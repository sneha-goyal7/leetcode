/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    ListNode* delNode = node->next;
    node->val = delNode->val;
    node->next = delNode->next;
    delNode->next = NULL;
    delete delNode;
    }
};