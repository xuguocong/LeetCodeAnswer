// 读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

// 	输入格式：
// 		每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10 ​100
// 			​​ 。

// 	输出格式：
// 		在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

// 	输入样例： 1234567890987654321123456789 输出样例：
// 		yi san wu
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int num;
	int length = s.size();
	for (int i = 0; i < length; ++i) {
		num += (s[i] - '0');
	}
	cout << num << "    " << length;

	stack<string> st;

	while (num != 0) {
		switch (num % 10) {
			case 0:
				st.push("ling");
				break;
			case 1:
				st.push("yi");
				break;
			case 2:
				st.push("er");
				break;
			case 3:
				st.push("san");
				break;
			case 4:
				st.push("si");
				break;
			case 5:
				st.push("wu");
				break;
			case 6:
				st.push("liu");
				break;
			case 7:
				st.push("qi");
				break;
			case 8:
				st.push("ba");
				break;
			case 9:
				st.push("jiu");
				break;
		}
		num /= 10;
	}
	for (int i = st.size(); i > 1; --i) {
		cout << st.top() << ' ';
		st.pop();
	}
	cout << st.top() << endl;
	return 0;
}