void inorder(vector<Node*> &v,Node* root){   // Hacker_Rank_temp.
       if(root==NULL){
            return ;
        }
        inorder(v,root->left);
        v.push_back(root);
        inorder(v,root->right);
    }
    
	bool checkBST(Node* root) {
        
        vector<Node*>ino;
        inorder(ino,root);
     
        vector<Node*>cor;
        for(int i=0;i<ino.size();i++){
            if(ino[i]){
                cor.push_back(ino[i]);
            }
}
        bool ans=true;
        for(int i=0;i<cor.size()-1;i++){
            if(cor[i+1]->data<=cor[i]->data){
            ans=false;
                break;
            }
        }
        return ans;
        		
	}







