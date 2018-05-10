// http://www.lintcode.com/en/problem/add-and-search-word/
#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie* next[26];
    bool end;
    Trie () :end(0) {
        memset(next, 0 ,sizeof(next));
    };
};

class WordDictionary {
private:
    bool dfs(Trie* root, string &word, int cur) {
        if (cur == word.length())
        {
            return root->end;
        }
        if (isalpha(word[cur])) {
            int index = word[cur] - 'a';
            if (root->next[index])
                return dfs(root->next[index], word, cur+1);
            else
                return 0;
        }
        else {
            bool ans = 0;
            for (int i=0; i<26; ++i)
                if (root->next[i])
                    ans |= dfs(root->next[i], word, cur+1);
            return ans;
        }
    }
public:
    Trie* root = new Trie;
    void addWord(string word) {
        int len = word.length();
        Trie* tmp = root;
        for (int i = 0; i < len; ++i)
        {
            int index = word[i] - 'a';
            if (tmp->next[index] == NULL)
                tmp->next[index] = new Trie;
            tmp = tmp->next[index];
        }
        tmp->end = 1;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int len = word.length();
        Trie* tmp = root;
        return dfs(tmp, word, 0);
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    WordDictionary dic;
    string ss;
    while (cin >> ss && ss != "@") {
        dic.addWord(ss);
    }

    while (cin >> ss && ss != "@") {
        if (dic.search(ss))
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}
