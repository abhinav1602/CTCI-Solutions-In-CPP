// structure of a node
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 // Height will be minimal if we create the tree in BST format
TreeNode* returnBST(vector<int> &a, int s, int e){
      if(s>e)
        return NULL;

      int m = ceil(((float)s+(float)e)/2.0);
      TreeNode *root = new TreeNode(a[m]);
      root->left = returnBST(a, s, m-1);
      root->right = returnBST(a, m+1, e);
      return root;
  }


TreeNode* sortedArrayToBST(vector<int> &a) {
    int n = a.size();
    return returnBST(a, 0, n-1);
}
