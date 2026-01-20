#include <iostream>
#include <vector> 
using namespace std;

bool check(vector<int>& nums) {
    int count = 0; 
    int n = nums.size(); 
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] > nums[i]) {
            count++; 
        }
    }

    if (nums[n - 1] > nums[0]) {
        count++; 
    }
    return count <= 1;
}


int main() {

    // Test Case 1: Sorted and rotated (e.g., [3,4,5,1,2])
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Array: ";
    for (int x : nums1) cout << x << " ";
    cout << " -> Is Sorted and Rotated? " << (check(nums1) ? "Yes" : "No") << endl; // Expected: Yes

    return 0; // Indicate successful program execution
}