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
        ListNode* deleteKthNode(ListNode* &head, int k) {
            int cnt = 0;
            ListNode* temp = head;
            ListNode* prev = nullptr;

            if(head == NULL) {
                return NULL;
            }

            if(k == 1) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
                
                return head;
            }

            while(temp != NULL) {
                cnt++;
                if(cnt == k) {
                    prev->next = temp->next;
                    delete temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }

            return head;
        }
};
