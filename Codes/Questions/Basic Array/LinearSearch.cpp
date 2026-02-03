#include <iostream>
#include <vector>
using namespace std;
bool Search(vector<int>& nums, int key) {
    // Loop through each element of the vector
    for (size_t i = 0; i < nums.size(); i++) { // Using size_t to avoid signed/unsigned warning
        // Check if the current element matches the key
        if (nums[i] == key) {
            // Return true (1) if the key is found
            return true;
        }
    }
    return false;
}

// Main function where the program starts
int main() {
    // Declare a variable to hold the search key
    int key;
    // Create and initialize a vector of integers
    vector<int> nums = {100, -50, 25, 75, 80, -15};

    // Prompt the user to enter a value
    cout << "Enter the value to be Searched : ";
    // Read the user's input
    cin >> key;

    // Call the Search function and store the result
    bool found = Search(nums, key);

    // Check if the value was found
    if (found) {
        // If found, print a success message
        cout << "the value is present in the array";
    } else {
        // If not found, print a different message
        cout << "the value is not present in the array";
    }

    // Return 0 to indicate successful execution
    return 0;
}