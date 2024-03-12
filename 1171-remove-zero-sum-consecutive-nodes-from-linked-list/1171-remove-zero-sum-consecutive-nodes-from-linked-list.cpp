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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = new ListNode(0, head);
        ListNode* reff = temp;
        int preS = 0;
        unordered_map<int, ListNode*>mp;
        while(reff)
        {
            preS += reff->val;
            mp[preS] = reff;
            reff = reff -> next;
        }
        preS = 0;
        reff = temp;
        while(reff)
        {
            preS += reff -> val;
            reff -> next = mp[preS] -> next;
            reff = reff -> next;
        }
        return temp -> next;
    }
};