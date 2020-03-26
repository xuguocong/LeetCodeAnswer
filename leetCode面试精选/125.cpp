// 125. 验证回文串
// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

// 说明：本题中，我们将空字符串定义为有效的回文串。

// 示例 1:

// 输入: "A man, a plan, a canal: Panama"
// 输出: true
// 示例 2:

// 输入: "race a car"
// 输出: false

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;
        int p1 = 0, p2 = s.length() - 1;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
        }
        while(p1 <= p2) {
            while(p1 < s.length() && !((s[p1] >= 'a' && s[p1] <= 'z') || (s[p1] >= '0' && s[p1] <= '9'))) ++p1;
            while(p2 >= 0 && !((s[p2] >= 'a' && s[p2] <= 'z') || (s[p2] >= '0' && s[p2] <= '9'))) --p2;
            if(p1 > p2) return true;
            if(s[p1] != s[p2]) return false;
            ++p1;
            --p2;
        }
        return true;
    }
};


int main() {
    Solution test;
    cout << test.isPalindrome("0P");
    return 0;
}