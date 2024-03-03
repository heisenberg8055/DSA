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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode(0);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        start->next=head;
        ListNode* f=start;
        ListNode* s=start;
        for(int i=0;i<n;i++)
        {
            f=f->next;
        }
        while(f->next!=NULL)
        {
            f=f->next;
            s=s->next;
        }
        s->next=s->next->next;
        return start->next;
    }
};