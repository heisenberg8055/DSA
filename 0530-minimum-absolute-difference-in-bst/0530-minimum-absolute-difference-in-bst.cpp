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
    int val = -1;
    void bst(TreeNode* root, int &ans)
    {
        if(root == NULL)
        {
            return;
        }
        bst(root->left, ans);
        if(val == -1)
        {
            val = root->val;
        }
        else
        {
            ans = min(ans, root->val - val);
        }
        val = root->val;
        bst(root->right, ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        bst(root, ans);
        return ans;
    }
};