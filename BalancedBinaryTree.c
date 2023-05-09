#include<stdio.h>
#include<stdlib.h>


//binary tree node structure
struct Node {

    //pointers to its left and right subtree's root nodes
    struct Node * left;
    struct Node * right;

    //actual value being stored
    int val;

    //functions that operate on this data structure follow the following definition structure
    //  (return type) ((function name) (function arguments))
    void (*addNode) (struct Node *, int);
    int (*Height) (struct Node *);

};

typedef struct Node Node;


Node * init(struct Node * self, int val);

//initialising all functions that are pointed to in by the struct Node
void addNode(Node * root, int val);
void addNode(Node * root, int val){
    // what makes a binary tree balanced, is the way elements are added into it
    // they are added in such a manner that, the tree actually "spans" or grows in a "vertical direction"
    // right skewing and left skewing is not possible here, because if the height of the left subtree or right subtree increases
    // disproportionately, it will self correct itself by certain rotations that ensure the tree stays balanced 
    
    // to start off, we initialise a an empty node with the value taken from the user
    Node * tempNode = init(tempNode, val); 
    // notice how writing the init function saved us from rewriting memory allocation, 
    // and child pointer initialisation, we know that the init will set the child nodes of the tempNode to be NULL by default

    //now we need to calculate the height of the left and right subtree of the "root" node sent to us


}



int Height(Node * root){
    
    if(root == NULL){
        return 0;
    }
    
    int leftSubtreeHeight = Height(root->left);
    int rightSubtreeHeight = Height(root->right);

    return (max(leftSubtreeHeight, rightSubtreeHeight) + 1);
}






//initialising the init function (ironic ik)
Node * init(struct Node * self, int val){

    self = (Node * )malloc(sizeof(Node));

    //initially we set it to be an independent node, with no children and only its own root node value
    self->val = val;
    self->left = NULL;
    self->right = NULL;


    //connecting the function pointers to the functions
    self->addNode = addNode;
    self->Height = Height;

}






int main(){

    Node * testNode = init(testNode, 10);
    testNode->addNode(testNode, 'L', 10);

    return 0;
}





