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
    long long val; // or int val, standard type
    TreeNode *left;
    TreeNode *right;
};
*/

long long minOfTree(TreeNode* root) {
    // If the entire tree is empty, the problem specifies to return 0
    if (!root) return 0;

    long long min_val = root->val;

    // Only traverse existing children to avoid mixing 0 from empty subtrees
    if (root->left) {
        min_val = std::min(min_val, minOfTree(root->left));
    }
    if (root->right) {
        min_val = std::min(min_val, minOfTree(root->right));
    }

    return min_val;
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

    cout << minOfTree(root) << '\n';
}