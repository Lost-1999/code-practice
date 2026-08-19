/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    if(root == NULL)return 0;
    int Depth = 1;
    int leftDepth = 0,rightDepth = 0;
    if(root->left)leftDepth = maxDepth(root->left);
    if(root->right)rightDepth = maxDepth(root->right);
    Depth += leftDepth > rightDepth ? leftDepth : rightDepth;
    return Depth;
}