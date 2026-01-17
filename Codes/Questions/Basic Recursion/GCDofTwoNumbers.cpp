#include<iostream>
using namespace std;
//Find The GCD(HCF) of Two Numbers

int GCD(int a, int b){
    if(b==0)    return a;
    return GCD(b,a%b);     
}


int main(){
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b);

    return 0;
}