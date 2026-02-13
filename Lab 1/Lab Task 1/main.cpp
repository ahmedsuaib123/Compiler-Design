#include <iostream>
#include <string>

using namespace std;

int main()
{
    string var;
    cout << "Enter variable name: ";
    cin >> var;

    string keywords[] = {"int", "float", "double", "char", "return", "if", "else"};

    if (isdigit(var.at(0))) {
        cout << "Invalid variable name";
        return 0;
    }

    for (int i = 0; i < 7; i++) {
        if (var == keywords[i]) {
            cout << "Invalid variable name";
            return 0;
        }
    }

    for (int i = 0; i < var.length(); i++) {
        char c = var.at(i);
        if (!(isalnum(c) || c == '_' || c == '$')) {
            cout << "Invalid variable name";
            return 0;
        }
    }

    cout << "Valid variable name";
    return 0;
}
