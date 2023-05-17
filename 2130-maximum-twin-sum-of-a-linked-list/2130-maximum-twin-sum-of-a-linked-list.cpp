/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>ans;
        int temp=0;
        while(head)
        {
            ans.push_back(head->val);
            head=head->next;
        }
        for(int i=0;i<(ans.size()/2);i++)
        {
            int sum=ans[i]+ans[ans.size()-i-1];
            temp=max(sum,temp);
        }
        return temp;
    }
};