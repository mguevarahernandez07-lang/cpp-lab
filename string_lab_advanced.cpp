#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cctype>
#include <vector>
#include <sstream>
using namespace std;

// ---------- Task 1 ----------
void extractDomain() {
    string email;
    cout << "Enter your email: ";
    cin >> email;

    int pos = email.find('@');
    if (pos != string::npos) {
        string user = email.substr(0, pos);
        string domain = email.substr(pos + 1);
        cout << "Username: " << user << endl;
        cout << "Domain: " << domain << endl;
    } else {
        cout << "Invalid email format!" << endl;
    }
}

// ---------- Task 2 ----------
void replaceWord() {
    cin.ignore(); // clear input buffer
    string text;
    cout << "Enter a sentence: ";
    getline(cin, text);

    size_t pos = 0;
    while ((pos = text.find("Miramar")) != string::npos)
        text.replace(pos, 7, "San Diego Miramar College");

    cout << "Updated text: " << text << endl;
}

// ---------- Task 3 ----------
bool isPalindrome(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

void checkPalindrome() {
    cin.ignore();
    string str;
    cout << "Enter a phrase: ";
    getline(cin, str);

    if (isPalindrome(str))
        cout << "It’s a palindrome." << endl;
    else
        cout << "Not a palindrome." << endl;
}

// ---------- Task 4 ----------
void findLongestWord() {
    cin.ignore();
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    string word, longest;
    while (ss >> word) {
        if (word.length() > longest.length())
            longest = word;
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << longest.length() << endl;
}

// ---------- Task 5 ----------
void characterHistogram() {
    cin.ignore();
    string s;
    cout << "Enter text: ";
    getline(cin, s);

    transform(s.begin(), s.end(), s.begin(), ::toupper);

    map<char, int> freq;
    for (char c : s)
        if (isalpha(c))
            freq[c]++;

    for (auto &p : freq)
        cout << p.first << " -> " << p.second << endl;
}

// ---------- Task 6 ----------
void maskEmail() {
    string email;
    cout << "Enter your email: ";
    cin >> email;

    int pos = email.find('@');
    if (pos != string::npos && pos > 2) {
        for (int i = 1; i < pos - 1; ++i)
            email[i] = '*';
        cout << "Masked email: " << email << endl;
    } else {
        cout << "Invalid email format!" << endl;
    }
}

// ---------- MAIN ----------
int main() {
    int choice;
    do {
        cout << "\n===== STRING LAB MENU =====" << endl;
        cout << "1. Extract Domain from Email" << endl;
        cout << "2. Replace a Word" << endl;
        cout << "3. Palindrome Checker" << endl;
        cout << "4. Find Longest Word" << endl;
        cout << "5. Character Histogram" << endl;
        cout << "6. Mask Email Address" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose a task: ";
        cin >> choice;

        switch (choice) {
            case 1: extractDomain(); break;
            case 2: replaceWord(); break;
            case 3: checkPalindrome(); break;
            case 4: findLongestWord(); break;
            case 5: characterHistogram(); break;
            case 6: maskEmail(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl; break;
        }
    } while (choice != 0);

    return 0;
}
