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
private:
    ListNode* rev(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(curr)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = rev(head);
        ListNode* reff = temp;
        int c = 0;
        while(temp)
        {
            int val = temp -> val * 2;
            val += c;
            temp -> val = val % 10;
            c = val / 10;
            temp  = temp -> next;
        }
        return c ? new ListNode(c, rev(reff)) : rev(reff);
    }
};