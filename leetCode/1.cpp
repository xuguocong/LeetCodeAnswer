// test
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == target - nums[i]) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution test;
    vector<int>nums = {15, 16, 17};
    int target = 31;
    vector<int> result = test.twoSum(nums, target);
    cout << result[0] << "   " << result[1];
}