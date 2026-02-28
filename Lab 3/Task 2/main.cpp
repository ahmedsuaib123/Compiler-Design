#include <iostream>

using namespace std;

int main()
{
    string line;
    getline(cin,line);

    bool isOperator=true;
    bool valid=true;

    for(int i=0;i<line.length();i++){
       char ch=line[i];

       if(ch==' '){
            continue;
       }

       if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')){
           if(!isOperator){
                valid=false;
                break;
           }
           isOperator=false;
       } else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
           if(isOperator){
                valid=false;
                break;
           }
           isOperator=true;
       } else{
           valid=false;
           break;
       }
    }

    if(isOperator){
        valid=false;
    }

    if(valid){
        cout<<"Valid"<<endl;
    } else{
        cout<<"Invalid"<<endl;
    }

    return 0;
}
