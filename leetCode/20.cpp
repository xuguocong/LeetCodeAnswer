#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2) return false;
        if(s.empty()) return true;
        vector<char> list;
        for (char c : s) {
            switch(c) {
            case '{' :  {
                list.push_back('}');
                break;
            }
            case '[' : {
                list.push_back(']');
                break;
            }
            case '(' : {
                list.push_back(')');
                break;
            }
            case '}' : {
                if(list.size() == 0 || list.back() != '}') {
                    return false;
                } else {
                    list.pop_back();
                }
                break;
            }
            case ']' : {
                if(list.size() == 0 || list.back() != ']') {
                    return false;
                } else {
                    list.pop_back();
                }
                break;
            }
            case ')' : {
                if(list.size() == 0 || list.back() != ')') {
                    return false;
                } else {
                    list.pop_back();
                }
                break;
            }
            }
        }
        if (list.size() == 0) return true;
        return false;
    }
};


int main() {
    Solution test;
    cout << test.isValid("}") << endl;
}