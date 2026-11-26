#include<iostream>
#include<list>
using namespace std;

class Node{
public: 
    int data; 
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList{
public: 
    Node* head;
    Node* tail;

    CircularLinkedList(){//THis is a constructor. 
        //Inside the constructor. We will define our node. 

        head = tail = nullptr; // Currenly, when we have no node. 
    }

    //Now, we have to make the functions of the Circular Linked List. 

    //1) insert at head. 
    void insert_at_head(int val){
        //We have to insert a new node at the the head. 
        
        Node* newNode = new Node(val);
        //Few checks if we have empty list, then the head and tail should point to added node.
        if(head == nullptr){
            head = tail = newNode;
            //We would neeed to point our tail back to the head to form circular connection.
            tail -> next = head;
        }else{// when we have more than one node in the CLL.
            //IN CLL, the head moves normally but the tail points back to head to form a circular path.
            //So, suppose we have this current LL. 
            // 1 -> 2 -> 3 -> 1.      // We have to add 4 at the head. 
            //We would have to form the new connections. 
            //Firstly the newNode should become the head now. and the tail next pointer should point to newNode. 
            newNode -> next = head; // this will form a connection. 
            head = newNode; // the new Node should be the new head now. 
            //The tail should point to the new head. 
            tail -> next = head;
        }
    }

    void printcll(){

        //edge case, if we have LL null, then in that case. We have to return.
        if(head == nullptr){ 
            cout << "The list is empty!";
            return;
        }

        //In order to print the CLL. 
        //We know that we have to take a temp pointer which will traverse over the LL starting from head.

        Node* temp = head; 

        while(temp != head){// we know that CLL does not have a nullptr. So we need to stop printing once 
        //it reaches back to the head again. 
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << temp -> data << endl; // printing the head again.
    }

    //3) Now, we have to insert at tail
    void insert_at_tail(int val){
        Node* newNode = new Node(val);

        //Firstly, if we have only 0 node. 
        if(head == nullptr){
            head = tail = newNode;
            tail-> next = head;
        }else{// now when we have more than one node. 
            //Now, we need add a node at the tail. 
            //The tail needs to be updated. 
            newNode -> next = head; // the new tail should point to the head. 
            tail -> next = newNode;
            tail = newNode;
        }
    }

    //4) delete_at_head
    void delete_at_head(){
        if(head == nullptr){
            return;
        }else if(head -> next == nullptr){
            delete head;
            head = tail = nullptr;
        }else{
            //Now we have to delete the head.
            //Firstly we have make a new head. 

            Node* temp = head;
            //before we delete our temp. we would need to build a new connections

            head = head -> next; // the new head would now one node after temp.

            //Since this is a circular list. Currently, we have to update tail to point it to right node. 
            tail -> next = head;

            //We have to disconnect the temp pointer. 
            temp -> next = nullptr;

            delete temp;
        }
    }

    //5) delete_at_tail
    void delete_at_tail(){
        if(head == nullptr){
            return;
        }else if(head -> next = nullptr){
            delete head;
            head = tail = nullptr;
        }else{
            //Now, we would need to run a loop to check the previous tail
            //As we can;t go back in CLL.

            Node* tempTail = tail;
            
            Node* prev = head;

            while(prev -> next != tail){
                prev = prev -> next;
            }

            tail = prev;// the tail has been shifted to previous node. 

            tail -> next = head;

            // oldtemp connection should be destroyed 

            tempTail -> next = nullptr;
            
            delete tempTail;
        }
    }

};
 
int main()
{
    return 0;
}