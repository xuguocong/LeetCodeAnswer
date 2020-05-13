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
        for(int i = 0; i < haystack.size(); i++) {
            if(haystack[i] == needle[0]) {
                int j;
                for(j = 1; j < needle.size(); j++) {
                    if(haystack[i+j] != needle[j]) break;
                }
                if(j == needle.size()) return i;
            }
        }
        return -1;
    }
};


int main() {
    Solution test;
    cout << test.strStr("hello", "ll") << endl;
    return 0;
}