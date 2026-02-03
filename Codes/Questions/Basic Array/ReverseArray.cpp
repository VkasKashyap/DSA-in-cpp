#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to reverse a vector in-place
void reverse(vector<int>& nums) {
    // Pointers for the start and end of the vector
    int start = 0;
    int end = nums.size() - 1;

    // Loop until the pointers meet in the middle
    while (start < end) {
        // Swap the start and end elements
        swap(nums[start], nums[end]);
        // Move pointers towards the center
        start++;
        end--;
    }
}

// Function to print the elements of a vector
void printArray(const vector<int>& nums) {
    // Loop through each number in the vector
    for (int num : nums) {
        // Print the number and a space
        cout << num << " ";
    }
}

// Main program entry point
int main() {
    // Create and initialize a vector
    vector<int> nums = {10, 15, 20, -100};

    // Call the function to reverse the vector
    reverse(nums);

    // Print a message
    cout << "Reverse of the given array is : ";
    // Call the function to print the reversed vector
    printArray(nums);

    // Indicate successful execution
    return 0;
}