#include <bits/stdc++.h>
using namespace std;
struct Symbol
{
    string name, idType, dataType, scope;
};
vector<Symbol> symbolTable;
void insert(string name, string idType, string dataType, string scope)
{
    symbolTable.push_back({name, idType, dataType, scope});
}
void display()
{
    cout << "Symbol Table:" << endl;
    cout << "Name\tType\tDataType\tScope\t" << endl;
    for (auto sym : symbolTable)
    {
        cout << sym.name << "\t" << sym.idType << "\t" << sym.dataType
             << "\t\t" << sym.scope << "\t" <<endl;
    }
}
void parseCode(string code)
{
    istringstream codeStream(code);
    string line;
    string scope = "global";
    regex identifierPattern("(int|float|double|char|void)\\s+([a-zA-Z_][a-zA-Z0-9_]*)");

    while (getline(codeStream, line))
    {
        smatch match;

        if (regex_search(line, match, identifierPattern))
        {
            string dataType = match[1];
            string name = match[2];

            if (line.find('(') != string::npos && line.find(')') != string::npos)
            {
                insert(name, "func", dataType, scope);
                scope = name;
            }
            else
            {
                insert(name, "var", dataType, scope);
            }
        }

        if (line.find('}') != string::npos)
        {
            scope = "global";
        }
    }
}
int main()
{
    string code;
    cout << "Enter a C++ program (end with Ctrl+D or Ctrl+Z): ";
    string line;
    while (getline(cin, line))
    {
        code += line + "\n";
    }
    parseCode(code);
    display();
    return 0;
}
