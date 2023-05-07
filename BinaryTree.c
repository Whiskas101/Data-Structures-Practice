#include<stdio.h>
#include<stdlib.h>



struct Node{
    int val;
    struct Node* left;
    struct Node* right;

    void (*preorder)(struct Node * );
    void (*inorder)(struct Node * );
    void (*postorder)(struct Node * );

};
//renaming "struct Node" to just "Node" because time is of the essence (its really not)
typedef struct Node Node;

void inorder(struct Node * self);
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



void inorder(struct Node * self){
    printf("pretend this is inorder output");
}
void postorder(struct Node * self){
    printf("pretend this is postorder output");
}
void preorder(struct Node * self){
    printf("pretend this is preorder output");
}


int main(){

    Node* RootNode = initNode(RootNode, 10); 
    addNode(RootNode, 'L', 11);
    addNode(RootNode, 'R', 12);
    printf("%d", RootNode->right->val);
    return 0;

}


