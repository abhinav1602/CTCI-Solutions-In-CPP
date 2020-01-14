// return height of each node and if height is not balanced return INT_MAX and carry it upwards
int height(TreeNode* node) {
    if(node == NULL)
        return -1;

    int left = height(node->left);

    // if any child is not balanced carry INT_MAX up
    if(left == INT_MAX)
        return INT_MAX;

    int right = height(node->right);

    // if any child is not balanced carry INT_MAX up
    if(right == INT_MAX)
        return INT_MAX;

    int diff = left - right;
    if(abs(diff) > 1)
        return INT_MAX;
    else
        return max(left, right)+1;
}

// if INT_MAX is carried from any node to root node then tree is not balanced
bool isBalanced(TreeNode* root) {
    return height(root) != INT_MAX;
}
