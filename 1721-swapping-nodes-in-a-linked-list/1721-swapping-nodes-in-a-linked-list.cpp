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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        int sz = k;
        ListNode* t1 = head, *t2 = head;
        while(sz>1)
        {
            t1=t1->next;
            sz--;
        }
        int st = n-k+1;
        while(st>1)
        {
            t2=t2->next;
            st--;
        }
        swap(t1->val,t2->val);
        return head;
    }
};