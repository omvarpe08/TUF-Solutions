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
    ListNode* insertBeforeTail(ListNode* head, int X) {

        if(head->next == NULL) {
            ListNode* NewNode = new ListNode(X,nullptr,head);
            head->prev = NewNode;
            return NewNode;
        }
        ListNode* temp = head;

        while(temp->next != NULL) {
            temp= temp->next;
        }
        
        ListNode* NewNode = new ListNode(X,temp->prev,temp);
        temp->prev->next = NewNode;
        temp->prev = NewNode;

        return head;

        

    }
};
