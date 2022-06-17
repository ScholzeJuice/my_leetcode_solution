class Solution {
public:
    int res;
    int minCameraCover(TreeNode* root) {
        res = 0;
        dfs(root);
        if(root->val==0)
            res++;
        return res;
    }
    
    void dfs(TreeNode* root){
        if(!root)
            return;
        if(!root->left && !root->right){
            root->val = 0;
            return;
        }
        bool has_leaf = false;
        if(root->left){
            dfs(root->left);
            if(root->left->val==-1)
                root->val = 1;
            if(root->left->val==0)
                has_leaf = true;
        }
        if(root->right){
            dfs(root->right);
            if(root->right->val==-1)
                root->val = 1;
            if(root->right->val==0)
                has_leaf = true;
        }
        if(has_leaf){
            res++;
            root->val = -1;
        }
    }
};
