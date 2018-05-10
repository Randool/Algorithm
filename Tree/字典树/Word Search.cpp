#include <bits/stdc++.h>
using namespace std;

int dirx[] = {0,0,1,-1};
int diry[] = {1,-1,0,0};

struct Trie {
    string word;
    Trie* next[26];
    Trie() {
        for (int i = 0; i < 26; ++i)
            this->next[i] = NULL;
        word = "";
    }
};

class Solution {
private:
    Trie* root = new Trie;

    void Build(string &ss) {
    	Trie *p = root;
        for (int i=0; i<ss.length(); ++i) {
            if (p->next[ss[i]-'a'] == NULL)
                p->next[ss[i]-'a'] = new Trie();
            else
				p = p->next[ss[i]-'a'];
        }
        p->word = ss;
    }

    void Search(vector<vector<char> > &board, Trie *cur, vector<string> result, int x, int y) {
        if (cur->word != "") {
            result.push_back(cur->word);
            cur->word = "";
        }
        for (int i=0; i<4; ++i) {
            int nx = x + dirx[i], ny = y + diry[i];
            if (nx<0 || ny<0 || nx==board.size() || ny==board[0].size()) continue;
            if (cur->next[board[nx][ny] - 'a'])
                Search(board, cur->next[board[nx][ny] - 'a'], result, nx, ny);
        }
    }

public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        vector<string> result;
        if (board.empty() || board[0].empty() || words.empty()) return result;

        // Building Trie;
        for (int i = 0; i < words.size(); ++i)
            Build(words[i]);

        // Finding words;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->next[board[i][j]-'a'] != NULL)
                    Search(board, root->next[board[i][j]-'a'], result, i, j);
            }
        }
        return result;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    Solution sol;
    vector<vector<char> > board;
    vector<string > words;
    string line;

    while (cin >> line && line[0] != '@') {
        int len = line.length();
        vector<char> temp;
        for (int i = 0; i < len; ++i) temp.push_back(line[i]);
        board.push_back(temp);
    }

    while (cin >> line && line[0] != '@')
        words.push_back(line);

    vector<string> result = sol.wordSearchII(board, words);
    
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << endl;

    return 0;
}
