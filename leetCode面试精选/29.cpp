#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend > INT_MIN) return -dividend;
            return INT_MAX;
        }
        int a = dividend, b = divisor;
        bool sign = ((dividend > 0) ^ (divisor > 0)) || ((dividend < 0) ^ (divisor < 0));

        //a = a <= 0 ? a : -a;
        if(a > 0) a = -a;
        if(b > 0) b = -b;
        int res = div(a, b);
        if(sign) return -res;
        return res;
    }
private:
    int div (int a, int b) {
        if (a > b) return 0;
        int count = 1;
        int tb = b;
        while(tb >= INT_MIN >> 1 && (tb + tb) > a) {
            count = count + count;
            tb = tb + tb;
        }
        return count + div(a - tb, b);
    }
};


int main() {
    Solution test;
    cout << test.divide(INT_MIN, 2);
    return 0;
}