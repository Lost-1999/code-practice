/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int level = 0;
    struct TreeNode* queue[2000];
    int rear = -1;
    int front = 0;
    int **arr = malloc(sizeof(int*)*2000);
    *returnColumnSizes = malloc(sizeof(int)*2000);
    if(!root){
        *returnSize = 0;
        return NULL;
    }
    queue[++rear] = root;
    while(rear >= front){
        int ColumnSize = rear - front + 1; 
        arr[level] = malloc(sizeof(int)*ColumnSize);
        for(int i=0;i<ColumnSize;i++){
            struct TreeNode *node = queue[front++];
            arr[level][i] = node->val;
            if(node->left)queue[++rear] = node->left;
            if(node->right)queue[++rear] = node->right;
        }
        (*returnColumnSizes)[level++] = ColumnSize;
    }
    *returnSize = level;
    return arr;
}