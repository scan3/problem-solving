/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL)
            return l2;
        if (l2==NULL)
            return l1;
        
        ListNode* ret;
        ListNode* prev;
        
        if (l1->val < l2->val) {
            ret = l1;
            prev = l1;
            l1 = l1->next;
        } else {
            ret = l2;
            prev = l2;
            l2 = l2->next;
        }
        
        ListNode* tmp;
        while (l1!=NULL || l2!=NULL) {
            if (l1==NULL) {
                prev->next = l2;
                return ret;
            }
            if (l2==NULL) {
                prev->next = l1;
                return ret;
            }
                
            if (l1->val == prev->val) {
                prev->next = l1;
                prev = prev->next;
                l1 = l1->next;
                continue;
            }
            if (l2->val == prev->val) {
                prev->next = l2;
                prev = prev->next;
                l2 = l2->next;    
                continue;
            }
            if (l1->val < l2->val) {
                prev->next = l1;
                prev = prev->next;
                
                l1 = l1->next;
                continue;
            } else {
                prev->next = l2;
                prev = prev->next;
                l2 = l2->next;
            }
        }
        return ret;
    }
};
