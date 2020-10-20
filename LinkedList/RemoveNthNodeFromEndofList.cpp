//Given the head of a linked list, write a function to remove the nth node from the end of the list and return its head

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
            //if only one element
        if(head->next == NULL && n==1){
            return NULL;
        }
                
        int x=0;
        ListNode* curr = head;  
        ListNode* prev = head;
        
        if(n==1){
            while(curr->next->next){
                curr=curr->next;
            }
            curr->next = NULL;
            return head;
        }
        
    
        while(x<n-1 && curr->next){
            ++x;
            curr = curr->next;
        }
        
        while(curr->next){
            
            curr = curr->next;
            prev = prev->next;
        }

        prev->val = prev->next->val;
        prev->next = prev->next->next;
        
        return head;       
        
        
    }
};
