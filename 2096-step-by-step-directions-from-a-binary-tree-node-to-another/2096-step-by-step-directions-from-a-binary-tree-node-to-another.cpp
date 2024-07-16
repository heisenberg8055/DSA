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
    TreeNode* lca(TreeNode* root,int u,int v)
    {   
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==u||root->val==v)
        {
            return root;
        }
        TreeNode* l=lca(root->left,u,v);
        TreeNode* r=lca(root->right,u,v);
        if(l&&r)
        {
            return root;
        }
        if(l)
        {
            return l;
        }
        if(r)
        {
            return r;
        }
        return NULL;
    }
    bool findPath(TreeNode* root,string &s,int t)
    {
        if(root->val==t)
        {
            return true;
        }
        if(root->left&&findPath(root->left,s,t)==true)
        {
            s+='L';
            return true;
        }
        if(root->right&&findPath(root->right,s,t)==true)
        {
            s+='R';
            return true;
        }
        return false;
    }
public:
    string getDirections(TreeNode* root, int s, int d) {
        string ans="";
        TreeNode* ances=lca(root,s,d);
        string l="";
        string r="";
        findPath(ances,l,s);
        findPath(ances,r,d);
        for(int i=0;i<l.size();i++)
        {
            l[i]='U';
        }
        reverse(r.begin(),r.end());
        ans=l+r;
        return ans;
    }
};