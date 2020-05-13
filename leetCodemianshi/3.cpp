#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        if(s.length() == 1) return 1;
        // 子串边界
        int q = 0, e = 0;
        // 最长子串长度
        int len = 1;
        for(int i = 1; i < s.length(); i++) {
            for(int j = q; j <= e; j++) {
                if(s[j] == s[i]) {
                    q = j + 1;
                    break;
                }
            }
            e++;
            if(e - q + 1 > len) {
                len = e - q + 1;
            }
        }
        return len;
    }
};


int main() {
    Solution test;
    string s = "pwwkew";
    int len = test.lengthOfLongestSubstring(s);
    cout << len << endl;
}