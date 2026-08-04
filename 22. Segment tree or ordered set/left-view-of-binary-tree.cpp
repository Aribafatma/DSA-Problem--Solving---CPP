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
vector<long long> leftView(TreeNode* root) {
    vector<long long> result;
    
    // If the tree is empty, return an empty vector
    if (root == nullptr) {
        return result;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int level_size = q.size();
        
        for (int i = 0; i < level_size; i++) {
            TreeNode* current = q.front();
            q.pop();
            
            // The first element of the current level belongs to the left view
            if (i == 0) {
                result.push_back(current->val);
            }
            
            // Push child nodes into the queue for the next level
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
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

    vector<long long> ans = leftView(root);

    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << '\n';
}