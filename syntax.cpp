#include <bits/stdc++.h>
using namespace std;
void DDI(const string &code) {
    unordered_set<string> identifiers;
    stringstream ss(code);
    string line;
    int lineNum = 1;
    while (getline(ss, line)) {
        stringstream lineStream(line);
        string type, identifier;
        lineStream >> type >> identifier;
        if (type == "int" || type == "float" || type == "double" || type == "char") {
            identifier = identifier.substr(0, identifier.find(';'));
            if (!identifiers.insert(identifier).second) {
                cout << "Duplicate identifier: '" << identifier << "' at line " << lineNum << endl;
            }
        }
        lineNum++;
    }
}
void DUB(const string &code) {
    stack<int> braceStack;
    stringstream ss(code);
    string line;
    int lineNum = 1;
    while (getline(ss, line)) {
        for (char ch : line) {
            if (ch == '{') braceStack.push(lineNum);
            else if (ch == '}') {
                if (braceStack.empty()) {
                    cout << "Unmatched '}' at line " << lineNum << endl;
                    return;
                } else {
                    braceStack.pop();
                }
            }
        }
        lineNum++;
    }
    while (!braceStack.empty()) {
        cout << "Unmatched '{' at line " << braceStack.top() << endl;
        braceStack.pop();
    }
}
int main() {
    string sourceCode, line;
    cout << "Enter your code (end input with a single '.'): \n";
    while (getline(cin, line) && line != ".") sourceCode += line + "\n";
    DDI(sourceCode);
    DUB(sourceCode);

    return 0;
}
