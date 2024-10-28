#include <bits/stdc++.h>
using namespace std;
void isComment(string line)
{
    for(int i=0;i<line.size();i++)
    {
        if(line[i] == '/' && (line[i+1] == '/' || line[i+1] == '*'))
        {
            cout<<"It's a comment"<<endl;
            break;
        }
        else{
            cout<<"It's not a comment"<<endl;
            break;
        }
    }
}
int main()
{
	string line ;
    cout<<"Enter your string: ";
    getline(cin,line);
	isComment(line);
    return 0;
}

