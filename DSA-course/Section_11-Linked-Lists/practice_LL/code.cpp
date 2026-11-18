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

    // void push_front(int val){
    //     //First would need to create an object. 

    //     Node* newNode = new Node(val);

    //     //We have a new object. 
    //     //We would need to check if our LinkedList is empty or not. 
    //     //If it is, then we would have to assign head and tail pointer to the first object which is newNode. 

    //     if(head == NULL){
    //         head = tail = newNode;
    //         //We would have to return now without doing anything. 
    //         return;
    //     }else{
    //         //Now, we would have to assign the right pointer to the right place. 
    //         newNode -> next = head;// The new value that is being passed in the paramater needs to have head pointer
    //         //as it is the firstNode. 
    //         //(Take the next pointer inside the Node pointed to by newNode, and assign it the address stored in head.
    //         //In other words:
    //         //newNode->next now points to Node 3.)
    //         // the head needs to be the newNode. 
    //         head = newNode;
    //     }
    // }

    void push_back(int val){
        //Now, we would have to push a new value on the back of the LL. 
        //First we would need to check if our LL is empty or not? 

        //Lets create a new Node using the constructor we have defined in Node class. 
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            tail -> next = newNode; //This is basically adding a new node after last node. 
            //Now we just have to update the tail pointer to the last node. 
            tail = newNode;
        }
    }

    void pop_front(){
        //Now, we have to delete the front node which is pointing to head.
        //If we have one node only, then if the node gets deleted, we will have empty LL.
        //Also, we would have to check if we have empty LL or not. 

        //Now, we know that we would need to delete the first node where the pointer is HEAD. 
        //If we delete the pointer Head and do not assign it to the next Node before delete, 
        //the whole LL can get lost, so we would need to make sure that we assign the Head pointer 
        //to the right Next node. 

        if(head == NULL){
            //We would need to return from this function. 
            cout << "THe LL is empty.";
            return;
        }
        //In the similar way in PrintLL, we would have to assign head pointer to a temp and try to
        //move it while we delete the orginal head. After deleting the first node, we would have to 
        //assign the next node a Head Pointer so that the LL stays intact. 
        //Lets assign Head pointer Head to a temp variable. 
        // temp,  head
        //  |       |
        //  v       v
        // [10] -> [20] -> [30] -> nullptr

        Node* temp = head; // This is assigning temp as a head. We are going to delete this. 
        head = head -> next;// This will move the pointer to the next node. 

        //If we have a edge case where our LL has only one node. 
        //In this case, we would have to update both our pointers to NULL values. 
        //If we just make one pointer to NULL, then other pointer TAIL will be a dangling pointer which will
        //still points to the old memeory address which will not exist if we delete it. 

        if(head == NULL){
            tail = nullptr;
        }
        temp -> next = NULL;
        delete temp;

    }

    void pop_back(){
        //Similary, we would have to delete the last node. 
        //Lets check if the LL is empty or not. 
        if(head == NULL ){
            cout << "LL is the empty right.";
            return;
        }
        //if LL has only single node. In that case, we would have to 
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }

        //Now we would have to assign temp to tail pointer as we would need to move one node back 
        //to direct the TAIL pointer correctly. 

        Node* temp = head; //assigning tail as Head as we need to travese over single LL. 
        //Now, we need to move original temp on node back. 
        //For this, we would need to find the node before the TAIL as we need to delete the tail and need
        //to assign a new node as TAIL. One before it. 
        //Since Single LL are straigtforward, we can traverse backwards.

        while(temp -> next != tail){
            temp = temp -> next; // The loop stops when temp->next == tail, not when temp->next == nullptr.
        }
        
        //Now, we need to make sure that we assign the temp which is TAIL to NULL pointer before we delete it. 
        temp -> next = nullptr;  
        delete tail;

        // now we have store TAIL in temp.
        tail = temp;// we are assigning second last node as TAIL. 
        
    }

    void insert(int val, int pos){

    }

    int search(int val){

        //Since we have to travese over the List to find out if the passed val exist in the list or not. 
        //We would need to return its indices if it exists or not. 
        //First of all, we would need to assign a temp as HEAD. 

        Node* temp = head;

        //We can use while loop and run the temp until we have reached the tail. 

        while(temp != NULL){
            
        }

        return -1;
    }

    void printLL(){
        //10 → 20 → 30 → nullptr
        
        //For printing we would have to take a temp variable and assign head pointer. 
        //It should keep on moving untill it reaches a NULL value which is the last last node pointer. 

        Node* temp = head; //We would have to preserve head as the original pointer which is at first node. 
        //Just in case, if it points to the incorrect node, then the LL can get lost. 
        //That is why we need to create a new temp and assign it head pointer. 

        while(temp != NULL){
            cout << temp -> data << " -> "; 
            temp = temp -> next;//this is updating the temp and moving to the next node after every iteration
            //until temp is not equal to NULL. Since the last node is going to be 
        }
        cout << " NULL " << endl;
    }
};

 
int main()
{

    List ll;

    ll.push_front(4);
    ll.push_front(2);
    ll.push_front(1);

    ll.printLL();

    ll.pop_front();

    ll.printLL();


    return 0;
}