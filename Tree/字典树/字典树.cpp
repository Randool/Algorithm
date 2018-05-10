//http://acm.hdu.edu.cn/showproblem.php?pid=1251
#include <cstdio>
#include <cstring>
#define MAX 26
using namespace std;

struct Node {
    Node *next[MAX];    // 26个字母叶子结点
    int cnt;    // 用来计数有多少个单词经过此节点
    Node() {    // 初始化构造函数
        cnt = 0;    // 初始化cnt为0
        // 将26个叶子结点清空
        memset(next,0,sizeof(next));
    }
};

class Trie {
private:
    Node *root; // Node 根节点
public:
    // 初始化构造函数
    Trie() {
        root = new Node;
    }
    // 插入操作insert
    void insert(char *words) {
        Node *p = root;
        int len = strlen(words);
        for (int i = 0; i < len; ++i) {
            int index = words[i] - 'a';
            if (p->next[index] == NULL) {
                p->next[index] = new Node;
            }
            p = p->next[index];
            ++(p->cnt);
        }
    }
    // 删除操作remove
    void remove(char *words) {
        Node *p = root;
        int len = strlen(words);
        for (int i = 0; i < len; ++i) {
            int index = words[i] - 'a';
            if (p->next[index] == NULL) return;
            p = p->next[index];
        }
        for (int i = 0; i < 26; ++i)
            if (p->next[i]) return;
        delete p;
    }
    // 查找操作find
    bool find(char *words) {
        Node *p = root;
        int len = strlen(words);
        for (int i = 0; i < len; ++i) {
            int index = words[i] - 'a';
            if (p->next[index] == NULL)
                return false;
            p = p->next[index];
        }
        return true;
    }
};

/*
ba
b
band
abc
*/
int main() {
    char words[26];
    Trie trie;

    while(gets(words) && strlen(words)) {
        if(strcmp(words,"")==0) break;
        trie.insert(words);
    }

    while(scanf("%s",&words)!=EOF)
        if (trie.find(words)) printf("%s is found\n", words);
        else printf("%s is not found\n", words);

    return 0;
}

