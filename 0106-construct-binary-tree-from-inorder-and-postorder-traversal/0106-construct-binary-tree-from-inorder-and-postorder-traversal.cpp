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
    TreeNode* build(vector<int>i,vector<int>p,unordered_map<int,int> &mp,int is,int ie,int ps,int pe)
    {
        if(is>ie||ps>pe)
        {
            return NULL;
        }
        int val=p[pe];
        TreeNode* ans=new TreeNode(val);
        int ind=mp[val];
        int rem=ind-is;
        ans->left=build(i,p,mp,is,ind-1,ps,ps+rem-1);
        ans->right=build(i,p,mp,ind+1,ie,ps+rem,pe-1);
        return ans;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        return build(inorder,postorder,mp,0,n-1,0,n-1);
    }
};