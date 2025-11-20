#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    char data;
    vector<TreeNode*> children;
};

TreeNode* createNode(char val) {
    TreeNode* node = new TreeNode();
    node->data = val;
    return node;
}

void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    for (auto child : root->children) {
        preorder(child);
    }
}

void postorder(TreeNode* root) {
    if (root == nullptr) return;
    for (auto child : root->children) {
        postorder(child);
    }
    cout << root->data << " ";
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    if (!root->children.empty()) inorder(root->children[0]);
    cout << root->data << " ";
    for (int i = 1; i < root->children.size(); i++) {
        inorder(root->children[i]);
    }
}

bool searchData(TreeNode* root, char key) {
    if (root == nullptr) return false;

    if (root->data == key) {
        cout << key << " was found!" << endl;
        return true;
    }

    for (auto child : root->children) {
        if (searchData(child, key))
            return true;
    }
    return false;
}

int main() {
    TreeNode* A = createNode('A');
    TreeNode* B = createNode('B');
    TreeNode* C = createNode('C');
    TreeNode* D = createNode('D');
    TreeNode* E = createNode('E');
    TreeNode* F = createNode('F');
    TreeNode* G = createNode('G');
    TreeNode* H = createNode('H');
    TreeNode* I = createNode('I');
    TreeNode* J = createNode('J');
    TreeNode* K = createNode('K');
    TreeNode* L = createNode('L');
    TreeNode* M = createNode('M');
    TreeNode* N = createNode('N');
    TreeNode* P = createNode('P');
    TreeNode* Q = createNode('Q');
    TreeNode* O = createNode('O'); // new leaf

    A->children = {B, C, D, E, F, G};
    D->children = {H};
    E->children = {I, J};
    J->children = {P, Q};
    F->children = {K, L, M};
    G->children = {N, O}; // new child added to G

    cout << "Pre-order Traversal: ";
    preorder(A);

    cout << "\nPost-order Traversal: ";
    postorder(A);

    cout << "\nIn-order Traversal: ";
    inorder(A);

    // Search for node O
    cout << "\n\nSearching for node O..." << endl;
    searchData(A, 'O');

    return 0;
}
