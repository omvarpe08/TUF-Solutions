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
            ListNode* zero = new ListNode(0);
            ListNode* zeroHead = zero;
            ListNode* one = new ListNode(0);
            ListNode* oneHead = one;
            ListNode* two = new ListNode(0);
            ListNode* twoHead = two;

            ListNode* temp = head;

            while(temp != NULL) {

                ListNode* newNode = temp->next;
                temp->next = nullptr;
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
                temp = newNode;
            }
            zero->next = oneHead->next ? oneHead->next : twoHead->next;    //...condn like this bcoz there maynot one sometime
            one->next = twoHead->next;

            return zeroHead->next;

        }
};