#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to find all pairs that sum to S
vector<vector<int>> pairSum(vector<int> &nums , int S){
    // Vector to store the resulting pairs
    vector<vector<int>> ans;
    // Get the size of the input array
    int n = nums.size();

    // Iterate through each element with an outer loop
    for(int i = 0 ; i < n ; i++){
        // Iterate through remaining elements with an inner loop
        for(int j = i+1 ; j < n ; j++){
            // Check if the pair's sum is equal to S
            if( nums[i] + nums[j] == S){
                // Create a temporary vector for the pair
                vector<int> temp;
                // Add the smaller element first
                temp.push_back(min(nums[i] , nums[j]));
                // Add the larger element second
                temp.push_back(max(nums[i] , nums[j]));
                // Add the sorted pair to the answer list
                ans.push_back(temp);
            }
        }
    }
    // Sort the final list of pairs
    sort(ans.begin(),ans.end());
    // Return the result
    return ans;
}

// Main function to demonstrate the pairSum function
int main() {
    // Create a sample vector of numbers
    vector<int> arr = {1, 2, 3, 4, 5, 0};
    // Set the target sum
    int targetSum = 5;

    // Call the function to find the pairs
    vector<vector<int>> result = pairSum(arr, targetSum);

    // Print the output
    cout << "Pairs that sum to " << targetSum << ":" << endl;
    for (const auto& pair : result) {
        cout << "{" << pair[0] << ", " << pair[1] << "}" << endl;
    }

    // Indicate successful execution
    return 0;
}