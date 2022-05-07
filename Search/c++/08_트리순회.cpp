// fast campus 강의
// https://www.acmicpc.net/problem/1991
// 2

#include <iostream>
#include <vector>

using namespace std;

struct node{
    char value;
    node* left = NULL;
    node* right = NULL;
};

int N;
vector<node> tree(26);

void preorder(node* node) {
    cout << node->value;
    if (node->left != NULL)
        preorder(node->left);
    if (node->right != NULL)
        preorder(node->right);
}

void inorder(node* node) {
    if (node->left != NULL)
        inorder(node->left);
    cout << node->value;
    if (node->right != NULL)
        inorder(node->right);
}

void postorder(node* node) {
    if (node->left != NULL)
        postorder(node->left);
    if (node->right != NULL)
        postorder(node->right);
    cout << node->value;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        char value, left, right;
        cin >> value >> left >> right;
        tree[value - 'A'].value = value;

        if (left != '.')
            tree[value - 'A'].left = &tree[left - 'A'];
        if (right != '.')
            tree[value - 'A'].right = &tree[right - 'A'];
    }

    node* root = &tree[0];
    
    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
}