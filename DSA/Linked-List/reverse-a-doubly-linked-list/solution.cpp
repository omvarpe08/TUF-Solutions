/*
class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
*/

class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {

        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* current = head;
        ListNode* back = NULL;
        
        while(current != nullptr) {
            back = current->prev;

            current->prev = current->next;
            current->next = back;
            
            current = current->prev;
            
        }
        return back->prev;

    }
};