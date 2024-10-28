#include <bits/stdc++.h>
using namespace std;
void checkCommentsInLine(const string& line, int lineNum)
{
    int singleLineCommentPos = line.find("//");
    if (singleLineCommentPos != -1)
    {
        cout << "Line " << lineNum << ": Single-line comment found: \"" << line.substr(singleLineCommentPos) << "\"" << endl;
    }
    int multiLineStart = line.find("/*");
    int multiLineEnd = line.find("*/");
    if (multiLineStart != -1)
    {
        if (multiLineEnd != -1 && multiLineEnd > multiLineStart)
        {
            cout << "Line " << lineNum << ": Multi-line comment found: \"" << line.substr(multiLineStart, multiLineEnd - multiLineStart + 2) << "\"" << endl;
        }
        else
        {
            cout << "Line " << lineNum << ": Multi-line comment started but not closed." << endl;
        }
    }
}

int main()
{
    string line;
    vector<string> codeLines;

    cout << "Enter your C++ code: " << endl;
    while (getline(cin, line))
    {
        codeLines.push_back(line);
    }
    for (int i = 0; i < codeLines.size(); ++i)
    {
        checkCommentsInLine(codeLines[i], i + 1);
    }
    return 0;
}
