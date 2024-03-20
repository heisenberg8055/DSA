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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list2;
        while(temp -> next)
        {
            temp = temp->next;    
        }
        ListNode* trav = list1;
        int cnt = 1;
        while(cnt != a)
        {
            trav = trav -> next;
            cnt++;
        }
        ListNode* trav1 = trav;
        
        b+=2;
        while(cnt != b)
        {
            trav1 = trav1 -> next;
            cnt++;
        }
        trav->next = list2;
        temp -> next = trav1;
        return list1;
    }
};