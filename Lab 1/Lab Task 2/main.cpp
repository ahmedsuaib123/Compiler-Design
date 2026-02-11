#include <iostream>

using namespace std;

int main()
{
    int a[]={10,20,30,40,50};
    int sum=0;

    for(int i=0;i<5;i++){
        sum+=a[i];
    }

    cout<<"Average Value = "<<sum/5<<endl;

    return 0;
}
