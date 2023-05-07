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
int pop(dArr * self){}

// Displays horizontally, each element
void display(dArr * self){}

// Delete
// Removes the element at the given index and returns it
int delete(dArr * self, int index){}





int main(){
    dArr * DYNAMIC_ARRAY = init_dynamic_Arr(2);

    DYNAMIC_ARRAY->append(DYNAMIC_ARRAY, 1);
    DYNAMIC_ARRAY->append(DYNAMIC_ARRAY, 2);
    DYNAMIC_ARRAY->append(DYNAMIC_ARRAY, 4);

    printf("element : %d", DYNAMIC_ARRAY->data[2]);
}
