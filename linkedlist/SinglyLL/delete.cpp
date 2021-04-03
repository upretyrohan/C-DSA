#include <stdio.h>

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow)
            {
                return slow;
            }
        }
        
        return NULL;
    }
};

int main()
{
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next= new ListNode(0);
    head->next->next->next= new ListNode(-4);
    head->next->next->next->next= head->next;

    Solution* obj = new Solution();
    obj->detectCycle(head);
}