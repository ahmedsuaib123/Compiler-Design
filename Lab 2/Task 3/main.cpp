#include <iostream>

using namespace std;

int main() {
    string token;
    cin >> token;

    string keywords[] = {"int","float","double","char","if","else","while","return"};

    for (int i = 0; i < 8; i++) {
        if (token == keywords[i]) {
            cout << "Keyword";
            return 0;
        }
    }

    if (!(isalpha(token[0]) || token[0] == '_')) {
        cout << "Invalid";
        return 0;
    }

    for (int i = 1; i < token.length(); i++) {
        if (!(isalnum(token[i]) || token[i] == '_')) {
            cout << "Invalid";
            return 0;
        }
    }

    cout << "Identifier";
    return 0;
}
