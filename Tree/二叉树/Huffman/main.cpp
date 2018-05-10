#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 结点结构
struct Node {
    int val;
    char ch;
    Node *l, *r;
    Node (int v=0, char c=0, Node *L=NULL, Node *R=NULL) {
        val = v;
        ch = c;
        l = L, r = R;
    }
};

// 比较函数
struct cmp {
    bool operator () (const Node *a, const Node *b) {
        if (a->val != b->val) return a->val > b->val;
        return a->ch < b->ch;
    }
};

// 遍历输出Huffman编码
void traverse(Node *root, vector<int> &code) {
    // cout << root->val << endl;
    if(root->ch > 0) {
        printf("'%c' : ", root->ch);
        for (int i = 0; i < code.size(); ++i)
            printf("%d ", code[i]);
        printf("\n");
        return;
    }
    code.push_back(0);
    traverse(root->l, code);
    code.pop_back();
    code.push_back(1);
    traverse(root->r, code);
    code.pop_back();
}

int main () {
	// Huffman优先队列
    priority_queue<Node *, vector<Node *>, cmp> huffman;
    vector<int> code;

    int t, n;
    char ch;
    scanf("%d", &n);
    getchar();

	// 输入格式：“对应的字符” “出现的频率” 
    while (n--) {
        scanf("%c %d", &ch, &t);
        getchar();
        huffman.push(new Node(t, ch));
    }

	// 编码过程
    while (huffman.size() != 1) {
        Node *first = huffman.top();
        huffman.pop();
        Node *second = huffman.top();
        huffman.pop();

        Node *mershed = new Node(first->val + second->val, 0, first, second);
        huffman.push(mershed);
    }
    Node *root = huffman.top();
    huffman.pop();

    printf("\n");

    traverse(root, code);

    return 0;
}

/** Example
12
A 2
B 3
C 5
D 7
E 11
F 13
G 17
H 19
I 23
J 31
K 37
L 41
*/
