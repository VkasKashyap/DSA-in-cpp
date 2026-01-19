// maxium subarray sum

#include<iostream>
#include<vector>
using namespace std;

int Kadanes(vector<int>& nums){
    int sum = 0, maxi = INT16_MIN;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];

        if(sum > maxi){
            maxi = sum;
        }

        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
}

int main(){
    vector<int> nums = {1,2,3,-5,-6,4,5,6,7,8,9};
    cout<<"maximum subarray sum is : "<<Kadanes(nums);

    return 0;
}