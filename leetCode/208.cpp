// 208. 实现 Trie (前缀树)
// 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

// 示例:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // 返回 true
// trie.search("app");     // 返回 false
// trie.startsWith("app"); // 返回 true
// trie.insert("app");   
// trie.search("app");     // 返回 true
// 说明:

// 你可以假设所有的输入都是由小写字母 a-z 构成的。
// 保证所有输入均为非空字符串。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<string.h>
#include<unordered_set>
#include<bitset>
using namespace std;
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        isWord = false;
        for(int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *s = this;
        for(char c : word) {
            if(!s->child[c - 'a']) {
                s->child[c - 'a'] = new Trie();
            }
            s = s->child[c - 'a'];
        }
        s->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *s = this;
        for(char c : word) {
            if(!s->child[c - 'a']) {
                return false;
            }
            s = s->child[c - 'a'];
        }
        return s->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *s = this;
        for(char c:prefix){
            if(!s->child[c-'a']){
                return false;
            }
            s = s->child[c - 'a'];
        }
        return true;
    }
private:
    Trie *child[26];
    bool isWord;
};


int main() {
    return 0;
}
