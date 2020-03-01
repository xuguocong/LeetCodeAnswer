#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // if(nums.size() == 0) return 0;
        int ptr = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != val) {
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        return ptr;
    }
};


int main() {
    Solution test;
}