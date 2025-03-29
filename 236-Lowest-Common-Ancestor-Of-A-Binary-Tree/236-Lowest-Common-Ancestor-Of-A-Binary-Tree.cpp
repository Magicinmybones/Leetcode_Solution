TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case: if the current node is NULL, return NULL
    if(root == NULL){
        return NULL;
    }
    // If the current node is equal to p, return p
    if(root == p){
        return p;
    }
    // If the current node is equal to q, return q
    if(root == q){
        return q;
    }
    // Recur for left and right subtrees
    TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
    
    
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else if (leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    return NULL;
}