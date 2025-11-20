#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* left;
    Node* right;
};

Node* makeNode(int x) {
    Node* p = new Node();
    p->num = x;
    p->left = p->right = NULL;
    return p;
}

Node* insert(Node* root, int x) {
    if (!root) return makeNode(x);
    if (x < root->num)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->num << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->num << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->num << " ";
}

int main() {
    Node* root = NULL;
    int data[] = {2, 3, 9, 18, 0, 1, 4, 5};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Inserting values into the Binary Search Tree:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
        root = insert(root, data[i]);
    }

    cout << "\n\nTree Traversals:\n";
    cout << "In-order Traversal (L, Root, R): ";
    inorder(root);
    cout << "\nPre-order Traversal (Root, L, R): ";
    preorder(root);
    cout << "\nPost-order Traversal (L, R, Root): ";
    postorder(root);
    cout << "\n";

    return 0;
}
