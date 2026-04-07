/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head) return NULL;
    if (!head->next) {
        struct TreeNode* node = malloc(sizeof(struct TreeNode));
        node->val = head->val;
        node->left = node->right = NULL;
        return node;
    }

    // Tìm node giữa bằng slow/fast pointer
    struct ListNode* slow = head;
    struct ListNode* fast = head->next->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow->next là mid (root)
    struct ListNode* mid = slow->next;
    slow->next = NULL; // Cắt đôi list

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left  = sortedListToBST(head);     // nửa trái
    root->right = sortedListToBST(mid->next); // nửa phải
    return root;
}