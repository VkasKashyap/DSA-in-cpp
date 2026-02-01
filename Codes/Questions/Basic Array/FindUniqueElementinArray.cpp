#include<iostream>
#include<vector>
using namespace std;
int findUnique(vector<int>& nums){
    int ans = 0;
    int n = nums.size();
    for(int i = 0; i < n ; i++){
        ans = ans ^ nums[i];
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4,1,2,3};
    cout << "unique element in the array is " << findUnique(nums);

    return 0;
}