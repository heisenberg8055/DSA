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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp = head;
        int n = 0;
        while(temp)
        {
            temp = temp->next;
            n++;
        }
        int per = n/k;
        int ex = n%k;
        int i = 0;
        temp = head;
        while(i<k)
        {
            ListNode* reff = new ListNode();
            ListNode* trav = reff;
            int r = per;
            while(r)
            {
                trav->next = new ListNode(temp->val);
                trav = trav->next;
                temp = temp->next;
                r--;
            }
            if(ex)
            {
                trav->next = new ListNode(temp->val);
                temp = temp->next;
                ex--;
            }
            ans.push_back(reff->next);
            i++;
        }
        return ans;
    }
};