#include <iostream>
#include <stack>
#include <string>
using namespace std;

void checkBrackets(const string& input) {
    stack<pair<char, size_t>> bracketStack; 
    string validBrackets = "[]{}()";  

    for (size_t i = 0; i < input.size(); ++i) {
        char ch = input[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            bracketStack.push({ ch, i });
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (bracketStack.empty()) {
                cout << "Error: closing bracket '" << ch << "' in position " << i << "does not have a corresponding opening.\n";
                cout << "Line before the error: " << input.substr(0, i + 1) << endl;
                return;
            }

            char topBracket = bracketStack.top().first;
            size_t topPosition = bracketStack.top().second;

            if ((topBracket == '(' && ch == ')') ||
                (topBracket == '{' && ch == '}') ||
                (topBracket == '[' && ch == ']')) {
                bracketStack.pop(); 
            }
            else {
                cout << "Error: Parentheses mismatch. Opening '" << topBracket << "' in position " << topPosition
                    << " does not match the closing '" << ch << "' in position " << i << ".\n";
                cout << "Line before the error: " << input.substr(0, i + 1) << endl;
                return;
            }
        }
    }

    if (!bracketStack.empty()) {
        char topBracket = bracketStack.top().first;
        size_t topPosition = bracketStack.top().second;
        cout << "Error: opening bracket '" << topBracket << "' in position " << topPosition << " does not have a corresponding closing.\n";
        cout << "Line before the error: " << input.substr(0, topPosition + 1) << endl;
    }
    else {
        cout << "The line is correct: all brackets are placed correctly.\n";
    }
}

int main() {
    string input;

    cout << "Enter a string (ends with ';'):\n";
    getline(cin, input, ';');

    checkBrackets(input);
}
