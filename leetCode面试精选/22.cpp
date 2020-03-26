#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0) return res;
        paren("", n, n, true, res);
        return res;
    }
private:
    void paren(string item, int n, int r, bool flag, vector<string> &res) {
        if (n == 0) {
            for(int i = 0; i < r; i++) item = item + ')';
            res.push_back(item);
            return;
        }
        if(flag) {
            item = item + '(';
            n--;
            paren(item, n, r, true, res);
            if(n > 0) paren(item, n, r, false, res);
        } else {
            item = item + ')';
            r--;
            paren(item, n, r, true, res);
            if (n < r) paren(item, n, r, false, res);
        }
    }
};


int main() {
    Solution test;
    vector<string> t;
    t = test.generateParenthesis(3);
    for(int i = 0; i < t.size(); i++) {
        cout << t[i] << endl;
    }
}