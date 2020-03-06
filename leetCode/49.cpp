// 49. 字母异位词分组
// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

// 示例:

// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// 说明：

// 所有输入均为小写字母。
// 不考虑答案输出的顺序。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> contain;
        int sub = 0;
        for(auto s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if(contain.find(tmp) != contain.end()) {
                res[contain[tmp]].push_back(s);
            } else {
                vector<string> t(1, s);
                res.push_back(t);
                contain.insert({tmp, sub++});
            }
        }
        return res;
    }
};


int main() {
    Solution test;
    return 0;
}