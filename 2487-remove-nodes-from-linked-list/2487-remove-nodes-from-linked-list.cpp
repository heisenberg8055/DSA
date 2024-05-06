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
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = rev(head);
        ListNode* reff = temp;
        int comp = reff -> val;
        while(reff -> next)
        {
            if(reff -> next -> val < comp)
            {
                reff ->next = reff -> next -> next;
            }
            else{
                comp = reff -> next -> val;
                reff = reff -> next;
            }
        }
        return rev(temp);
    }
};