#include<stdio.h>
#include<stdlib.h>



struct Node{
    int val;
    struct Node* left;
    struct Node* right;

    void (*preorder)(struct Node * );
    int (*inorder)(struct Node * );
    void (*postorder)(struct Node * );

};
//renaming "struct Node" to just "Node" because time is of the essence (its really not)
typedef struct Node Node;

int inorder(struct Node * self);
void postorder(struct Node * self);
void preorder(struct Node * self);

//constructor
// Ik C lang doesn't have constructors, but I like to think of this as one, as it achieves the same thing functionally
Node * initNode(Node * self, int val);

Node * initNode(Node * self, int val){
    
    //allocating memory to a pointer to the Node
    self = (Node *)malloc(sizeof(Node));

    //setting the user value at the node
    self->val = val;
    self->left = NULL;
    self->right = NULL;

    //connecting the function pointers to the proper functions
    self->preorder = preorder;
    self->inorder = inorder;
    self->postorder = postorder;

    //returning the Node pointer back after properly initialising
    return self;
}

void addNode(Node * Root,char LR, int val);
void addNode(Node * Root,char LR, int val){

    
    Node * TempNode = initNode(TempNode, val);
    TempNode->val = val;

    //if tree doesnt exist, we simply add a root node, with NULL children
    if(Root == NULL){
        

        Root = TempNode;

    //checking if the L or R (left or right) node is NULL or filled
    }else if (LR == 'L'){
        if(Root->left == NULL){
            Root->left = TempNode;
        }else{
            printf("\n Left child occupied");
        }

    }else if(LR == 'R'){
        if(Root->right== NULL){
            Root->right = TempNode;
        }else{
            printf("\n Right child occupied");
        }
    }

}



int inorder(struct Node * self){
    
    //recursive approach because using the iterative approach needs a stack to be used, which is annoying to think of
    //Inorder follows the following -> leftChild -> root -> rightChild

    //base case
    //if we reach a leaf node (a node with no children)

    if(self != NULL){
        
        inorder(self->left);
        printf(" %d,", self->val);
        inorder(self->right);
    }

    


}
void postorder(struct Node * self){
    
    //post order follows -> leftChild -> rightChild -> root

    if(self != NULL){

        postorder(self->left);
        postorder(self->right);
        printf(" %d,", self->val);


    }



}
void preorder(struct Node * self){

    //preorder follows -> root -> leftChild -> rightChild

    if(self  != NULL){

        printf(" %d,", self->val);
        preorder(self->left);   
        preorder(self->right);


    }


}


int main(){

    //creating a small tree
    Node* RootNode = initNode(RootNode, 10); 
    addNode(RootNode, 'L', 11);
    addNode(RootNode, 'R', 92);
    addNode(RootNode->left, 'L', 12);

    
    
    //testcases
        //inorder(RootNode);
        //postorder(RootNode);
        //preorder(RootNode);

    return 0;

}


