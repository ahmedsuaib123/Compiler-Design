#include <iostream>

using namespace std;

int main()
{
    string line;
    int count=0;

    cin>>line;

    for(int i=0;i<line.length();i++){
        char ch=line[i];

        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='%'||ch=='/'||ch=='<'||ch=='>'||ch=='!'||ch=='&'||ch=='|'){
            count++;
            cout<<"operator"<<count<<" : "<<ch<<endl;
        }
    }

    cout<<"number of operators = "<<count<<endl;

    return 0;
}
