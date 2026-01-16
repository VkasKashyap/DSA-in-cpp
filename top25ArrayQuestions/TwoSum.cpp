#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        int rem = target - nums[i];
        if(mp.count(rem))   return {mp[rem], i};
        mp[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int target = 5;
    vector<int> ans = twoSum(nums, target);
    for(int num : ans){
        cout<<num<<" ";
    }

    return 0;
}