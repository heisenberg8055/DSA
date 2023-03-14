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
    void trav(TreeNode* root,int temp,int &ans)
    {
        if(!root)
        {
            return;
        }
        temp=temp*10+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            ans+=temp;
        }
        trav(root->left,temp,ans);
        trav(root->right,temp,ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans=0;
        int temp=0;
        trav(root,temp,ans);
        return ans;
    }
};