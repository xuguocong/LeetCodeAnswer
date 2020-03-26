// 131. 分割回文串
// 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

// 返回 s 所有可能的分割方案。

// 示例:

// 输入: "aab"
// 输出:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        partition(s, 0, tmp, res);
        return res;
    }

    void partition(const string& s, int start, vector<string>& tmp, vector<vector<string>>& res)
    {
    	if (start >= s.size()) res.push_back(tmp);
    	string temp;
    	for (int i = start; i < s.size(); ++i)
    	{
    		temp.push_back(s[i]);
    		if (IsPalindrome(temp)) {
    			tmp.push_back(temp);
    			partition(s, i+1, tmp, res);
    			tmp.pop_back();
    		}
    	}
    }
    bool IsPalindrome(const string& s)
    {
    	for (int i = 0; i < s.size()/2; ++i) {
    		if(s[i] != s[s.size()-i-1])
    			return false;
    	}
    	return true;
    }
};


int main() {
    Solution test;
    return 0;
}