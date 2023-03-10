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
    int len;
    ListNode* dhead;
public:
    Solution(ListNode* head) {
        len=0;
        dhead=head;
        while(head!=NULL)
        {
            head=head->next;
            len++;
        }
    }
    
    int getRandom() {
        int nu=rand()%len;
        ListNode* ans=dhead;
        while(nu>0)
        {
            nu--;
            ans=ans->next;
        }
        return ans->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */