// Include headers for input/output, vector, and integer limits
#include <iostream>
#include <vector>
#include <climits>

// Use the standard C++ namespace      
using namespace std;

// Function to find the maximum value in a vector
int getMax(vector<int>& nums) {
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > maxi) {
            maxi = nums[i];
        }
    }
    return maxi;
}

// Function to find the minimum value in a vector
int getMin(vector<int>& nums) {
    // Initialize mini to the largest possible integer value (FIXED)
    int mini = INT_MAX;
    // Loop through each element in the vector
    for (int i = 0; i < nums.size(); i++) {
        // If the current element is smaller than the current min...
        if (nums[i] < mini) {
            // ...update the min
            mini = nums[i];
        }
    }
    // Return the final minimum value
    return mini;
}

// Main function where execution begins
int main() {
    // Create a sample vector of integers
    vector<int> nums = {45, 12, -50, 100, 3};

    // Call getMax and print the result
    cout << "maximum value in array is : " << getMax(nums) << endl;
    // Call getMin and print the result
    cout << "minimum value in array is : " << getMin(nums);

    // Indicate successful program termination
    return 0;
}