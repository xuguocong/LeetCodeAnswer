#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m(nums1.size()), n(nums2.size()), p1 = 0, p2 = 0;
        int *nums = new int[m+n];
        for(int i = 0; i < m+n; i++) {
            if(p1 >= m) {
                nums[i] = nums2[p2];
                p2++;
            } else if(p2 >= n) {
                nums[i] = nums1[p1];
                p1++;
            } else if(nums1[p1] > nums2[p2]) {
                nums[i] = nums2[p2];
                p2++;
            } else {
                nums[i] = nums1[p1];
                p1++;
            }
        }
        if((n + m) % 2 == 0) {
            return (double(nums[(n+m)/2]) + double(nums[(n+m)/2 - 1])) / 2;
        } else {
            return double(nums[(n+m)/2]);
        }
    }
};


int main() {
    Solution test;
    vector<int> nums1 = {3, 5, 10};
    vector<int> nums2 = {1, 2, 4};
    cout << test.findMedianSortedArrays(nums1, nums2) << endl;
}