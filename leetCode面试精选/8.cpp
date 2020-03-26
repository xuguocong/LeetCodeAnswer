#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int index(0), res(0), pop(0), flag(1);
        while(str[index] == ' ') {
            index++;
            if(index > str.length()) {
                return 0;
            }
        }
        if(str[index] == '-') {
            flag = -1;
            index++;
        } else if(str[index] == '+'){
            index++;
        }

        if(index > str.length() || (str[index] < '0' && str[index] > '9')) {
            return 0;
        }
        while(index < str.length() && str[index] >= '0' && str[index] <= '9') {
            pop = (str[index] - '0')* flag;
            if(res > INT32_MAX/10 || (res == INT32_MAX / 10 && pop > 7)) return INT32_MAX;
            if(res < INT32_MIN/10 || (res == INT32_MIN / 10 && pop < -8)) return INT32_MIN;
            res = res * 10 + pop;
            index++;
        }
        return res;
    }
};

int main() {
    Solution test;
    cout << test.myAtoi("-91283472332") << endl;
}