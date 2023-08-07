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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans = head;
        if(ans ->next == NULL)
        {
            return ans;
        }
        ListNode* f = head;
        ListNode* s = head->next;
        while(s)
        {
            ListNode* temp = new ListNode(__gcd(f->val, s->val),s);
            f->next = temp;
            f = s;
            s = s->next;
        }
        return ans;
    }
};