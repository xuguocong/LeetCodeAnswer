#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> arr;
        for(char c : t) arr[c]++;
        int left = 0, count = 0, start = left, maxLen = s.size() + 1;
        for(int i = 0; i < s.size(); ++i) { //当区间和t不匹配时，向右拓展区间
            if(--arr[s[i]] >= 0) count++;  //left和i构成的区间中有一个字母与t中的字母匹配
            while(count == t.size()) {  //可以和t匹配的最小子串
                if (maxLen > i - left + 1) {
                    maxLen = i - left + 1;
                    start = left;
                }
                if(++arr[s[left]] > 0) count--; //left右移找到一个不符合要求的区间
                left++;
            }
        }
        return maxLen == s.size() + 1 ? "" : s.substr(start, maxLen);
    }
};


int main() {
    Solution test;
    cout << test.minWindow("ADOBECODEBANC", "ABC") << endl;
}