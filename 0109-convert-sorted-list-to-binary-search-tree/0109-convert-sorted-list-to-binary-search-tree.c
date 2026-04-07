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

    struct ListNode* slow = head;
    struct ListNode* fast = head->next->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* mid = slow->next;
    slow->next = NULL; 

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left  = sortedListToBST(head);    
    root->right = sortedListToBST(mid->next); 
    return root;
}