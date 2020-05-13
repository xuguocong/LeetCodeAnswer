#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int i = 0, j = 0;
        while(i < haystack.length()) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if(j == needle.length()) {
                    return i - j;
                } else {
                    i++;
                    i = i - j;
                    j = 0;
                }
            }
        }
        if(j == needle.length()) return i - j;
        return -1;
    }
};


int main() {
    Solution test;
    cout << test.strStr("aa", "aa") << endl;
    return 0;
}