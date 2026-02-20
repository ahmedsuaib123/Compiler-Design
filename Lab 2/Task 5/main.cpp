#include <iostream>

using namespace std;

int main()
{
    string line;
    int count = 0;

    getline(cin, line);

    for (int i = 0; i < line.length(); i++)
    {
        char ch = line[i];

        if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == ',' || ch == ';')
        {
            count++;
            cout << "delimiter" << count << " : " << ch << endl;
        }
    }

    cout << "number of delimiters = " << count << endl;

}
