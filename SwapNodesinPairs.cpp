#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
ListNode * swapPairs(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;                //空、1
    
    ListNode *p1(head), *p2(head->next), *newHead(head->next);
    p1->next = p2->next;
    p2->next = p1;
    if (p1->next == NULL || p1->next->next == NULL) return newHead;     //1->2、1->2->3
    p2 = p2->next->next->next;                                          //2->1->3->4，p1指向1，p2指向4
    while (1) {
        p1->next->next = p2->next;                                      //p1的后继（3）的后继是p2的后继
        p2->next = p1->next;                                            //p2的后继是p1的后继（3）
        p1->next = p2;                                                  //p1的后继是p2
        p1 = p1->next->next;                                            //p1指向3
        if (p1->next == NULL || p1->next->next == NULL)                 //2->1->4->3
            break;
        p2 = p2->next->next->next;
    }
    return newHead;
}
int main() {
    auto head = new ListNode(1);
    auto node1 = new ListNode(2);
    head->next = node1;
    auto node2 = new ListNode(3);
    node1->next = node2;
    auto node3 = new ListNode(4);
    node2->next = node3;
    auto newHead = swapPairs(head);
    while (newHead != NULL) {
        cout << newHead->val;
        newHead = newHead->next;
    }
    return 0;
}
