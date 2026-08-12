#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (nodes[i] != "null") {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < (int)nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

/*
    Implement only the function below.
    Return the sum of the values of all nodes whose value is inside the
    inclusive range [low, high].

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

long long rangeSumBST(TreeNode* root, int low, int high) {
    // Base case: if the node is empty, sum is 0
    if (root == nullptr) {
        return 0;
    }

    // Case 1: Current node value is smaller than 'low'
    // All valid values must be in the right subtree
    if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    }

    // Case 2: Current node value is larger than 'high'
    // All valid values must be in the left subtree
    if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }

    // Case 3: Current node value is within [low, high]
    // Add current value and explore both subtrees
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    int low, high;
    cin >> low >> high;

    TreeNode* root = buildTree(nodes);

    cout << rangeSumBST(root, low, high) << '\n';

    return 0;
}