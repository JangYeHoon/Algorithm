// fast campus 강의
// https://www.acmicpc.net/problem/2250
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	Node* parent = NULL;
	int number = 0;
	Node* left_node = NULL;
	Node* right_node = NULL;
};

int N, x, level_depth;
vector<int> level_min;
vector<int> level_max;

void inorder(Node* node, int level) {
	level_depth = max(level_depth, level);
	if (node->left_node != NULL)
		inorder(node->left_node, level + 1);
	level_min[level] = min(level_min[level], x);
	level_max[level] = max(level_max[level], x);
	x++;
	if (node->right_node != NULL)
		inorder(node->right_node, level + 1);
}

int main() {
	cin >> N;
	x = 1;
	level_depth = 1;
	int root = -1;
	vector<Node> tree(N + 1);
	level_min.push_back(N);
	level_max.push_back(0);

	for (int i = 1; i < N + 1; i++) {
		int number, left_node, right_node;
		cin >> number >> left_node >> right_node;
		tree[number].number = number;
		if (left_node != -1) {
			tree[number].left_node = &tree[left_node];
			tree[left_node].parent = &tree[number];
		}
		if (right_node != -1) {
			tree[number].right_node = &tree[right_node];
			tree[right_node].parent = &tree[number];
		}
		level_min.push_back(N);
		level_max.push_back(0);
	}

	for (int i = 1; i < N + 1; i++) {
		if (tree[i].parent == NULL)
			root = i;
	}

	inorder(&tree[root], 1);
	int result_level = 1;
	int result_width = level_max[1] - level_min[1] + 1;
	for (int i = 2; i < level_depth + 1; i++) {
		int width = level_max[i] - level_min[i] + 1;
		if (result_width < width) {
			result_level = i;
			result_width = width;
		}
	}

	cout << result_level << ' ' << result_width;
}