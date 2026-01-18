#include<iostream>
#include<vector>
using namespace std;
int BS(vector<int>& nums , int key , int start , int end){
    // Loop until the search space is exhausted.
    while(start <= end){
        // Calculate mid-point to prevent integer overflow.
        int mid = start + (end - start)/2;
 
        // Key is found.
        if(nums[mid] == key){
            return mid;
        }
        // Key is in the right half.
        else if(nums[mid] < key){
            start = mid+1;      
        }
        // Key is in the left half.
        else{
            end = mid-1;
        }
    }
    // Key not found.
    return -1;
}

// Finds the index of the smallest element (the pivot) in a rotated sorted array.
int pivot(vector<int>& nums){
    int start = 0;
    int end = nums.size()-1;
    // Modified binary search to find the rotation point.
    while(start < end){
        int mid = start + (end-start)/2;
        // If mid is in the larger, first part of the array.
        if(nums[mid] >= nums[0]){
            // The pivot must be to the right.
            start = mid+1;
        }
        // If mid is in the smaller, second part of the array.
        else{
            // The pivot could be mid or to its left.
            end = mid;
        }
    }
    // Start will point to the pivot index.
    return start;
}

// Searches for a value in a rotated sorted array.
int search(vector<int>& nums , int value){
    // Handle empty array case.
    if (nums.empty()) {
        return -1;
    }
    // Find the pivot point.
    int pivotIndex = pivot(nums);

    // Check if the value is in the right sorted portion (from pivot to end).
    if(value >= nums[pivotIndex] && value <= nums[nums.size()-1]){
        // If so, perform binary search on that part.
        return BS(nums, value, pivotIndex, nums.size()-1);
    }
    // Otherwise, the value must be in the left sorted portion.
    else{
        // Perform binary search on the left part.
        return BS(nums, value, 0, pivotIndex-1);
    }
}

// Main function to test the search functionality.
int main() {
    // Define a sample rotated sorted array.
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target_exists = 4;
    int target_missing = 3;

    cout << "Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // --- Test Case 1: Target is present in the array ---
    int index1 = search(nums, target_exists);
    cout << "\nSearching for " << target_exists << "..." << endl;
    if (index1 != -1) {
        cout << "Found " << target_exists << " at index: " << index1 << endl;
    } else {
        cout << target_exists << " not found." << endl;
    }

    // --- Test Case 2: Target is not present in the array ---
    int index2 = search(nums, target_missing);
    cout << "\nSearching for " << target_missing << "..." << endl;
    if (index2 != -1) {
        cout << "Found " << target_missing << " at index: " << index2 << endl;
    } else {
        cout << target_missing << " not found." << endl;
    }

    return 0;
}