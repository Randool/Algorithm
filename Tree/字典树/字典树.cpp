//http://acm.hdu.edu.cn/showproblem.php?pid=1251
#include <cstdio>
#include <cstring>
#define MAX 26
using namespace std;

struct Node {
    Node *next[MAX];    // 26����ĸҶ�ӽ��
    int cnt;    // ���������ж��ٸ����ʾ����˽ڵ�
    Node() {    // ��ʼ�����캯��
        cnt = 0;    // ��ʼ��cntΪ0
        // ��26��Ҷ�ӽ�����
        memset(next,0,sizeof(next));
    }
};

class Trie {
private:
    Node *root; // Node ���ڵ�
public:
    // ��ʼ�����캯��
    Trie() {
        root = new Node;
    }
    // �������insert
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
    // ɾ������remove
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
    // ���Ҳ���find
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

