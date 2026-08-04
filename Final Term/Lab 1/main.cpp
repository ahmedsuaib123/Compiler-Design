#include <iostream>

using namespace std;

int main()
{
    int n,m;
    char symbols[100];
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>symbols[i];
    }

    int transition[100][100];
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            transition[i][j]=-1;
        }
    }

    int t;
    cin>>t;

    for (int i = 0; i < t; i++) {
        int currentState, nextState;
        char inputChar;
        cin >> currentState >> inputChar >> nextState;

        int symbolIndex = -1;

        for (int j = 0; j < m; j++) {
            if (symbols[j] == inputChar) {
                symbolIndex = j;
                break;
            }
        }

        if (symbolIndex != -1) {
            transition[currentState][symbolIndex] = nextState;
        }
    }

    int startState;
    cin >> startState;

    int f;
    cin >> f;

    int finalStates[100];
    for (int i = 0; i < f; i++) {
        cin >> finalStates[i];
    }

    string inputString;
    cin >> inputString;

    int currentState = startState;
    bool valid = true;

    for (int i = 0; i < inputString.length(); i++) {
        int symbolIndex = -1;

        for (int j = 0; j < m; j++) {
            if (symbols[j] == inputString[i]) {
                symbolIndex = j;
                break;
            }
        }

        if (symbolIndex == -1 || transition[currentState][symbolIndex] == -1) {
            valid = false;
            break;
        }

        currentState = transition[currentState][symbolIndex];
    }

    bool isFinal = false;
    for (int i = 0; i < f; i++) {
        if (currentState == finalStates[i]) {
            isFinal = true;
            break;
        }
    }

    if (valid && isFinal) {
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }


    return 0;
}
