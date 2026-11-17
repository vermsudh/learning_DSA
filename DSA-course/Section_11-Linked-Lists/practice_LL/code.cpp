#include<iostream>
#include<list>
using namespace std;

class Node{
    //First we would have to check what comes in Node? 
    //1st is the value that needs to be their in the LL. It is basically storing the data. 
    //2) Memeory location pointer which is next. 
public:
    int data; 
    //Now, we need a pointer which is going to be next. 
    //This will always points to the next node. 
    Node* next;

    //Now, we need to create a constructor defining the initiating pointer of first node. 

    Node(int val){
        // Lets initialize the data first. 
        data = val;
        //Lets initialize next. 
        next = NULL; 
    }
    //When you execute:
    // Node* newNode = new Node(10);

    // Three things happen conceptually:
    // 1. Memory is dynamically allocated for a new Node.
    // 2. The constructor receives 10 and assigns it to data.
    // 3. next is initialized to NULL.
};

//Creating a List class now to define our pointers head and tail. 

class List {
public: 
    //Defining the pointers which are head and tail of the linkedin List. 
    Node* head;
    Node* tail;

    //created a constructor and need to assign the initlize values of head and tail which should be NULL
    List(){
        //Assignin head and tail NULL. 
        head = tail = NULL;
    }

    void push_front(int val){
        //Now, we have the pointers which are head and tail which initlizially pointing to NULL.

        //Lets assume we have a LL  : 3 -> 2 -> 1.
        //We will have to add 4 in the front of the LL. 

        //How to do it? 
        //We know the value that needs to be update in the front will be passed as a parameter.
        //In this case, we know that our head is at 3 which is the first node and 1 is tha tail node. 
        //But currently, we have to update head and tail. 
        //For assigning the first node as 4 now, we would have update the head which is a pointer at 3 currently. 
        
        //We would need to create an object of Node. 
        Node* newNode = new Node(val);// Creating a new obkect with a name newNode. 
        //We need to check if the List is empty or not. 
        if(head == nullptr){
            head = tail = newNode;
            return;
        }else{
            
            //1) newNode->next stores the address currently held by head (Node 3).
            newNode -> next = head;
            //2) head is updated to store the address of newNode (Node 4).
            head = newNode;
        }
    }

    void push_back(int val){
        
    }

    void pop_front(){

    }

    void pop_back(){

    }

    void insert(int val, int pos){

    }

    int search(int val){

    }

    void printLL(){

    }

};

 
int main()
{
    return 0;
}