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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
        {
            if (headA == headB)
            {
                return headA;
            }
            if (!headA || !headB)
            {
                return nullptr;
            }
    
            ListNode* listA = headA;
            ListNode* listB = headB;
            ListNode* tempA = listA;
            ListNode* tempB = listB;
            int lenA = 0;
            int lenB = 0;
    
            while (tempA != nullptr)
            {
                ++lenA;
                tempA = tempA->next;
    
            }
            while (tempB != nullptr)
            {
                ++lenB;
                tempB = tempB->next;
            }
            if (lenA > lenB)
            {
                int difference = lenA - lenB;
                while (listA != nullptr && difference > 0)
                {
                    listA = listA->next;
                    --difference;
                }
            }
            else
            {
                int difference = lenB - lenA;
                while (listB != nullptr && difference > 0)
                {
                    listB = listB->next;
                    --difference;
                }
            }
            while (listA != nullptr && listB != nullptr)
            {
                if (listA == listB)
                    return listA;
                listA = listA->next;
                listB = listB->next;
            }
    
            return nullptr;
        }
    };