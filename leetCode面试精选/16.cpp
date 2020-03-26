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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l(0), r(nums.size() - 1), m;
        int res(nums[0] + nums[1] + nums[2]); // 不能初始化为INT_MAx，防止target为0时溢出
        while(l < nums.size() - 2) {
            m = l + 1;
            r = nums.size() - 1;
            while(m < r) {
                int temp = nums[l] + nums[m] + nums[r];
                if(temp > target) {
                    if(abs(temp - target) < abs(res - target)) res = temp;
                    r--;
                } else if(nums[l] + nums[m] + nums[r] < target) {
                    if(abs(temp - target) < abs(res - target)) res = temp;
                    m++;
                } else {
                    return target;
                }
            }
            l++;
        }
        return res;
    }
};


int main() {
    Solution test;
    vector<int> t = {-1, 2, 1, -4};
    vector<int> t2 = {1,1,1,1};
    cout << test.threeSumClosest(t2, -100) << endl;
    //test.threeSum(t);
}