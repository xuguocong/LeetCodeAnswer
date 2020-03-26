// 169. 多数元素
// 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

// 示例 1:

// 输入: [3,2,3]
// 输出: 3
// 示例 2:

// 输入: [2,2,1,1,1,2,2]
// 输出: 2
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int majorityElement_sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() / 2 + 1; ++i) {
            if(nums[i] == nums[i + nums.size() / 2]) return nums[i];
        }
        return 0;
    }

    int majorityElement_hash(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i) {
            if(!map[nums[i]]) {
                map[nums[i]] = 1;
            } else {
                map[nums[i]]++;
                if(map[nums[i]] > nums.size() / 2) return nums[i];
            }
        }
        return nums[0];
    }

    int majorityElement(vector<int>& nums) {
        // 投票
        int tmp;
        int count = 0;
        for(int n : nums) {
            if(count == 0) tmp = n;
            if(n == tmp){
                ++count;
            } else {
                --count;
            }
        }
        return tmp;
    }
};


int main() {
    Solution test;
    return 0;
}