/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int data;
 *     ListNode *next;
 *     ListNode() : data(0), next(nullptr) {}
 *     ListNode(int x) : data(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : data(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* &linkedList1, ListNode* &linkedList2) {

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int sum;
        int num;
        int carry = 0;

        while(linkedList1 != NULL || linkedList2 != NULL || carry != 0){
            sum = carry;

            if(linkedList1 != NULL) {
                sum += linkedList1->data;
                linkedList1 = linkedList1->next;
            }

            if(linkedList2 != NULL) {
                sum += linkedList2->data;
                linkedList2 = linkedList2->next;
            }

            carry = sum / 10;
            num = sum % 10;

            curr->next = new ListNode(num);
            curr = curr->next;

        }
        return dummy->next;
    }
};

//TC = O(max(n1 , n2))      n1 - no of node in 1st LL
//SC = O(max(n1 , n2))      n2 - no of node in 2nd LL
