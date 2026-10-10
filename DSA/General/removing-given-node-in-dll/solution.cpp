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
    void deleteGivenNode(ListNode *node) {
        
        ListNode* front = node->next;
        ListNode* back = node->prev;

        if(front == NULL) {
            back->next = NULL;
            node->prev = NULL;
            free(node);
            return ;
        }

        back->next = front;
        front->prev = back;

        node->next = node->prev = NULL;
        free(node);

    }
};