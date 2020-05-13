#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res(0);
        unordered_map<char, int> luoMap;

        luoMap.insert({'I', 1});
        //luoMap.insert({'IV', 4});
        luoMap.insert({'V', 5});
        //luoMap.insert({'IX', 9});
        luoMap.insert({'X', 10});
        //luoMap.insert({'XL', 40});
        luoMap.insert({'L', 50});
        //luoMap.insert({'XC', 90});
        luoMap.insert({'C', 100});
        //luoMap.insert({'CD', 400});
        luoMap.insert({'D', 500});
        //luoMap.insert({'DM', 900});
        luoMap.insert({'M', 1000});

        for(char i = 0; i < s.length(); i++) {
            if(luoMap[s[i]] < luoMap[s[i+1]]) {
                res = res - luoMap[s[i]];
            } else {
                res = res + luoMap[s[i]];
            }
        }
        return res;
    }
};


int main() {
    Solution test;
    cout << test.romanToInt("IV") << endl;
}