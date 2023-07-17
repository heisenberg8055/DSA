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
    ListNode* reverse(ListNode* root)
    {
        ListNode* prev = NULL, *next = NULL;
        while(root)
        {
            next = root->next;
            root->next = prev;
            prev = root;
            root = next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int car = 0;
        ListNode* ans = new ListNode(1);
        ListNode* temp = ans;
        while(l1 || l2)
        {
            int v1 = 0,v2 = 0;
            if(l1)
            {
                v1 = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                v2 = l2->val;
                l2 = l2->next;
            }
            int total = v1 + v2 + car;
            car = total / 10;
            total = total % 10;
            temp->next = new ListNode(total);
            temp = temp->next;
        }
        if(car)
        {
            temp->next = new ListNode(1);
        }
        return reverse(ans->next);
    }
};