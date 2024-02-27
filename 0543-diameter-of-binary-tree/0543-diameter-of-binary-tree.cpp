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
    int dia(TreeNode* root,int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=dia(root->left,ans);
        int r=dia(root->right,ans);
        ans=max(ans,l+r);
        return 1+max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        dia(root,ans);
        return ans;
    }
};