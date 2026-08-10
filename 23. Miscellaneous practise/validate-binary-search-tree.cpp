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

// Helper function to validate node values within a specific range
bool validate(TreeNode* node, long long min_val, long long max_val) {
    // An empty tree/node is valid
    if (node == nullptr) {
        return true;
    }
    
    // The current node's value must be strictly within the min and max limits
    if (node->val <= min_val || node->val >= max_val) {
        return false;
    }
    
    // Recursively check subtrees
    return validate(node->left, min_val, node->val) && 
           validate(node->right, node->val, max_val);
}

// Global validation function called by main
bool isValidBST(TreeNode* root) {
    // Initialize the range with values outside the 32-bit signed integer limits
    return validate(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    bool ans = isValidBST(root);

    cout << (ans ? "true" : "false") << '\n';

    return 0;
}
