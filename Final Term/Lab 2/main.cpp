#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char symbols[100];
    for (int i = 0; i < m; i++) {
        cin >> symbols[i];
    }

    int transition[100][100];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            transition[i][j] = -1;
        }
    }

    int t;
    cin >> t;

    bool validDFA = true;
    string reason = "";

    for (int i = 0; i < t; i++) {
        int currentState, nextState;
        char inputChar;
        cin >> currentState >> inputChar >> nextState;

        if (currentState < 0 || currentState >= n || nextState < 0 || nextState >= n) {
            if (validDFA) {
                validDFA = false;
                reason = "State out of range";
            }
        }


        int symbolIndex = -1;
        for (int j = 0; j < m; j++) {
            if (symbols[j] == inputChar) {
                symbolIndex = j;
                break;
            }
        }

        if (symbolIndex == -1) {
            if (validDFA) {
                validDFA = false;
                reason = "Transition symbol not in alphabet";
            }
        }

        if (symbolIndex != -1) {
            if (transition[currentState][symbolIndex] != -1) {
                if (validDFA) {
                    validDFA = false;
                    reason = "Duplicate transition";
                }
            } else {
                transition[currentState][symbolIndex] = nextState;
            }
        }
    }

    int startState;
    cin >> startState;

    if (startState < 0 || startState >= n) {
        if (validDFA) {
            validDFA = false;
            reason = "Invalid start state";
        }
    }

    int f;
    cin >> f;

    int finalStates[100];
    for (int i = 0; i < f; i++) {
        cin >> finalStates[i];

        if (finalStates[i] < 0 || finalStates[i] >= n) {
            if (validDFA) {
                validDFA = false;
                reason = "Invalid final state";
            }
        }
    }

    int q;
    cin >> q;

    string testStrings[100];
    for (int i = 0; i < q; i++) {
        cin >> testStrings[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (transition[i][j] == -1) {
                if (validDFA) {
                    validDFA = false;
                    reason = "Missing transition";
                }
            }
        }
    }

    if (!validDFA) {
        cout << "Invalid DFA" << endl;
        cout << reason << endl;
        return 0;
    }

    cout << "Valid DFA" << endl;
    cout << endl;

    for (int i = 0; i < q; i++) {
        string str = testStrings[i];
        int currentState = startState;
        bool rejected = false;

        cout << "String: " << str << endl;
        cout << "Path: " << currentState;

        for (int j = 0; j < str.length(); j++) {
            int symbolIndex = -1;

            for (int k = 0; k < m; k++) {
                if (symbols[k] == str[j]) {
                    symbolIndex = k;
                    break;
                }
            }

            if (symbolIndex == -1 || transition[currentState][symbolIndex] == -1) {
                rejected = true;
                break;
            }

            currentState = transition[currentState][symbolIndex];
            cout << " -> " << currentState;
        }

        cout << endl;

        bool isFinal = false;
        for (int j = 0; j < f; j++) {
            if (currentState == finalStates[j]) {
                isFinal = true;
                break;
            }
        }

        if (!rejected && isFinal) {
            cout << "Accepted" << endl;
        } else {
            cout << "Rejected" << endl;
        }

        cout << endl;
    }

    return 0;
}
