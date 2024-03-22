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
    bool isPalindrome(ListNode* head) {
        ListNode* s = head, *f = head;
        while(f && f -> next)
        {
            s = s -> next;
            f = f -> next -> next;
        }
        ListNode* prev = s,*next;
        s = s -> next;
        prev -> next = nullptr;
        while(s)
        {
            next = s -> next;
            s -> next = prev;
            prev = s;
            s = next;
        }
        f = head;
        while(prev != nullptr)
        {
            if(f -> val != prev -> val)
            {
                return false;
            }
            prev = prev -> next;
            f = f -> next;
        }
        return true;
    }
};