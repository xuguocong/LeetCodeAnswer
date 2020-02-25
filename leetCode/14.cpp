#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        if(strs.size() == 1) return strs[0];
        string res = "";
        for(int i = 0; i < strs[0].length(); i++) { //第i个字符
            for(int j = 0; j < strs.size(); j++) { //第j个字符串
                if(i > strs[j].length()) return res;
                if(strs[0][i] != strs[j][i]) return res;
                if(j == strs.size() - 1) res += strs[0][i];
            }
        }
        return res;
    }
};


int main() {
    Solution test;
    vector<string> strs = {"abb", "abc"};
    cout << test.longestCommonPrefix(strs) << endl;
}