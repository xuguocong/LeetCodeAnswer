#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int reverse(int x) {
        long temp = 0;
        while(x != 0){
            int pop = x % 10;
            temp = temp * 10 + pop;
            if(temp > INT_MAX || temp < INT_MIN){
                return 0;
            }
            x /= 10;
        }
        return (int)temp;
    }
};

int main() {
    Solution test;
    cout << test.reverse(50000) << endl;
}