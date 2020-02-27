#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        int l, m1, m2, r, temp = target;
        for(l = 0; l < nums.size() - 3; ++l) {
            if(l != 0 && nums[l] == nums[l-1]) continue;
            target = temp - nums[l];
            for(m1 = l + 1; m1 < nums.size() - 2; ++m1) {
                if(m1 != l + 1 && nums[m1] == nums[m1-1]) continue;
                m2 = m1 + 1;
                r = nums.size() - 1;
                //cout << l << m1 << m2 << r << endl;
                while(m2 < r) {
                    if(m2 - m1 > 1 && nums[m2] == nums[m2 - 1]) {
                        m2++;
                        continue;
                    }
                    int temp = nums[m1] + nums[m2] + nums[r];
                    if (temp > target) {
                        r--;
                    } else if(temp < target) {
                        m2++;
                    } else {
                        res.push_back({nums[l], nums[m1], nums[m2], nums[r]});
                        m2++;
                    }
                    //cout << l << m1 << m2 << r << endl;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution test;
    vector<int> t = {1, 0, -1, 0, -2, 2};
    vector<int> t2 = {0,0,0,0};
    vector<vector<int>> res = test.fourSum(t2, 0);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    //test.threeSum(t);
}