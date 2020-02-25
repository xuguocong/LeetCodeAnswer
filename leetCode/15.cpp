#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool compare(int a,int b)
{
  return a<b; //升序排列
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        sort(nums.begin(),nums.end());
        int l(0), r(nums.size() - 1), m;
        while(l < nums.size() - 2) {
            if(l != 0 && nums[l] == nums[l-1]) {
                l++;
                continue;
            }
            m = l + 1;
            r = nums.size() - 1;
            while(m < r) {
                if(m - l > 1 && nums[m] == nums[m - 1]) {
                    m++;
                    continue;
                }
                if(nums[l] + nums[m] + nums[r] > 0) {
                    r--;
                } else if(nums[l] + nums[m] + nums[r] < 0){
                    m++;
                } else {
                    vector<int>  temp = {nums[l], nums[m], nums[r]};
                    res.push_back(temp);
                    m++;
                }
            }
            l++;
        }
        return res;
    }
};


int main() {
    Solution test;
    vector<int> t = {-1, 0, 1, 2, -1, -4};
    vector<int> t2 = {0,0,0,0};
    vector<vector<int>> res = test.threeSum(t);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    //test.threeSum(t);
}