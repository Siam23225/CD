#include <bits/stdc++.h>
using namespace std;
set<string> keywords =
{
    "int", "float", "if", "else", "while", "for", "return", "string", "char", "bool", "true", "false"
};
bool isKeyword( string str)
{
    return keywords.find(str) != keywords.end();
}
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>' || ch == '<');
}

bool isNumber( string str)
{
    for (char c : str)
    {
        if (!isdigit(c)) return false;
    }
    return true;
}
bool isIdentifier( string str)
{
    if (isdigit(str[0])) return false;
    for (char c : str)
    {
        if (!isalnum(c) && c != '_') return false;
    }
    return true;
}
void lexicalAnalysis( string sourceCode)
{
    int i = 0;
    int len = sourceCode.length();

    while (i < len)
    {
        if (isspace(sourceCode[i]))
        {
            i++;
            continue;
        }
        if (isalpha(sourceCode[i]) || sourceCode[i] == '_')
        {
            string token = "";
            while (i < len && (isalnum(sourceCode[i]) || sourceCode[i] == '_'))
            {
                token += sourceCode[i++];
            }
            if (isKeyword(token))
            {
                cout << "Keyword: " << token << endl;
            }
            else if (isIdentifier(token))
            {
                cout << "Identifier: " << token << endl;
            }
        }
        else if (isdigit(sourceCode[i]))
        {
            string token = "";
            while (i < len && isdigit(sourceCode[i]))
            {
                token += sourceCode[i++];
            }
            if (isNumber(token))
            {
                cout << "Number: " << token << endl;
            }
        }
        else if (isOperator(sourceCode[i]))
        {
            cout << "Operator: " << sourceCode[i] << endl;
            i++;
        }
        else  i++; }
}

int main()
{
    string sourceCode;
    cout << "Enter a C++ program (end with Ctrl+D or Ctrl+Z):\n";
    char c;
    while (cin.get(c))
    {
        sourceCode += c;
    }
    cout << "\nLexical Analysis:\n";
    lexicalAnalysis(sourceCode);
    return 0;
}
