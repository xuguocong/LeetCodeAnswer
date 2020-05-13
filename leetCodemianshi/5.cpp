#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define max(a,b) a > b ? a : b
int findSubString(string s, int start, int end) {
    while(start >= 0 && end < s.length() && s[end] == s[start]) {
        start--;
        end++;
    }
    return end - start - 1;
}

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), maxLen = -1, l(0);
        if(len < 2) return s;
        for(int i = 0; i < len; i++) {

            int begin = findSubString(s,i,i);
            int end = findSubString(s,i,i+1);
            if(maxLen < (max(begin, end))) {
                maxLen = max(begin, end);
                l = i - (maxLen-1)/2;
                //r = i + maxLen/2;
            }
            // if(maxLen>r-l+1) {
            //     l = i - (maxLen-1)/2;
            //     r = i + maxLen/2;
            // }
        }
        return s.substr(l, maxLen);
    }
};


int main() {
    Solution test;
    string s = "abba";
    cout << test.longestPalindrome(s) << endl;
}