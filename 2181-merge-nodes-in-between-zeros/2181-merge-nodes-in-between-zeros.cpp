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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode(0);
        ListNode* arr=ans;
        int temp=0;
        head=head->next;
        while(head)
        {
            if(head->val==0)
            {
                ListNode* tempp=new ListNode(temp);
                arr->next=tempp;
                arr=arr->next;
                temp=0;
            }
            else
            {
                temp+=head->val;
            }
            head=head->next;
        }
        return ans->next;
    }
};