#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Checks if we can place 'k' cows with at least 'mid' distance between them.
bool isPossible(vector<int>& stalls, int k, int mid) {
    int cowCount = 1;         // Place the first cow in the first stall.
    int lastPos = stalls[0];  // Position of the last placed cow.
    int n = stalls.size();

    // Greedily place the rest of the cows.
    for (int i = 1; i < n; i++) {
        // If the current stall is at a valid distance, place a cow.
        if (stalls[i] - lastPos >= mid) {
            cowCount++;
            if (cowCount == k) {
                return true; // Successfully placed all k cows.
            }
            lastPos = stalls[i]; // Update the position of the last placed cow.
        }
    }
    return false; // Could not place all k cows.
}

// Finds the largest minimum distance between any two cows using binary search.
int aggresiveCows(vector<int>& stalls, int k) {
    // Sorting is necessary to apply the greedy placement strategy.
    sort(stalls.begin(), stalls.end());

    int start = 0;
    int n = stalls.size();
    // The maximum possible distance is between the first and last stall.
    int end = stalls[n - 1] - stalls[0];
    int ans = -1;

    // Binary search for the largest possible minimum distance.
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(stalls, k, mid)) {
            // 'mid' is a possible distance. Try for a larger one.
            ans = mid;
            start = mid + 1;
        } else {
            // 'mid' is too large. Try for a smaller distance.
            end = mid - 1;
        }
    }
    return ans;
}

// Main function to run the code.
int main() {
    // Sample input
    vector<int> stalls = {1, 2, 8, 4, 9};
    int k = 3; // Number of cows

    // Call the function to find the largest minimum distance.
    int result = aggresiveCows(stalls, k);

    // Print the result.
    cout << "The largest minimum distance is: " << result << endl;
    // Expected output for this example is 3.
    // Cows can be placed at stalls 1, 4, and 8 (or 9).
    // Distances are (4-1)=3 and (8-4)=4. The minimum is 3.
    
    return 0;
}