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
    void reorderList(ListNode* head) {
        int len=0;
        ListNode* temp = head;
        stack<ListNode*>s;
        while(temp)
        {
            s.push(temp);
            len++;
            temp=temp->next;
        }
        if(len<=2)
        {
            return;
        }
        temp=head;
        int c = len/2;
        while(c--)
        {
            ListNode* reff=temp;
            temp=temp->next;
            reff->next=s.top();
            s.pop();
            reff->next->next=temp;
        }
        if(temp)
        temp->next=NULL;
    }
};