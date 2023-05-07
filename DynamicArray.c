#include<stdio.h>
#include<stdlib.h>


//dArr = Dynamic Array
typedef struct dArr{
    int nSize;
    int LastElementIndex;

    //function pointers
    //these will, well point to functions that can only operate on THIS specific data structure
    
    void (*append) (struct dArr*, int); //this takes in a dArr, which is just itself, and an integer, that we will add to this arr
    int (*pop)(struct dArr*);
    void (*display)(struct dArr*);
    int (*delete) (struct dArr*, int);

    //end of functions of dArr

    int *data;

}dArr;
//renamed it because typing is a pain

//function prototypes
void append(dArr* self, int val);
int pop(dArr * self);
void display(dArr * self);
int delete(dArr * self, int index);


// constructor
// returns a pointer to a dynamic arr struct after allocating memory for it.
dArr * init_dynamic_Arr(int size){

    dArr * self = (dArr * )malloc(sizeof(dArr));
    self->nSize = size;

    //allocating memory for the array
    self->data = (int * )malloc(sizeof(int)*size);

    //set the last index to -1 by default
    self->LastElementIndex = -1;

    //connecting the function pointers to the actual functions defined below
    self->append = &append;
    self->pop = &pop;
    self->delete = &delete;
    self->display = &display;

    return self;

}
//---------------------------------------------------------------------------------------------------
// basic functions that this array has
//      1. append (python habits die hard, i need that append feature ong)
//      2. pop (another python function fr)
//      3. display (C lang sucks for printing things, its always messy)
//      4. delete (Gotta make sure to free that memory)

// Append
// adds an element to the end of the dynamic array
void append(dArr* self, int val){
    int pos = (self->LastElementIndex)+1;

    //checking if the array is empty
    if(self->nSize == 0){
        //assigning memory for ONE integer unit
        self->data = (int * )malloc(sizeof(int));

        self->data[0] = val;

    }else if(pos < self->nSize){
        //we reallocate the amount of memory requireds
        //self->data = (int *)realloc(self->data, sizeof(int)*(self->nSize));

        self->data[pos] = val;

        //updating the last element Index
        (self->LastElementIndex)++;

    //if the array reaches maximum capacity, we expand its memory
    }else if(pos = self->nSize){
        //we double the memory, if it fills up (very reckless ik, but its not meant to handle large inputs anyway?)
        self->nSize *= 2;

        self->data = (int *)realloc(self->data, sizeof(int) *(self->nSize));

        //now we have updated the size of the array, we can just call the append function again
        append(self, val);   
    }


}


// removes the last element in the array, and returns it
int pop(dArr * self){
    int result = 0;
    // cant pop an item if the list is empty
    if(self->nSize == 0 || self->LastElementIndex == -1){
        printf("\n Empty array, can't pop \n");
    
    // if the array has more than 0 element s
    }else{
        //storing the value to be popped into a result variable, and adjusting the last element index position
        result = self->data[(self->LastElementIndex)];
        (self->LastElementIndex) -= 1;
    }


    return result;

}

// Displays horizontally, each element
void display(dArr * self){
    
    //tried to make it look like a python list on output
    printf("\n");
    int i = 0;
    printf("[");
    while(i <= (self->LastElementIndex)){
        printf("%d", self->data[i]);
        printf(", ");
        i++;
    }
    printf("]");

}

// Delete
// Removes the element at the given index and returns it
int delete(dArr * self, int index){

    int result;

    // if the index is out of range of the array, we raise an error
    if(index > self->LastElementIndex || index < 0){
        printf("\n Array does not have an element at index %d \n", index);
        result = 0;

    // if the index to be deleted is the END of the list, we can just call pop() function
    }else if(index == self->LastElementIndex){
        result = pop(self);
        
        
    
    // if the index is in between last and first, we need to SHIFT every element after it to the left by 1
    }else{
        //left shifting each element
        int temp = self->data[index];
        result = temp;

        while(index + 1 != self->LastElementIndex){
            self->data[index] = self->data[index + 1]; //we replace the current element with the next element, and repeat this
            index++;
        }
        //we shift the last index to the left, because we deleted an element from the array
        self->LastElementIndex -= 1;

        
        

    }
    
    return result;

}






int main(){
    dArr * DYNAMIC_ARRAY = init_dynamic_Arr(2);

    DYNAMIC_ARRAY->append(DYNAMIC_ARRAY, 1);
    DYNAMIC_ARRAY->append(DYNAMIC_ARRAY, 2);
    DYNAMIC_ARRAY->append(DYNAMIC_ARRAY, 3);
    DYNAMIC_ARRAY->append(DYNAMIC_ARRAY, 4);
    DYNAMIC_ARRAY->append(DYNAMIC_ARRAY, 7);

    display(DYNAMIC_ARRAY);

    int deletedVal = delete(DYNAMIC_ARRAY, 0);
    
    

    //printf("element : %d", DYNAMIC_ARRAY->data[2]);
    
    printf("\n element deleted : %d", deletedVal);
    display(DYNAMIC_ARRAY);
}
