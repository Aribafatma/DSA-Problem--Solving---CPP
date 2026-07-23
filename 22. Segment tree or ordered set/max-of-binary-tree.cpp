#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    long long val;
    TreeNode *left, *right;
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoll(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (nodes[i] != "null") {
            cur->left = new TreeNode(stoll(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoll(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

// ================= STUDENT FUNCTION =================
/*
Definition for a binary tree node handled by the template:
struct TreeNode {
    long long val;
    TreeNode *left;
    TreeNode *right;
};
*/

long long maxOfTree(TreeNode* root) {
    // If the entire tree is empty, return 0 as requested
    if (!root) return 0;

    long long max_val = root->val;

    // Check left subtree if it exists
    if (root->left) {
        max_val = std::max(max_val, maxOfTree(root->left));
    }
    
    // Check right subtree if it exists
    if (root->right) {
        max_val = std::max(max_val, maxOfTree(root->right));
    }

    return max_val;
}

// ====================================================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    cout << maxOfTree(root) << '\n';
}