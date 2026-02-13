#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;
    cout << "Number of students: ";
    cin >> n;

    ofstream fout("students.txt");

    for (int i = 1; i <= n; i++) {
        string name;
        int marks;
        cout << "Student " << i << " name: ";
        cin >> name;
        cout << "Student " << i << " marks: ";
        cin >> marks;

        fout << name << " " << marks << endl;
    }

    fout.close();

    ifstream fin("students.txt");
    string name;
    int marks;

    cout << "Data read from file: "<<endl;
    while (fin >> name >> marks) {
        cout << name << " " << marks << endl;
    }

    fin.close();
    return 0;
}
