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
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
        {
            return head;
        }
        int p = left - 1;
        int nex = right + 1;
        ListNode* first = new ListNode();
        first->next = head;
        int n = 0;
        ListNode* temp = first;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* l = nullptr;
        ListNode* r = nullptr;
        while(temp)
        {
            if(n == p)
            {
                prev = temp;
            }
            else if(n == left)
            {
                l = temp;
            }
            else if(n == right)
            {
                r = temp; 
            }
            else if(n == nex)
            {
                next = temp;
            }
            n++;
            temp = temp->next;
        }
        r->next = nullptr;
        ListNode* last = rev(l);
        prev->next = last;
        l->next = next;
        return first->next;
    }
};