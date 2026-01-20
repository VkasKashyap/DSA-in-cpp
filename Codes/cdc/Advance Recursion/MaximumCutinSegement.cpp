
#include<iostream>
using namespace std;

int maxCut(int n, int x, int y, int z){
    if(n==0)    return 0;
    if(n<0) return -1;
    int a = maxCut(n-x,x,y,z);
    int b = maxCut(n-y,x,y,z);
    int c = maxCut(n-z,x,y,z);

    return max(max(a,b) , max(a,c)) + 1;
}
int main(){
    int n;
    cout<<"Enter the length of the segment : ";
    cin>>n;
    cout<<"maximum cuts in the segements are : "<<maxCut(n,2,1,1);

    return 0;
}