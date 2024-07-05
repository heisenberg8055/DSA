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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        vector<int>temp;
        while(head){
            temp.push_back(head->val);
            head=head->next;
        }
        vector<int>reff;
        for(int i=1;i<=temp.size()-2;i++)
        {
            if(temp[i]>temp[i-1]&&temp[i]>temp[i+1]||(temp[i]<temp[i-1]&&temp[i]<temp[i+1]))
            {
                reff.push_back(i);
            }
        }
        if(reff.size()<2)
        {
            return {-1,-1};
        }
        else
        {
            int a=INT_MAX;
            for(int i=0;i<reff.size()-1;i++)
            {
                if(reff[i+1]-reff[i]<a)
                {
                    a=reff[i+1]-reff[i];
                }
            }
            ans.push_back(a);
            ans.push_back(reff[reff.size()-1]-reff[0]);
        }
        return ans;
    }
};