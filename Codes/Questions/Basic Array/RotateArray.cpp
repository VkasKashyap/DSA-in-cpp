#include <iostream> 
#include <vector>   
#include <algorithm> 

using namespace std; 

void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]); 
        start++;                         
        end--;                           
    }
}


void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0 || k % n == 0) return;

    // Normalize k:
    // Ensure k is within the bounds [0, n-1] by taking modulo n.
    // This handles cases where k > n.
    k = k % n;

    // Three-reversal algorithm for right rotation:
    // 1. Reverse the first (n - k) elements. These are the elements that will move to the end.
    //    For example, if nums = [1,2,3,4,5,6,7] and k=3, n-k = 4. Reverse [1,2,3,4] -> [4,3,2,1,5,6,7]
    reverse(nums, 0, n - k - 1);

    // 2. Reverse the last k elements. These are the elements that will move to the front.
    //    Continuing the example: Reverse [5,6,7] -> [4,3,2,1,7,6,5]
    reverse(nums, n - k, n - 1);

    // 3. Reverse the entire array. This brings all elements into their final rotated positions.
    //    Continuing the example: Reverse [4,3,2,1,7,6,5] -> [5,6,7,1,2,3,4] (Correct rotation)
    reverse(nums, 0, n - 1);
}

int main() {

    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    cout << "Original nums1: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;
    rotate(nums1, k); // Rotate nums1 by k1 steps
    cout << "Rotated nums1 by " << k << ": ";
    for (int x : nums1) cout << x << " ";
    cout << "\n\n";
    // Expected Output: 5 6 7 1 2 3 4


    return 0; // Indicate successful program execution
}