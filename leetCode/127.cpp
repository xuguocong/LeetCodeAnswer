// 127. 单词接龙
// 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

// 每次转换只能改变一个字母。
// 转换过程中的中间单词必须是字典中的单词。
// 说明:

// 如果不存在这样的转换序列，返回 0。
// 所有单词具有相同的长度。
// 所有单词只由小写字母组成。
// 字典中不存在重复的单词。
// 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
// 示例 1:

// 输入:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// 输出: 5

// 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//      返回它的长度 5。
// 示例 2:

// 输入:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]

// 输出: 0

// 解释: endWord "cog" 不在字典中，所以无法进行转换。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) return 0;

        unordered_set<string> from({ beginWord });
        unordered_set<string> to({ endWord });
        int ans = 2;

        while (!from.empty())
        {
            unordered_set<string> next;
            for (auto& word : from)
            {
                wordSet.erase(word);
            }
            for (auto& word : from)
            {
                for (int i = 0; i < word.size(); i++)
                {
                    string s = word;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        s[i] = c;
                        if (wordSet.count(s) == 0) continue;
                        next.insert(s);
                        if (to.count(s) == 0) continue;
                        return ans;
                    }
                }
            }
            from = next;
            if (from.size() > to.size())
            {
                swap(from, to);
            }
            ans++;
        }

	    return 0;
    }
};


int main() {
    Solution test;
    return 0;
}