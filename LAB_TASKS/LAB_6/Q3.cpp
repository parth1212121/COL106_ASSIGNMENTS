/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



// LeetCode_Template.....





class Solution {
public:
void inorder(vector<TreeNode*> &v,TreeNode* root){  
       if(root==NULL){
            return ;
        }
        inorder(v,root->left);
        v.push_back(root);
        inorder(v,root->right);
    }

void sumt(TreeNode* root,map<TreeNode*,int> &mp){

        if(root==NULL){
            mp[root]=0;
            return ;
        }
        sumt(root->left,mp);
        sumt(root->right,mp);
        mp[root]=((root->val)+ mp[root->left] +mp[root->right]);     
        
}

void mini(TreeNode* root,map<TreeNode*,int>&mp_min){

    if(root->right==NULL && root->left==NULL){
     
        mp_min[root]=root->val;
        return;
    }
    else if(root->right==NULL && !(root->left==NULL)){
        mini(root->left,mp_min);
        mp_min[root]=min(mp_min[root->left],root->val);
        return;
    }
    else if(!(root->right==NULL) && root->left==NULL){
        mini(root->right,mp_min);
        mp_min[root]=min(mp_min[root->right],root->val);
        return;
    }
    else{
        mini(root->left,mp_min);
        mini(root->right,mp_min);
        mp_min[root]=min(mp_min[root->left],mp_min[root->right]);
        mp_min[root]=min(mp_min[root],root->val);
        return;
    }

}

void maxi(TreeNode* root,map<TreeNode*,int>&mp_max){

    if(root->right==NULL && root->left==NULL){
        mp_max[root]=root->val;
        return;
    }
    else if(root->right==NULL && !(root->left==NULL)){
        maxi(root->left,mp_max);
        mp_max[root]=max(mp_max[root->left],root->val);
        return;
    }
    else if(!(root->right==NULL) && root->left==NULL){
        maxi(root->right,mp_max);
        mp_max[root]=max(mp_max[root->right],root->val);
        return;
        

    }
    else{
        maxi(root->left,mp_max);
        maxi(root->right,mp_max);
        mp_max[root]=max(mp_max[root->left],mp_max[root->right]);
        mp_max[root]=max(mp_max[root],root->val);
        return;
    }

}


void BST(TreeNode* root,map<TreeNode*,bool>&is_bst,map<TreeNode*,int>&mp_max,map<TreeNode*,int>&mp_min){

        if(root==NULL){
            is_bst[root]=true;
            return;
        }
        else if(root->right==NULL && (root->left==NULL)){
            is_bst[root]=true;
            return;
        }
        else if(root->right==NULL && !(root->left==NULL)){
            BST(root->left,is_bst,mp_max,mp_min);
            if((root->val>mp_max[root->left])&& is_bst[root->left]){
                is_bst[root]=true;
                
            }

        }
        else if(root->left==NULL && !(root->right==NULL)){
            BST(root->right,is_bst,mp_max,mp_min);
            if((root->val<mp_min[root->right])&& is_bst[root->right]){
                is_bst[root]=true;
                return;
            }
        }
        else{
            BST(root->left,is_bst,mp_max,mp_min);
            BST(root->right,is_bst,mp_max,mp_min);
            if((root->val>mp_max[root->left])&& is_bst[root->left] && (root->val<mp_min[root->right])&& is_bst[root->right]){
                is_bst[root]=true;
                return;
            }
        }

}



// bool bst(TreeNode* root,map<TreeNode*,int>&mp_max,map<TreeNode*,int>&mp_min) {
//     if(root==NULL){
//         return true;
//     }
//     else if(root->right==NULL){
//         if(root->val>mp_max[root->left]){

//             return true;
//         }
//         return false;
//     }
//     else if(root->left==NULL){
//         if(root->val<mp_min[root->right]){
//             return true;
//         }
//         return false;
//     }
//     else if(root->val>mp_max[root->left] && root->val<mp_min[root->right] ){
//         return true;
//     }
//     else{
//         return false;
//     }
// }


int maxtr(TreeNode* root,int sum,map<TreeNode*,int> &mp,map<TreeNode*,int>&mp_max,map<TreeNode*,int>&mp_min){
    
    if(is_bst[root] || root==NULL){
        if(root!=NULL){
        int j= (max(maxtr(root->left,mp[root->left],mp,mp_max,mp_min),maxtr(root->right,mp[root->right],mp,mp_max,mp_min)));
        j=max(j,0);
        return max(mp[root],j);
        }
        else{
        return mp[root];}
    }
    else{

        int j= (max(maxtr(root->left,mp[root->left],mp,mp_max,mp_min),maxtr(root->right,mp[root->right],mp,mp_max,mp_min)));
        return max(j,0);
        
    }

}
map<TreeNode*,int>mp;
map<TreeNode*,int>mp_max;
map<TreeNode*,int>mp_min;
map<TreeNode*,bool>is_bst;

    int maxSumBST(TreeNode* root) {
        
        sumt(root,mp);
        maxi(root,mp_max);
        mini(root,mp_min);
        BST(root,is_bst,mp_max,mp_min);

        return maxtr(root,mp[root],mp,mp_max,mp_min);      
    }

};
