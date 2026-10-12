/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {

            ListNode* zeroHead = new ListNode(0);
            ListNode* zero = zeroHead;

            ListNode* oneHead = new ListNode(0);
            ListNode* one = oneHead;

            ListNode* twoHead = new ListNode(0);
            ListNode* two = twoHead;

            ListNode* temp = head;

            while(temp != NULL) {

                if(temp->data == 0) {
                    zero->next = temp;
                    zero = zero->next;
                }

                else if(temp->data == 1) {
                    one->next = temp;
                    one = one->next;
                }

                else {
                    two->next = temp;
                    two = two->next;
                }

                temp = temp->next;
            }

            zero->next = oneHead->next ? oneHead->next : twoHead->next;   
             //...condn like this bcoz there maynot one sometime

            one->next = twoHead->next;

            two->next = NULL;

            ListNode* newHead = zeroHead->next;

            delete zeroHead;
            delete oneHead;
            delete twoHead;

            return newHead;

        }
};

//TC = O(N)
//SC = O(1)