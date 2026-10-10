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
    ListNode *deleteKthElement(ListNode *&head, int k) {

        if(head == nullptr) {
            return nullptr;
        }
        
        ListNode* temp = head;
        int cnt = 0;

        while(temp != nullptr) {
            cnt++;
            if(cnt == k) {
                break;
            }
            temp = temp->next;
        } 

        ListNode* front = temp->next;
        ListNode* back = temp->prev;

        if(front == nullptr && back == nullptr) {
            delete head;
            return nullptr;
        }

        else if(front == nullptr) {
            back->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            return head;
        }
        else if(back == nullptr) {
            ListNode* temp = head->next;
            temp->prev= nullptr;
            delete head;
            return temp;
        }

        back->next = front;
        front->prev = back;

        temp->next = nullptr;
        temp->prev = nullptr;
        
        delete temp;

        return head;
    }
};