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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int q = 0;
        ListNode* ans = new ListNode;
        ListNode* temp = ans;
        
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                temp->val = (l2->val + q) % 10;
                q = (l2->val + q) / 10;
                if (l2->next == nullptr) {
                    break;
                }
                l2 = l2->next;
                temp->next = new ListNode;
                temp = temp->next;
                continue;
                
            }
            if (l2 == nullptr) {
                temp->val = (l1->val + q) % 10;
                q = (l1->val + q) / 10;
                if (l1->next == nullptr) {
                    break;
                }
                l1 = l1->next;
                temp->next = new ListNode;
                temp = temp->next;
                continue;
            }
            
            temp->val = (l1->val + l2->val + q) % 10;
            q = (l1->val + l2->val + q) / 10;
            if (l2->next == nullptr && l1->next == nullptr) {
                break;
            }
            temp->next = new ListNode;
            temp = temp->next;
            l2 = l2->next;
            l1 = l1->next;
        }
        if (q != 0) {
            temp->next = new ListNode;
            temp = temp->next;
            temp-> val = q;
        }
        return ans;
    }
};