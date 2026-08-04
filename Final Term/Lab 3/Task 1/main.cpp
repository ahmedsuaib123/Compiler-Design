#include <iostream>

using namespace std;

int trans[100][3][100];
int transCount[100][3];

int eps[100][100];
int epsCount[100];

int dfa[100][3][100];
int dfaCount[100][3];

int states[100][100];
int stateSize[100];

int totalDFA = 0;

char symbols[10];
int m;

bool exists(int arr[], int size, int x) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == x) {
            return true;
        }
    }
    return false;
}

void epsilonClosure(int input[], int size, int output[], int &outSize) {
    outSize = 0;

    for(int i = 0; i < size; i++) {
        output[outSize++] = input[i];
    }

    for(int i = 0; i < outSize; i++) {
        int s = output[i];

        for(int j = 0; j < epsCount[s]; j++) {
            int v = eps[s][j];

            if(!exists(output, outSize, v)) {
                output[outSize++] = v;
            }
        }
    }
}

bool sameSet(int a[], int as, int b[], int bs) {
    if(as != bs) {
        return false;
    }

    for(int i = 0; i < as; i++) {
        if(!exists(b, bs, a[i])) {
            return false;
        }
    }
    return true;
}

int findState(int arr[], int size) {
    for(int i = 0; i < totalDFA; i++) {
        if(sameSet(states[i], stateSize[i], arr, size)) {
            return i;
        }
    }
    return -1;
}

void printSet(int arr[], int size) {
    cout << "{";

    for(int i = 0; i < size; i++) {
        cout << arr[i];
        if(i != size - 1) {
            cout << ",";
        }
    }

    cout << "}";
}

int main() {
    int n;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> symbols[i];
    }

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int u, v;
        char c;
        cin >> u >> c >> v;

        if(c == 'e') {
            eps[u][epsCount[u]++] = v;
        } else {
            int idx = (c == symbols[0]) ? 0 : 1;
            trans[u][idx][transCount[u][idx]++] = v;
        }
    }

    int start;
    cin >> start;

    int f;
    cin >> f;

    int final[100];
    for(int i = 0; i < f; i++) {
        cin >> final[i];
    }


    int startArr[100], startSize = 1;
    startArr[0] = start;

    int closure[100], closureSize;
    epsilonClosure(startArr, startSize, closure, closureSize);

    for(int i = 0; i < closureSize; i++) {
        states[0][i] = closure[i];
    }

    stateSize[0] = closureSize;
    totalDFA = 1;

    for(int i = 0; i < totalDFA; i++) {
        for(int j = 0; j < m; j++) {

            int temp[100], tempSize = 0;

            for(int k = 0; k < stateSize[i]; k++) {
                int s = states[i][k];

                for(int x = 0; x < transCount[s][j]; x++) {
                    int v = trans[s][j][x];

                    if(!exists(temp, tempSize, v)) {
                        temp[tempSize++] = v;
                    }
                }
            }

            int newSet[100], newSize;
            epsilonClosure(temp, tempSize, newSet, newSize);

            int idx = findState(newSet, newSize);

            if(idx == -1) {
                idx = totalDFA;

                for(int x = 0; x < newSize; x++) {
                    states[totalDFA][x] = newSet[x];
                }

                stateSize[totalDFA] = newSize;
                totalDFA++;
            }

            dfaCount[i][j] = stateSize[idx];

            for(int x = 0; x < stateSize[idx]; x++) {
                dfa[i][j][x] = states[idx][x];
            }
        }
    }

    cout << "Start State = ";
    printSet(states[0], stateSize[0]);
    cout << endl;

    cout << endl;
    cout << "Final States:" << endl;

    for(int i = 0; i < totalDFA; i++) {
        bool isFinal = false;

        for(int j = 0; j < stateSize[i]; j++) {
            for(int k = 0; k < f; k++) {
                if(states[i][j] == final[k]) {
                    isFinal = true;
                }
            }
        }

        if(isFinal) {
            printSet(states[i], stateSize[i]);
            cout << endl;
        }
    }

    cout << endl;
    cout << "Transition Table:" << endl;

    for(int i = 0; i < totalDFA; i++) {
        for(int j = 0; j < m; j++) {

            printSet(states[i], stateSize[i]);

            cout << " --" << symbols[j] << "--> ";

            printSet(dfa[i][j], dfaCount[i][j]);

            cout << endl;
        }
    }

    int q;
    cin >> q;

    while(q--) {
        string s;
        cin >> s;

        int current = 0;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            int idx = (c == symbols[0]) ? 0 : 1;

            int nextState = -1;

            for(int j = 0; j < totalDFA; j++) {
                if(sameSet(states[j], stateSize[j],
                           dfa[current][idx], dfaCount[current][idx])) {
                    nextState = j;
                    break;
                }
            }

            current = nextState;
        }

        bool accepted = false;

        for(int i = 0; i < stateSize[current]; i++) {
            for(int j = 0; j < f; j++) {
                if(states[current][i] == final[j]) {
                    accepted = true;
                }
            }
        }

        cout << endl;
        cout << "String: " << s << endl;

        if(accepted) {
            cout << "Accepted" << endl;
        } else {
            cout << "Rejected" << endl;
        }
    }

    return 0;
}
