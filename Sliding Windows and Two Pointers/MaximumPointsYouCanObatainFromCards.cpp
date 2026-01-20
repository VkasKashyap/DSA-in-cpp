#include<iostream>
#include<vector>
using namespace std;

int maxPoint(vector<int>& nums, int k){
    int lSum = 0;
    int rSum = 0;
    for(int i=0 ; i<k ; i++){
        lSum += nums[i];
    }
    int maxSum = lSum;
    int rIndex = nums.size()-1;
    for(int i=k ; i>=0 ; i--){
        lSum -= nums[i];
        rSum += nums[rIndex];
        rIndex--;
        maxSum = max(maxSum, lSum+rSum);
    }
    return maxSum;
}

int main(){
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout<<"Maximum Points you can obtain from the cards is : "<<maxPoint(cardPoints,k);

    return 0;
}