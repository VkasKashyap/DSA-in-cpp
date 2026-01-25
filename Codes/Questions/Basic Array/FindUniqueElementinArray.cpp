#include<iostream>
#include<vector>
using namespace std;

// Finds the single element that appears only once in an array.
int findUnique(vector<int>& nums){
    // Initialize the result variable.
    int ans = 0;
    int n = nums.size();
    
    // XOR all elements together.
    for(int i = 0; i < n ; i++){
        // The XOR operation cancels out duplicate numbers.
        ans = ans ^ nums[i];
    }
    return ans;
}

int main(){
    // Create a sample vector where every element has a pair except '4'.
    vector<int> nums = {1,2,3,4,1,2,3};
    
    // Call the function and print the unique element.
    cout << "unique element in the array is " << findUnique(nums);

    return 0;
}