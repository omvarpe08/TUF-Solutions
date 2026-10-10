/**
class ListNode
{
 * Definition for doubly-linked list.
 *  public:
 *      int data;
 *      ListNode *prev;
 *      ListNode *next;
 *      ListNode() : data(0), prev(nullptr), next(nullptr) {}
 *      ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
 *      ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};
*/

class Solution {
public:
    ListNode* insertBeforeKthPosition(ListNode* head, int X, int K) {


        if(K==1) {
            ListNode* NewNode = new ListNode(X,nullptr, head);
            head->prev = NewNode;
            return NewNode;
        }
        ListNode* temp = head;
        int cnt = 0;

        while(temp != NULL) {
            cnt++;
            if(cnt == K) {
                break;
            }

            temp = temp->next;
        }

        ListNode* NewNode = new ListNode(X,temp->prev,temp);
        temp->prev->next = NewNode;
        temp->prev = NewNode;
        return head;
    }
};