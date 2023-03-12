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
    int getsize(ListNode* head)
    {
        int size = 0;
        ListNode* temp = head;
        while(temp)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
    
    bool reverse(ListNode* head)
    {
        int llsize = getsize(head), revsize = llsize / 2;
        ListNode *prev = NULL, *temp = head,*tempnext = head->next;
        while(revsize)
        {
            revsize--;
            tempnext = temp->next;
            temp->next = prev;
            prev = temp;
            // temp = tempnext;
            // tempnext = tempnext->next;
            temp = tempnext;
             // This is the way they do... so can put while(temp) in place of tempnext in condition
        }
        
        // req reversing is done...
        // lemme just check for palin
        // prev is at start of 1st part. temp/tempnext is at start of 2nd part
        int flag = 1;
        if(llsize % 2 == 1) temp = temp->next;
        while(temp && prev)
        {
            if(temp->val != prev->val) flag = 0;
            temp = temp->next;
            prev = prev->next;
        }
        
        if(flag == 1) return true;
        else return false;
    }
    
    bool isPalindrome(ListNode* head) {
        return reverse(head);

    }
};