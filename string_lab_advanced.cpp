#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// === Task 1: Extract Domain from Email ===
void extractDomain() {
    string email;
    cout << "Enter email address: ";
    getline(cin, email);

    int pos = email.find('@');
    if (pos != string::npos) {
        string user = email.substr(0, pos);
        string domain = email.substr(pos + 1);
        cout << "Username: " << user << endl;
        cout << "Domain: " << domain << endl;
    } else {
        cout << "Invalid email address." << endl;
    }
}

// === Task 2: Replace a Word ===
void replaceWord() {
    string text;
    cout << "Enter a sentence: ";
    getline(cin, text);

    size_t pos;
    while ((pos = text.find("Miramar")) != string::npos) {
        text.replace(pos, 7, "San Diego Miramar College");
    }

    cout << "Updated sentence: " << text << endl;
}

// === Task 3: Palindrome Checker ===
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

// === Task 4: Find the Longest Word ===
void longestWord() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string word = "", longest = "";
    for (int i = 0; i <= sentence.length(); i++) {
        if (i == sentence.length() || sentence[i] == ' ') {
            if (word.length() > longest.length()) {
                longest = word;
            }
            word = "";
        } else {
            word += sentence[i];
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << longest.length() << endl;
}

// === Task 5: Character Histogram ===
void charHistogram() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    transform(text.begin(), text.end(), text.begin(), ::toupper);

    int freq[26] = {0};
    for (char c : text) {
        if (isalpha(c)) {
            freq[c - 'A']++;
        }
    }

    cout << "Letter counts:\n";
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0)
            cout << char('A' + i) << " -> " << freq[i] << endl;
    }
}

// === Task 6: Mask Email ===
void maskEmail() {
    string email;
    cout << "Enter email address: ";
    getline(cin, email);

    int pos = email.find('@');
    if (pos == string::npos || pos <= 1) {
        cout << "Invalid email address." << endl;
        return;
    }

    for (int i = 1; i < pos - 1; i++) {
        email[i] = '*';
    }

    cout << "Masked email: " << email << endl;
}

// === MAIN MENU ===
int main() {
    int choice;
    do {
        cout << "\n==== STRING LAB MENU ====\n";
        cout << "1. Extract Domain from Email\n";
        cout << "2. Replace a Word\n";
        cout << "3. Palindrome Checker\n";
        cout << "4. Find the Longest Word\n";
        cout << "5. Character Histogram\n";
        cout << "6. Mask Email Address\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

        if (choice == 1) extractDomain();
        else if (choice == 2) replaceWord();
        else if (choice == 3) checkPalindrome();
        else if (choice == 4) longestWord();
        else if (choice == 5) charHistogram();
        else if (choice == 6) maskEmail();
        else if (choice == 0) cout << "Goodbye!" << endl;
        else cout << "Invalid choice." << endl;

    } while (choice != 0);

    return 0;
}

