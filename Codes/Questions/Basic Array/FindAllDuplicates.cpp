#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> findDuplicates(vector<int>& nums){
    vector<int> result;
    int n = nums.size();
    for(int i = 0 ; i < n ; ++i){
        int num = abs(nums[i]);
        int index = num-1;
        if(nums[index] < 0){
            result.push_back(num);
        }
        else{
            nums[index] = -nums[index];
        }
    }
    return result;
}

// Helper function to print a vector.
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ",");
    }
    cout << "]" << endl;
}

// Main function for testing.
int main() {

    // Example 1
    vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    cout << "Input: [4,3,2,7,8,2,3,1]" << endl;
    vector<int> result1 = findDuplicates(nums1);
    cout << "Output: ";
    printVector(result1); // Expected: [2,3]
    cout << "--------------------" << endl;

    // Example 2
    vector<int> nums2 = {1, 1, 2};
    cout << "Input: [1,1,2]" << endl;
    vector<int> result2 = findDuplicates(nums2);
    cout << "Output: ";
    printVector(result2); // Expected: [1]
    cout << "--------------------" << endl;

    // Example 3
    vector<int> nums3 = {1};
    cout << "Input: [1]" << endl;
    vector<int> result3 = findDuplicates(nums3);
    cout << "Output: ";
    printVector(result3); // Expected: []
    cout << "--------------------" << endl;

    return 0;
}