#include <iostream>

using namespace std;

int main()
{
    string line;
    cin>>line;

    if(line.substr(0,2)=="//"){
        cout<<"This is a single line comment."<<endl;
    } else if(line.substr(0,2)=="/*" && line.substr(line.length()-2,2)=="*/"){
        cout<<"This is a multi line comment."<<endl;
    } else{
        cout<<"This is not a comment."<<endl;
    }

    return 0;
}
