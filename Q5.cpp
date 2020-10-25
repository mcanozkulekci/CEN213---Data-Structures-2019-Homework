#include <iostream>


using namespace std;


struct Node{
    Node *left;
    Node *right;
    int key_value;
};
Node *root=NULL;


class btree{
    public:
        void insert(int key);
        void postOrder(Node *leaf);
    private:
        void insert(int key,Node *leaf);
        
};


void btree::postOrder(struct Node *leaf)
{
    if(leaf)
    {
    postOrder(leaf->left);
    postOrder(leaf->right);
    cout<<leaf->key_value<<"\t";
    }
}



void btree:: insert(int key,Node *leaf){
    if(key < leaf->key_value){
        if(leaf->left!=NULL){
            insert(key,leaf->left);
        }else{
            leaf->left= new Node;
            leaf->left->key_value=key;
            leaf->left->left=NULL;
            leaf->left->right=NULL;

        }

        
    }
    else if(key >= leaf->key_value){
        if(leaf->right != NULL){
            insert(key,leaf->right);
        }else{
            leaf->right=new Node;
            leaf->right->key_value=key;
            leaf->right->left=NULL;
            leaf->right->right=NULL;

        }

    }
}
/*The public version of the insert function takes care of
 the case where the root has not been initialized by allocating 
 the memory for it and setting both child nodes to NULL and setting 
 the key_value to the value to be inserted. If the root node already
  exists, insert is called with the root node as the initial node of 
  the function, and the recursive insert function takes over.*/
void btree::insert(int key){
    if(root!=NULL){
        insert(key,root);
    }else{
        root=new Node;
        root->key_value=key;
        root->left=NULL;
        root->right=NULL;
    }
}




int main(){
    btree bt;
    int opt;
    int num;
    
    
    while(1){
        cout<<"Sayi Giriniz (Cıkıs=0)"<<" ";
        cin>>num;
        if(num != 0){
            bt.insert(num);
        }else if(num==0){
           
            Node *p=root;
            cout<<"Post Order Siralamasi:\n";
            bt.postOrder(root);
            exit(-1);
        }
    }


    return 0;
}