#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

void checkPalindrome() {
    string str;
    cout << "Enter a phrase: ";
    getline(cin, str);

    if (isPalindrome(str))
        cout << "It's a palindrome." << endl;
    else
        cout << "Not a palindrome." << endl;
}

int main() {
    checkPalindrome();
    return 0;
}
