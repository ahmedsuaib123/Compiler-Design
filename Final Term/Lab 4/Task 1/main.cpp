#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string symbols[10];
    for (int i = 0; i < m; i++) {
        cin >> symbols[i];
    }

    int trans[50][10];

    for (int i = 0; i < n * m; i++) {
        int from, to;
        string sym;
        cin >> from >> sym >> to;

        for (int j = 0; j < m; j++) {
            if (symbols[j] == sym) {
                trans[from][j] = to;
            }
        }
    }

    int start;
    cin >> start;

    int f;
    cin >> f;

    int finalStates[50] = {0};

    for (int i = 0; i < f; i++) {
        int x;
        cin >> x;
        finalStates[x] = 1;
    }

    int group[50];

    for (int i = 0; i < n; i++) {
        if (finalStates[i]) {
            group[i] = 1;
        } else {
            group[i] = 0;
        }
    }

    int changed = 1;

    while (changed) {
        changed = 0;

        int newGroup[50];
        int groupCount = 0;

        for (int i = 0; i < n; i++) {
            int found = -1;

            for (int j = 0; j < i; j++) {
                if (group[i] == group[j]) {
                    int same = 1;

                    for (int k = 0; k < m; k++) {
                        if (group[trans[i][k]] != group[trans[j][k]]) {
                            same = 0;
                            break;
                        }
                    }

                    if (same) {
                        found = newGroup[j];
                        break;
                    }
                }
            }

            if (found == -1) {
                newGroup[i] = groupCount++;
            } else {
                newGroup[i] = found;
            }
        }

        for (int i = 0; i < n; i++) {
            if (group[i] != newGroup[i]) {
                changed = 1;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            group[i] = newGroup[i];
        }
    }

    cout << "Equivalent Groups:" << endl;

    int printed[50] = {0};

    for (int i = 0; i < n; i++) {
        if (!printed[i]) {
            cout << "{";
            cout << i;
            printed[i] = 1;

            for (int j = i + 1; j < n; j++) {
                if (group[i] == group[j]) {
                    cout << "," << j;
                    printed[j] = 1;
                }
            }
            cout << "}" << endl;
        }
    }

    cout << "Start State = {";
    for (int i = 0; i < n; i++) {
        if (group[i] == group[start]) {
            cout << i << ",";
        }
    }
    cout << "\b}" << endl;

    cout << "Final States:" << endl;

    int printedGroup[50] = {0};

    for (int i = 0; i < n; i++) {
        if (finalStates[i] && !printedGroup[group[i]]) {
            cout << "{";

            for (int j = 0; j < n; j++) {
                if (group[j] == group[i]) {
                    cout << j << ",";
                }
            }

            cout << "\b}" << endl;
            printedGroup[group[i]] = 1;
        }
    }

    cout << "Minimized DFA Transition Table:" << endl;

    for (int i = 0; i < n; i++) {
        int isRep = 1;

        for (int j = 0; j < i; j++) {
            if (group[i] == group[j]) {
                isRep = 0;
                break;
            }
        }

        if (!isRep) {
            continue;
        }

        for (int k = 0; k < m; k++) {
            cout << "{";

            for (int j = 0; j < n; j++) {
                if (group[j] == group[i]) {
                    cout << j << ",";
                }
            }

            cout << "\b} --" << symbols[k] << "--> {";

            int next = trans[i][k];

            for (int j = 0; j < n; j++) {
                if (group[j] == group[next]) {
                    cout << j << ",";
                }
            }

            cout << "\b}" << endl;
        }
    }

    return 0;
}
