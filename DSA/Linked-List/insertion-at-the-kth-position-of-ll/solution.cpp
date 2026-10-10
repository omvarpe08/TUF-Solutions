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
        ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {

            if(head == NULL) {
                return new ListNode(X);
            }
            if(K==1) {
                ListNode* NewNode = new ListNode(X);
                NewNode->next = head;
                return NewNode;

                //or
                //return new ListNode(X,head);
            }
            int cnt = 0;

            ListNode* temp = head;

            while(temp != NULL){
                cnt++;

                if(cnt == K-1) {
                    ListNode* NewNode = new ListNode(X);
                    NewNode->next = temp->next;
                    temp->next = NewNode;
                    break;

                }
                temp = temp->next;
            }
            return head;
        }
};