#include <iostream>

using namespace std;

int main()
{
    string token;
    cin >> token;

    int start = 0;
    int dotCount = 0;

    if (token[0] == '+' || token[0] == '-')
    {
        start = 1;
    }

    if (start == token.length())
    {
        cout << "Invalid number";
        return 0;
    }

    for (int i = start; i < token.length(); i++)
    {
        if (isdigit(token[i]))
        {
            continue;
        } else if (token[i] == '.')
        {
            dotCount++;
        } else
        {
            cout << "Invalid number";
            return 0;
        }
    }

    if (dotCount == 0)
    {
        cout << "Integer literal";
    } else if (dotCount == 1)
    {
        int pos = token.find('.');

        if (pos > start && pos < token.length() - 1)
        {
            cout << "Floating literal";
        }
        else
        {
            cout << "Invalid number";
        }
    } else
    {
        cout << "Invalid number";
    }

    return 0;
}
