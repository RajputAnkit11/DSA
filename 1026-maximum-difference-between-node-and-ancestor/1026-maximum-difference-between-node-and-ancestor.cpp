/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    void helper(TreeNode* root, int mx, int mn)
    {
        if(root==NULL)
            return;
        
        ans=max({ans, abs(mx-root->val), abs(mn-root->val)});

        helper(root->left, max(mx, root->val), min(mn, root->val));
        helper(root->right, max(mx, root->val), min(mn, root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        ans=0;
        helper(root, root->val, root->val);
        return ans;
    }
};