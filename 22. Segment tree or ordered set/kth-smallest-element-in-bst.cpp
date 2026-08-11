#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Helper function to build the tree from level-order input
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
    ==================================================
    IMPLEMENTATION ONLY - PASTE THIS IN THE FUNCTION BOX
    ==================================================
*/

void findKth(TreeNode* root, int& k, int& result) {
    if (root == nullptr || k <= 0) return;

    // 1. Visit Left Subtree
    findKth(root->left, k, result);

    // 2. Process Current Node
    k--;
    if (k == 0) {
        result = root->val;
        return;
    }

    // 3. Visit Right Subtree
    findKth(root->right, k, result);
}

int kthSmallest(TreeNode* root, int k) {
    int result = -1;
    findKth(root, k, result);
    return result;
}

/*
    ==================================================
*/

int main() {
    // Optimize standard I/O operations for performance
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    int k;
    cin >> k;

    TreeNode* root = buildTree(nodes);

    cout << kthSmallest(root, k) << '\n';

    return 0;
}
