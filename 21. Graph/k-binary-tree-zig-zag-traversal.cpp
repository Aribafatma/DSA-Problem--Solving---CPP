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

// ================= STUDENT FUNCTION =======
#include <vector>
#include <queue>

/* 
// Definition for a binary tree node (for reference)
struct TreeNode {
    long long val;
    TreeNode *left;
    TreeNode *right;
};
*/

vector<vector<long long>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<long long>> result;
    if (root == nullptr) {
        return result;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    
    while (!q.empty()) {
        int size = q.size();
        vector<long long> currentLevel(size);
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            // Determine the insertion index based on current traversal direction
            int index = leftToRight ? i : (size - 1 - i);
            currentLevel[index] = node->val;
            
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        
        // Switch the direction flag for the next level
        leftToRight = !leftToRight;
        result.push_back(currentLevel);
    }
    
    return result;
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

    vector<vector<long long>> ans = zigzagLevelOrder(root);

    for (auto &level : ans) {
        for (int i = 0; i < level.size(); i++) {
            if (i) cout << " ";
            cout << level[i];
        }
        cout << '\n';
    }
}