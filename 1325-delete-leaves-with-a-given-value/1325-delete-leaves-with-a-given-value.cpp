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
private:
    TreeNode* dfs(TreeNode* root, int target)
    {
        if(root == NULL)
        {
            return NULL;
        }
        TreeNode* left = dfs(root -> left, target);
        TreeNode* right = dfs(root -> right, target);
        if(left == nullptr && right == nullptr && root -> val == target)
        {
            return nullptr;
        }
        return new TreeNode(root -> val, left, right);
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
};