#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(!digits.empty()) {
            partten(digits, 0, "", res);
        }
        return res;
    }
private:
    unordered_map<char, string> map = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    void partten(string digits, int offset, string item, vector<string> &res) {
        if(offset >= digits.length()) res.push_back(item);
        string temp = item;
        for(int i = 0; i < map[digits[offset]].length(); i++) {
            item = temp;
            item = item + map[digits[offset]][i];
            partten(digits, offset + 1, item, res);
        }
    }
};


int main() {
    Solution test;
    vector<string> res = test.letterCombinations("233");
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    //test.threeSum(t);
}