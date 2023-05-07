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

Node * initNode(Node * self, int val);
Node * initNode(Node * self, int val){
    
    //allocating memory to a pointer to the Node
    self = (Node * )malloc(sizeof(Node));

    //setting the user value at the node
    self->val = val;

    //connecting the function pointers to the proper functions
    self->preorder = preorder;
    self->inorder = inorder;
    self->postorder = postorder;

    //returning the Node pointer back after properly initialising
    return self;
}

void addNode(Node * Root, int val);
void addNode(Node * Root, int val){

    
    Node * TempNode = (Node * )malloc(sizeof(Node));
    TempNode->val = val;

    //if tree doesnt exist, we simply add a root node, with NULL children
    if(Root == NULL){
        TempNode->left = NULL;
        TempNode->right = NULL;
    }else{
        

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

    

    return 0;

}


