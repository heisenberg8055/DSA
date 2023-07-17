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
        ListNode* prev = NULL, *next = NULL;
        while(head)
        {
            next = head->next;
            head->next = prev; 
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1,s2;
        ListNode* ans = new ListNode(1);
        ListNode* temp = ans;
        ListNode* l11 = l1, *l22 = l2;
        while(l11)
        {
            s1.push(l11->val);
            l11 = l11 ->next;
        }
        while(l22)
        {
            s2.push(l22->val);
            l22 = l22 ->next;
        }
        int car = 0;
        while(s1.size() || s2.size())
        {
            int val1 = 0, val2 = 0;
            if(s1.empty() == false)
            {
                val1 = s1.top();
                s1.pop();
            }
            if(s2.empty() == false)
            {
                val2 = s2.top();
                s2.pop();
            }
            int total = val1 + val2 + car;
            car = total / 10;
            total = total % 10;
            temp->next  = new ListNode(total);
            temp = temp ->next;
        }
        if(car)
        {
            temp->next = new ListNode(1);
        }
        return rev(ans->next);
    }
};