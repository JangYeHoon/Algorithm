// fast campus 강의
// https://www.acmicpc.net/problem/2250
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	Node* parent = NULL;
	int value;
	Node* left = NULL;
	Node* right = NULL;
};

int N, cnt, level_width;
vector<int> level_min;
vector<int> level_max;

void inorder(Node* node, int level) {
	level_width = max(level_width, level);
	if (node->left != NULL)
		inorder(node->left, level + 1);

	level_min[level] = min(level_min[level], cnt);
	level_max[level] = max(level_max[level], cnt);
	cnt += 1;

	if (node->right != NULL)
		inorder(node->right, level + 1);
}

int main() {
	cin >> N;
	level_min.push_back(N + 1);
	level_max.push_back(0);

	vector<Node> tree(N + 1);
	for (int i = 0; i < N; i++) {
		int value, left, right;
		cin >> value >> left >> right;
		tree[value].value = value;

		if (left != -1) {
			tree[value].left = &tree[left];
			tree[left].parent = &tree[value];
		}
		if (right != -1) {
			tree[value].right = &tree[right];
			tree[right].parent = &tree[value];
		}

		level_min.push_back(N + 1);
		level_max.push_back(0);
	}

	Node root;
	for (int i = 1; i < N + 1; i++) {
		if (tree[i].parent == NULL)
			root = tree[i];
	}

	inorder(&root, 1);
	int result_level = 0;
	int result_width = 0;
	for (int i = 1; i <= level_width; i++) {
		int width = level_max[i] - level_min[i] + 1;
		if (result_width < width) {
			result_level = i;
			result_width = width;
		}
	}

	cout << result_level << ' ' << result_width;
}