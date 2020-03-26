#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;
        int *next = new int[needle.length() + 1];
        getNext(needle, next);
        int i = 0, j = 0;
        int n = needle.length();
        while((i < haystack.length()) && j < n) {
            if(j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        if(j == needle.length()) {
            return i - j;
        } else {
            return -1;
        }
    }
private:
    void getNext(string &p, int *next)
    {
        next[0] = -1;
        int i = 0, j = -1;

        while (i < p.length())
        {
            if (j == -1 || p[i] == p[j])
            {
                ++i;
                ++j;
                next[i] = j;
            }
            else
                j = next[j];
        }
    }
};


int main() {
    Solution test;
    cout << test.strStr("hello", "ll") << endl;
    return 0;
}