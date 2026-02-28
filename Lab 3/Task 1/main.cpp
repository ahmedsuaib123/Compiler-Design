#include <iostream>

using namespace std;

bool checkExpression2(string s){

    if(s.length()!=3){
        return false;
    }

    if(((s[0]>='A' && s[0]<='Z') || (s[0]>='a' && s[0]<='z')) && s[1]=='+' && s[2]=='+' ){
        return true;
    }

    if(s[0]=='+' && s[1]=='+' && ((s[2]>='A' && s[2]<='Z') || (s[2]>='a' && s[2]<='z'))  ){
        return true;
    }

    if(((s[0]>='A' && s[0]<='Z') || (s[0]>='a' && s[0]<='z')) && s[1]=='-' && s[2]=='-' ){
        return true;
    }

    if(s[0]=='-' && s[1]=='-' && ((s[2]>='A' && s[2]<='Z') || (s[2]>='a' && s[2]<='z'))  ){
        return true;
    }

    return false;
}

int main()
{
    string s;
    cin>>s;

    if(checkExpression2(s)){
        cout<<"Valid"<<endl;
    } else{
        cout<<"Invalid"<<endl;
    }
    return 0;
}
