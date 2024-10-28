#include <bits/stdc++.h>
using namespace std;

int main() {
    string filename = "tac.txt";
    ifstream file(filename);
    string line;
    int regCounter = 0;

    if (!file) {
        cout << "Error: Could not open the file." << endl;
        return 1;
    }

    cout << "Generated Machine Code:\n";
    while (getline(file, line)) {
        istringstream iss(line);
        string result, operand1, operand2, op;
        iss >> result >> op >> operand1 >> op >> operand2;

        string reg = "R" + to_string(regCounter++);

        cout << result << " = " << operand1 << " " << op << " " << operand2 << " -> ";
        cout << "MOV " << reg << ", " << operand1 << "\n";

        if (op == "+") cout << "ADD " << reg << ", " << operand2;
        if (op == "-") cout << "SUB " << reg << ", " << operand2;
        if (op == "*") cout << "MUL " << reg << ", " << operand2;
        if (op == "/") cout << "DIV " << reg << ", " << operand2;
        cout << "\n\n";
    }

    file.close();
    return 0;
}
