#include <iostream>
#include <string>

using namespace std;

string str;
int i = 0;
bool isValid = true;
void B() {
    if (i < str.size() && str[i] == 'b') {
        i++;
        isValid = true;
    } else {
        isValid = false;
    }
}
void A() {
    if (i < str.size() && str[i] == 'a') {
        i++;
        isValid = true;
        A();
    } else {
        return;
    }
}
void S() {
    if (i < str.size() && str[i] == 'b') {
        i++;  // Match a single 'b'
        isValid = true;
    } else {
        A();  // Try to match A part
        if (isValid) {
            B();
        }
    }
}
int main() {
    cout << "Enter a string to validate: ";
    cin >> str;

    i = 0;
    isValid = true;
    S();
    if (isValid && i == str.size()) {
        cout << "String is valid according to the CFG." << endl;
    } else {
        cout << "String is not valid according to the CFG." << endl;
    }
    return 0;
}
