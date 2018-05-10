#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<int>::iterator Iter;

vector<int> result;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

TreeNode *buildTree(Iter pstart, Iter pend, Iter istart, Iter iend) {
	if (istart == iend) return NULL;

	int rootVal = *pstart;
	TreeNode *root = new TreeNode(rootVal);

	Iter inoRoot = find(istart, iend, rootVal);

	root->left  = buildTree(pstart+1, pstart+1+(inoRoot-istart), istart, inoRoot);
	root->right = buildTree(pstart+1+(inoRoot-istart), pend, inoRoot+1, iend);

	return root;
}

void Postorder(TreeNode* root) {
	if (root == NULL) return ;
	TreeNode *left = root->left;
	TreeNode *right = root->right;
	Postorder(left);
	Postorder(right);
	result.push_back(root->val);
}

int main() {
	int n, t;
	while (~scanf("%d", &n)) {
		vector<int> pre, ino;
		for (int i=0; i < n; ++i) {
			scanf("%d", &t);
			pre.push_back(t);
		}
		for (int i=0; i < n; ++i) {
			scanf("%d", &t);
			ino.push_back(t);
		}
		TreeNode *root = buildTree(pre.begin(), pre.end(), ino.begin(), ino.end());
		Postorder(root);
		
		for (int i=0; i<result.size(); ++i)
		{
			printf("%d", result[i]);
			if (i != result.size()-1) printf(" ");
			else printf("\n");
		}
		
		result.clear();
	}
	return 0;
}
