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
    pair<int,int> trav(TreeNode* root, int &ans){
        if(root == NULL)
        {
            return {0,0};
        }
        int sum = 0;
        auto itl = trav(root->left, ans);
        auto itr = trav(root->right, ans);
        int sl = itl.first;
        int sr = itr.first;
        int cl = itl.second;
        int cr = itr.second; 
        sum = sl + sr + root->val;
        int count = cl + cr + 1;
        ans += (sum/count) == root->val;
        return {sum,count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        int count = 0;
        trav(root, ans);
        return ans;
    }
};