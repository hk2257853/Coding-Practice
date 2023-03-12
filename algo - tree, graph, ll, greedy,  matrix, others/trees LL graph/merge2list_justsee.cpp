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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp1 = list1, *temp2 = list2, *NewHead = NULL, *tempnew;
        while(temp1 && temp2)
        {
            ListNode *newNode = new ListNode;
            newNode->next = NULL;
            
            if(temp1->val < temp2->val)
            {
                newNode->val = temp1->val;
                temp1 = temp1->next;
            }
            else
            {
                newNode->val = temp2->val;
                temp2 = temp2->next;
            }
            
            if(!NewHead)
            {
                NewHead = newNode;
                tempnew = NewHead;
            }
            else
            {
                tempnew->next = newNode;
                tempnew = tempnew->next;
            }
        }
        
        tempnew->next = temp1 ? temp1 : temp2;
        
        // I wrote the below faltu code that could have been done in above 1 line...
        // while(temp1)
        // {
        //     ListNode *newNode = new ListNode;
        //     newNode->next = NULL;
        //     newNode->val = temp1->val;
        //     temp1 = temp1->next;
        //     if(!NewHead)
        //     {
        //         NewHead = newNode;
        //         tempnew = NewHead;
        //     }
        //     else
        //     {
        //         tempnew->next = newNode;
        //         tempnew = tempnew->next;
        //     }
        // }
        
        // while(temp2)
        // {
        //     ListNode *newNode = new ListNode;
        //     newNode->next = NULL;
        //     newNode->val = temp2->val;
        //     temp2 = temp2->next;
        //     if(!NewHead)
        //     {
        //         NewHead = newNode;
        //         tempnew = NewHead;
        //     }
        //     else
        //     {
        //         tempnew->next = newNode;
        //         tempnew = tempnew->next;
        //     }
        // }
        
        return NewHead;        
    }
};

// After looking at dicussion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp1 = list1, *temp2 = list2, *NewHead = NULL, *tempnew;
        while(temp1 && temp2)
        {
            ListNode *newNode = new ListNode;
            newNode->next = NULL;
            
            if(temp1->val < temp2->val)
            {
                newNode->val = temp1->val;
                temp1 = temp1->next;
            }
            else
            {
                newNode->val = temp2->val;
                temp2 = temp2->next;
            }
            
            if(!NewHead)
            {
                NewHead = newNode;
                tempnew = NewHead;
            }
            else
            {
                tempnew->next = newNode;
                tempnew = tempnew->next;
            }
        }
        
        if(!NewHead) NewHead = temp1 ? temp1 : temp2;
        else tempnew->next = temp1 ? temp1 : temp2;

        return NewHead;        
    }
};