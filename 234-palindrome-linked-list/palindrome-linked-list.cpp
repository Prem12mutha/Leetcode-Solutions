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

ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;   // save next
            curr->next = prev;   // reverse link
            prev = curr;         // move prev forward
            curr = next;         // move curr forward
        }
        return prev; // new head of reversed list
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = slow;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* secondhalf = reverseList(slow->next);

        ListNode* p1 = head;
        ListNode* p2 = secondhalf;

        bool palindrome = true;
        while(p2 != NULL){
            if(p1->val != p2->val){
                palindrome = false;
                break;
            }
            p1= p1->next;
            p2 = p2->next;
        }

        slow->next = reverseList(secondhalf);

        return palindrome;
    }
};