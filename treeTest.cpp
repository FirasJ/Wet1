/* * treeTest.cpp
 *
 *  Created on: Nov 25, 2014
 *      Author: Firas
 */
/*
#include <iostream>
#include "list.h"
#include "tree.h"

const int MAX = 256;
int mapIndex[MAX];
void mapToIndices(int inorder[], int n) {
	for (int i = 0; i < n; i++) {
		assert(0 <= inorder[i] && inorder[i] < MAX);
		mapIndex[inorder[i]] = i;
	}
}

class TreeNode {
public:
	int info;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* buildTree(int in[], int pre[], int inStart, int inEnd) {
	static int preIndex = 0;
	if (inStart > inEnd)
		return NULL;

	int root_value = pre[preIndex++];

	TreeNode* root = new TreeNode;
	root->info = root_value;

	if (inStart == inEnd) {
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	int root_idx = mapIndex[root_value];
	root->left = buildTree(in, pre, inStart, root_idx - 1);
	root->right = buildTree(in, pre, root_idx + 1, inEnd);

	return root;
}

void print_TreeNode_inorder(TreeNode* root) {
	if (!root)
		return;

	print_TreeNode_inorder(root->left);
	std::cout << root->info;
	print_TreeNode_inorder(root->right);
}

int main() {
	int preorder[] = { 7, 10, 4, 3, 1, 2, 8, 11 };
	int inorder[] = { 4, 10, 3, 1, 7, 11, 8, 2 };
	int len = sizeof(preorder) / sizeof(preorder[0]);
	mapToIndices(inorder, len);
	TreeNode* tree = buildTree(inorder, preorder, 0, len - 1);
	print_TreeNode_inorder(tree);
	std::cout << std::endl;
	return 0;
}

*/
