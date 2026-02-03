#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){

    int i = m-1;    // i: points to the last valid element of nums1
    int j = n-1;    // j: points to the last element of nums2
    int k = m+n-1;  // k: points to the last position in nums1 where the merged element will be placed
    while(i >= 0 && j >= 0){
        if(nums1 [i] > nums2[j]){
            nums1[k] = nums1[i]; // If nums1's element is larger, place it at k
            i--;                 // Move to the next element in nums1
        }
        else{
            nums1[k] = nums2[j]; // If nums2's element is larger or equal, place it at k
            j--;                 // Move to the next element in nums2
        }
        k--; // Move to the previous position in nums1
    }

    // If there are remaining elements in nums2, copy them to the beginning of nums1
    // (No need to handle remaining elements in nums1 as they are already in their correct sorted positions)
    while(j >= 0){
        nums1[k] = nums2[j];
        k--;
        j--;
    }
}

int main(){
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m1 = 3;
    vector<int> nums2 = {2, 5, 6};        
    int n1 = 3;

    cout << "Initial nums1: ";
    for(int x : nums1) cout << x << " ";
    cout << endl;
    cout << "nums2: ";
    for(int x : nums2) cout << x << " ";
    cout << endl;

    merge(nums1, m1, nums2, n1); // Call the merge function

    cout << "Merged nums1: ";
    for(int x : nums1) {
        cout << x << " ";
    }
    cout << endl << endl; // Expected: 1 2 2 3 5 6

    return 0; // Indicate successful execution
}