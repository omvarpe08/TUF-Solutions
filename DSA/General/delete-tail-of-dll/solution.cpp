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
    ListNode *deleteTail(ListNode *&head) {

        if(head->next == nullptr) {
            delete head;
            return nullptr;
        }
        ListNode* tail = head;

        while(tail->next != nullptr) {
            tail = tail->next;
        }
        tail->prev->next = nullptr;
        tail->prev = nullptr;
        delete tail;
        return head;
    }
};