#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char symbols[100];
    for (int i = 0; i < m; i++) cin >> symbols[i];

    int t;
    cin >> t;

    int transition[100][100][100];
    int count[100][100] = {0};

    for (int i = 0; i < t; i++) {
        int current, next;
        char ch;
        cin >> current >> ch >> next;

        int index = -1;
        for (int j = 0; j < m; j++) {
            if (symbols[j] == ch) {
                index = j;
                break;
            }
        }

        if (index != -1) {
            transition[current][index][count[current][index]++] = next;
        }
    }

    int start;
    cin >> start;

    int f;
    cin >> f;

    int finalStates[100];
    for (int i = 0; i < f; i++) cin >> finalStates[i];

    string input;
    cin >> input;

    int current[100], nextStates[100];
    int currSize = 1;
    current[0] = start;

    for (int i = 0; i < input.length(); i++) {
        int index = -1;

        for (int j = 0; j < m; j++) {
            if (symbols[j] == input[i]) {
                index = j;
                break;
            }
        }

        int nextSize = 0;

        for (int j = 0; j < currSize; j++) {
            int state = current[j];

            for (int k = 0; k < count[state][index]; k++) {
                nextStates[nextSize++] = transition[state][index][k];
            }
        }

        currSize = nextSize;

        for (int j = 0; j < currSize; j++) {
            current[j] = nextStates[j];
        }
    }

    bool accepted = false;

    for (int i = 0; i < currSize; i++) {
        for (int j = 0; j < f; j++) {
            if (current[i] == finalStates[j]) {
                accepted = true;
            }
        }
    }

    if (accepted) cout << "Accepted";
    else cout << "Rejected";

    return 0;
}
