#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value, height;
    Node *lchild, *rchild;
    Node(int v = 0) {
        value = v, height = 0;
        lchild = rchild = NULL;
    }
};

class AVL {
private:
    Node *root;

    int get_height(Node *root) { /// ����ڵ�root�ĸ߶�
        if (!root) return 0;
        return root->height;
    }

    void update_height(Node *root) { /// ����root�ڵ�ĸ߶�
        root->height = max(get_height(root->lchild),
                           get_height(root->rchild)) + 1;
    }

    int get_balance_factor(Node *root) {    /// ����ڵ��ƽ������
        return get_height(root->lchild) - get_height(root->rchild);
    }

    void _insert(Node *&root, const int &v) {
        if (!root) {
            root = new Node(v);
            return;
        }
        if (v == root->value) {
            /// �������Ԫ���Ѵ���AVL�У���������
            return;
        }
        else if (v < root->value) {  /// ��left���룬�������
            _insert(root->lchild, v);
            update_height(root);
            if (get_balance_factor(root) == 2) {
                if (get_balance_factor(root->lchild) == 1) /// LL��ֻҪһ����������
                    rotate_right(root);
                else {  /// LR����Ҫ������������
                    rotate_left(root->lchild);
                    rotate_right(root);
                }
            }
        }
        else {  /// ��right���룬�����ұ�
            _insert(root->rchild, v);
            update_height(root);
            if (get_balance_factor(root) == -2) {
                if (get_balance_factor(root->rchild) == -1) /// RR��ֻҪһ����������
                    rotate_left(root);
                else {  /// RL����Ҫ������������
                    rotate_right(root->rchild);
                    rotate_left(root);
                }
            }
        }
    }

    void rotate_left(Node *&root) {     /// ��������
        Node *temp = root->rchild;
        root->rchild = temp->lchild;
        temp->lchild = root;
        update_height(root);
        update_height(temp);
        root = temp;
    }
    void rotate_right(Node *&root) {    /// ��������
        Node *temp = root->lchild;
        root->lchild = temp->rchild;
        temp->rchild = root;
        update_height(root);
        update_height(temp);
        root = temp;
    }

    bool _search(Node *root, const int &v) {
        if (!root) return 0;
        if (v == root->value) return 1;
        else if (v < root->value) return _search(root->lchild, v);
        else return _search(root->rchild, v);
        return 0;
    }

    void _preorder(Node *root) {
        if (!root) return;
        cout << root->value << " ";
        _preorder(root->lchild);
        _preorder(root->rchild);
    }
    void _inorder(Node *root) {
        if (!root) return;
        _preorder(root->lchild);
        cout << root->value << " ";
        _preorder(root->rchild);
    }
    void _postorder(Node *root) {
        if (!root) return;
        _preorder(root->lchild);
        _preorder(root->rchild);
        cout << root->value << " ";
    }

public:
    AVL() { root = NULL; }

    /// ���Һ���
    bool search(const int &v) { _search(root, v); }

    /// ���뺯��
    void insert(const int &v) { _insert(root, v); }

    /// ɾ���ڵ�
    void remove(const int &v) { return; }

    /// ��������
    void preorder() { _preorder(root); }
    void inorder()  { _inorder(root); }
    void postorder() { _postorder(root); }
};


int main()
{
    int a[8] = {5, 7, 9, 3, 10, 4, 8, 6};
    AVL avl;

    for (int i = 0; i < 8; ++i)
        avl.insert(a[i]);

    int t;
    while (cin >> t) {
        if (avl.search(t)) cout << t << " in AVL Tree\n";
        else cout << "Can't find\n";
    }
    return 0;
}
