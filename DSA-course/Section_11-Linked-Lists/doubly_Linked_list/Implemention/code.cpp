#include<iostream>
#include<list>
using namespace std;
 
class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = nullptr;
    }
};

class DoublyList{
    Node* head;
    Node* tail;

public:
    DoublyList(){
        head = tail = nullptr;
    }
    //We need to create functions now. 

    //1) push_front();
    //We will have two cases where our head be empty and one would be nonEmpty.
    void pushfront(int val){
        Node* newNode = new Node(val);
        //When we create a new node and try to add to the front

        //1) First we need to check if the LL is empty or not.
        if(head == nullptr){
            //In this case, we will simply mark the pointers. 
            head = tail = newNode;
        }
        else{ // when we know that head is not null. 
            //make a connection newNode-> next should point to current 

            newNode -> next = head;
            //Then head -> prev should point to node 2 which is newNode.
            head -> prev = newNode;

            //update the new head which is Node 2
            head = newNode;
        }
    }
    //2) push_back(val)
    void push_back(int val){
        Node* newNode = new Node(val);
        
        //We will chech if our nodes are empty or not. 
        if(head == nullptr){
            head = tail = newNode;
        }else{
            //assume we have 1 <=> 2 We need to add 3. 
            //newNode should be after the head node. 
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
    }

    //3) print function
    void print(){
        
        //Take a temp pointer. 
        Node* temp = head;

        while(temp != nullptr){
            cout << temp -> data << " <=> ";
            temp = temp -> next;
        }
        cout << "NULL\n";
    }
    //4) pop front will remove the node from the front of the LL. 
    void popfront(){
        //assume we have we have this LL : 1 <=> 2 <=> 3
        //The end result should be 2 <=> 3

        //currently the head is 1 and tail at 3. 
        //We need to delete the head but we need to presever the Node 2 as a head before we 
        //delete it. 

        Node* temp = head;
        head = head -> next; // We have updated the head to next node. 
        //Now we need to break the connections between 1 and 2. 

        //But we need to make sure that any head -> prev = nullptr should be true. 
        //if we have only one node 1. then we need to check this. 
        if(head != nullptr){
            head -> prev = nullptr;//We want this new head to point at null. 
        }
        //Now we need to break second connection 
        //We need to connection temp -> next = nullptr;
        temp -> next = nullptr;
        //Now we can safely delete the temp;
        delete temp;
    }
    
};

int main()
{
    DoublyList dll;

    dll.pushfront(1);
    dll.pushfront(2);
    dll.pushfront(3);
    dll.pushfront(4);

    dll.print();

    dll.push_back(5);

    dll.print();

    return 0;
}