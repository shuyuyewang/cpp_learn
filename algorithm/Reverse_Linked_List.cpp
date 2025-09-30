/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        //prev -> cur -> next
        while (cur != nullptr) {
            ListNode* next = cur -> next; // 暂存
            cur -> next = prev;           // 翻转指针
            prev = cur;                 // prev 前进
            cur = next;                 // cur 前进
        }

        return prev; // 新的头节点
    }
};