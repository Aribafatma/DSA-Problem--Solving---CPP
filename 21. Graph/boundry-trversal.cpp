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
    Return the anti-clockwise boundary traversal of the binary tree
    (root, left boundary, leaves left-to-right, right boundary).
*/

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
private:
    // Helper function to check if a node is a leaf
    bool isLeaf(TreeNode* node) {
        return (node->left == nullptr && node->right == nullptr);
    }

    // Helper function to collect all leaf nodes from left to right
    void getLeaves(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        
        if (isLeaf(node)) {
            res.push_back(node->val);
            return;
        }
        getLeaves(node->left, res);
        getLeaves(node->right, res);
    }

public:
    vector<int> boundary(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        // If the root is a leaf node, it is handled as a special case
        if (isLeaf(root)) {
            res.push_back(root->val);
            return res;
        }

        // 1. Add the root node
        res.push_back(root->val);

        // 2. Traversal for the Left Boundary (excluding leaves)
        TreeNode* curr = root->left;
        while (curr != nullptr) {
            if (!isLeaf(curr)) {
                res.push_back(curr->val);
            }
            if (curr->left != nullptr) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        // 3. Traversal for all Leaf Nodes
        getLeaves(root, res);

        // 4. Traversal for the Right Boundary (excluding leaves, in reverse order)
        vector<int> rightBoundary;
        curr = root->right;
        while (curr != nullptr) {
            if (!isLeaf(curr)) {
                rightBoundary.push_back(curr->val);
            }
            if (curr->right != nullptr) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        
        // Add right boundary nodes in reverse order
        for (int i = rightBoundary.size() - 1; i >= 0; --i) {
            res.push_back(rightBoundary[i]);
        }

        return res;
    }};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    vector<int> ans = boundary(root);

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}