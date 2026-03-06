#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLetter(char c){
    return ((c>='A' && c<='Z') || (c>='a' && c<='z'));
}

bool isDigit(char c){
    return ((c>='0' && c<='9'));
}

bool isIdentifier(string s){
    if(s.length()==0){
        return false;
    }

    if(!(isLetter(s[0]) || s[0]=='_')){
        return false;
    }

    for(int i=1;i<(int)s.length();i++){
        if(!(isLetter(s[i]) || isDigit(s[i]) || s[i]=='_')){
            return false;
        }
    }

    return true;
}

bool isVariable(string type,string id,char last){
    if((type=="int" || type=="float" || type=="double" || type=="char") && last==';' && isIdentifier(id)){
        return true;
    }
    return false;
}

bool isFunction(string type,string fname){
    if((type=="int" || type=="float" || type=="double" || type=="char" || type=="void") && isIdentifier(fname)){
        return true;
    }
    return false;
}

string removeSpaces(string s){
    string temp="";

    for(int i=0;i<(int)s.length();i++){
        if(s[i]!=' '){
            temp=temp+s[i];
        }
    }

    return temp;
}

int main()
{
    ofstream fout("input.txt");

    int n;
    cout<<"How many lines: ";
    cin>>n;
    cin.ignore();

    string line;

    for(int i=0;i<n;i++){
        cout<<"Enter line "<<i+1<<": ";
        getline(cin,line);
        fout<<line<<endl;
    }

    fout.close();

    ifstream fin("input.txt");
    ofstream report("report.txt");
    ofstream valid("valid_code.txt");


    int total=0;
    int varCount=0;
    int funcCount=0;
    int invalidCount=0;

    while(getline(fin,line)){
        total++;

        string originalLine=line;
        string type,name,rest;

        int i=0;

        while(i<(int)line.length() && line[i]==' '){
            i++;
        }

        while(i<(int)line.length() && isLetter(line[i])){
            type=type+line[i];
            i++;
        }

        while(i<(int)line.length() && line[i]==' '){
            i++;
        }

        while(i<(int)line.length()){
            rest=rest+line[i];
            i++;
        }

        rest=removeSpaces(rest);

        if(type==""){
            report<<"Line "<<total<<": Invalid"<<endl;
            invalidCount++;
            continue;
        }

        if(rest.length()>0 && rest.find('(')==-1 && rest[rest.length()-1]==';'){
            name=rest.substr(0,rest.length()-1);

            if(isVariable(type,name,rest[rest.length()-1])){
                report<<"Line "<<total<<": Variable Declaration"<<endl;
                valid<<originalLine<<endl;
                varCount++;
            } else{
                report<<"Line "<<total<<": Invalid"<<endl;
                invalidCount++;
            }
        } else if(rest.find('(')!=-1){
            int p=rest.find('(');
            name=rest.substr(0,p);

            if(rest.substr(p)=="();"){
                if(isFunction(type,name)){
                    report<<"Line "<<total<<": Function Declaration"<<endl;
                    valid<<originalLine<<endl;
                    funcCount++;
                } else{
                    report<<"Line "<<total<<": Invalid"<<endl;
                    invalidCount++;
                }
            } else{
                report<<"Line "<<total<<": Invalid"<<endl;
                invalidCount++;
            }
        } else{
            report<<"Line "<<total<<": Invalid"<<endl;
            invalidCount++;
        }
    }

    report<<"Summary:"<<endl;
    report<<"Total lines = "<<total<<endl;
    report<<"Variable Declarations = "<<varCount<<endl;
    report<<"Function Declarations = "<<funcCount<<endl;
    report<<"Invalid = "<<invalidCount<<endl;

    fin.close();
    report.close();
    valid.close();

    return 0;
}
