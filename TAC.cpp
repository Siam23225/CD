#include <bits/stdc++.h>
using namespace std;
struct TAC {
    string result;
    string op;
    string arg1;
    string arg2;
};
string newTemp(int &tempCount) {
    return "t" + to_string(tempCount++);
}
int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
vector<TAC> generateTAC(const string &expression) {
    vector<TAC> tacList;
    int tempCount = 1;
    stack<string> operands;
    stack<char> operators;
    for (size_t i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        if (isspace(ch)) continue;
        if (isalnum(ch)) {
            string operand(1, ch);
            operands.push(operand);
        } else if (isOperator(ch)) {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(ch)) {
                string arg2 = operands.top(); operands.pop();
                string arg1 = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                string result = newTemp(tempCount);
                tacList.push_back({result, string(1, op), arg1, arg2});
                operands.push(result);
            }
            operators.push(ch);
        }
    }
    while (!operators.empty()) {
        string arg2 = operands.top(); operands.pop();
        string arg1 = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        string result = newTemp(tempCount);
        tacList.push_back({result, string(1, op), arg1, arg2});
        operands.push(result);
    }
    if (!operands.empty()) {
        tacList.push_back({"w", "=", operands.top(), ""});
    }

    return tacList;
}
void printTAC(const vector<TAC> &tacList) {
    cout << "Generated Three Address Code (TAC):" << endl;
    for (const auto &tac : tacList) {
        if (tac.op == "=")
            cout << tac.result << " = " << tac.arg1 << endl;
        else
            cout << tac.result << " = " << tac.arg1 << " " << tac.op << " " << tac.arg2 << endl;
    }
    cout << endl;
}
void printMachineCode(const vector<string> &machineCode) {
    cout << "Generated Machine Code:" << endl;
    for (const auto &code : machineCode) {
        cout << code << endl;
    }
}
int main() {
    string expression;
    cout << "Enter an arithmetic expression (e.g., w = a - b * c / d + e - f): ";
    getline(cin, expression);
    vector<TAC> tacList = generateTAC(expression);
    printTAC(tacList);
    return 0;
}
