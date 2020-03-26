#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // if(nums.size() == 0) return 0;
        int ptr = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[ptr] != nums[i]) {
                ++ptr;
                nums[ptr] = nums[i];
            }
        }
        return ptr + 1;
    }
};


int main() {
    Solution test;
    vector<int> t = {};
    int nums = test.removeDuplicates(t);
    for(int i = 0; i < nums; i++) cout << t[i] << " ";
    cout << endl;
}