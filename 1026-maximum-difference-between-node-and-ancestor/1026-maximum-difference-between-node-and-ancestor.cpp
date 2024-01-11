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
    int maxAncestorDiff(TreeNode* root, int mx = 0, int mn = 5002) {
        return root == NULL ? mx - mn : max(maxAncestorDiff(root->left,max(mx,root->val),min(mn,root->val)),maxAncestorDiff(root->right,max(mx,root->val),min(root->val,mn)));
    }
};