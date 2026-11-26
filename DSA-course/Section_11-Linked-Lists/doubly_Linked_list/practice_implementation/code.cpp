#include<iostream>
#include<list>
using namespace std;

class Node{
public: 
    int data;
    Node* next;
    Node* prev;
    
    Node(int val){// We are going to create a constructor. 
        //Our data will hold the value that is being passed by the user. 
        data = val;
        next = prev = nullptr; //At first, both our pointer will point at nullptr when we create 
        //first node. 
    }
};

class DoublyList{
public:
    Node* head;
    Node* tail;

    DoublyList(){
        head = tail = nullptr;
    }

    //1) Lets create the first function which is push_front()

    void push_front(int val){// this function will pass the node value when we create one. 
        Node* newNode = new Node(val);
        //Lets create the conditons, when there is no node. 
        if(head == nullptr){
            // In this case, we will create a new Node, and assign next and prev pointer to nullptr. 
            head = tail = newNode;
        }else{// when we will have more than one node. 
            //For Example : 2 <=> 3
            //When we want to add 1 <=> 2 <=> 3

            //1) Then we have to point the newNode -> next to point to current head which is 1 -> 2 2 <=> 3
            newNode -> next = head;
            //2we would have to point the head -> prev = newNodeNode; which is 1 <- 2 2 <=> 3
            head -> prev = newNode;
            //Now, we have to update the head. 
            head = newNode;
        }
    }

    //2) printdll
    //We would have travese over using a temp pointer. 
    void printdll(){
        Node* temp = head;

        while(temp != nullptr){
            cout << temp-> data << " <=> ";
            temp = temp -> next;
        }
        cout << "NULl \n" <<  endl;
    }

    //3) push_back();
    void push_back(int val){
        Node* newNode = new Node(val);

        if(head = nullptr){
            head = tail = nullptr;
        }else{
            //We need to add a node after the tail now. 
            //Suppose we have 2 <=> 3. We need to add node 4.
            
            //1) Current the current tail is Node 3. 
            //1) We need to establish a new connection. 
            
            tail -> next = newNode;
            //2) Assign prev pointer. 
            newNode -> prev = tail;
            //3) Assign a new tail.
            tail = newNode;
        }
    }

    //4) pop_front() which will delete the node at the front.
    void pop_front(){
        //Now, we have to remove from the front which is the head. 
        //We can have the following conditions.
        
        //1) If we have empty LL. In that case, we can't delete anything. 
        if(head == nullptr){
            cout <<" The list is empty";
            return;
        }else if(head -> next = nullptr){//When LL has only 1 node. 
            head = tail = nullptr;
        }else{//When LL has more than 2 nodes.
            //Currently, we have to update the head. 
            
            //We would need a temp pointer as when we will assign a new head. We would need a pointer to delete
            //We can't delete our orginal head pointer as it can lead losing the whole LL. 
            Node* temp = head;
            
            //Now, we have to point the current head to temp -> next
            head = head -> next; //which is the next node. 
            //We have to think about the prev connection too. 
            
            if(head != nullptr){
                head -> prev = nullptr;
            }

            temp -> next = nullptr; //as we need to break the connection and make temp pointer points to null

            delete temp;// we will delete the temp. 
        }
    }

    //4) We have to create a new function called pop_back();
    void pop_back(){
        //We have two options here. 
        //1) We need to check if our LL is empty or not. 
        if(head == nullptr){
            cout << "The list is empty."; 
            return;
        }

        Node* temp = tail;

        if(head != nullptr){
            tail = nullptr;
        }else{
            
            //Now, we have to establish a new connection. 
            //We need a previous node. 
            tail = tail -> prev;// This will move the tail to previous node. 

            if(tail != nullptr){
                tail -> next = nullptr;
            }

            temp -> prev = nullptr;

            delete temp;
        }
    }
};
 
int main()
{
    DoublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_front(4);
    dll.push_front(5);

    dll.printdll();

    return 0;
}