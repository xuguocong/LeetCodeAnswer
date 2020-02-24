// 使用哈希表
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); i++) {
            if (myMap.find(target - nums[i]) != myMap.end()) {
                return {myMap[target-nums[i]], i};
            }
            myMap[nums[i]]=i;
        }
        return {};
    }
};


int main() {
    Solution test;
    vector<int>nums = {15, 16, 17};
    int target = 31;
    vector<int> result = test.twoSum(nums, target);
    cout << result[0] << "   " << result[1];
}