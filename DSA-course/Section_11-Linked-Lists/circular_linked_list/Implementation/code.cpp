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

class CircularList{
    Node* head;
    Node* tail;

public: 
    CircularList(){
        head = tail = nullptr;
    }

    // functions of Circular Linked List
    //1) insert at Head. 
    void insert_at_head(int val){
        //We would have to check if head is equal to null? In this case, our LL is empty. 

        //We would need to create a new node first. 
        Node* newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;
            //for circular LL, we know that our tail should point to our head to form a loop.
            tail -> next = head;
        }else{
            //We need to establish a new connection if we get another node. 
            newNode -> next = head;
            head = newNode;//We need to update the head after making the connection.
            tail -> next = head;// now the tail should point back to head to make circular connection.
        }
    }

    //2) print circular list function. 
    void print(){

        if(head == nullptr){
            cout << "The Circular List is emppty";
            return;
        }

        cout << head -> data << " -> ";
        Node* temp = head -> next;

        while(temp != head){
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << temp -> data << endl; // printing the head again.
    }

    //3) Insert at Tail. 
    void insert_at_tail(int val){

        Node* newNode = new Node(val);

        //First we need to check if our head is poinng to null or not? 
        if(head == nullptr){
            head = tail = newNode; // map head and tail to newNode. 
            tail -> next = head; //Form a connections. 
        }else{
            newNode -> next = head;// we need to connect the newNode which is tail to head.
            tail -> next = newNode; // Breaking the connection and point the next node of tail to newNode. 
            tail = newNode; // Update the tail to newNode
        }
    }

    //4) Delete at Head. 
    void delete_at_head(int val){
        //a) check if head is pointing to null or not? 
        // if yes, then we can't delete the list. 
        if(head == nullptr){
            cout << "The list is empty";
            return;
        }
        //b) If the CLL has one node only? 
        else if(head == tail){
            delete head;// we can directly delete it.
            head = tail = nullptr;
        }else{
            //c) 2 or more nodes.
            //we need to create a new temp Node. 
            Node* temp = head;// we have store the address of head in temp
            //Update head to point to next node.
            head = head -> next;
            // Now, tail should point to the new head. 
            tail -> next = head;
            //Need to break one more connection
            temp -> next = nullptr;
            //now delete the temp. 
            delete temp;
        }
    }

    void delete_at_tail(){
        if(head == nullptr) return; //when there is no node
        else if(head == tail){//if there is one node
            delete head;
            head = tail = nullptr;
        }else{
            Node* temp = tail;
            //In order to find the previous node before tail. We would need to run a loop. 
            //We can take prev at head and run a loop from head to tail. 
            Node* prev = head;
            while(prev -> next != tail){
                prev = prev -> next;
            }
            tail = prev; //we have found the prev node before tail. 

            tail -> next = head;// Now new tail should point to head now. 

            temp -> next = nullptr; // We need need to break the connection of temp. 

            delete temp;
        }
    }

};
 
int main()
{
    CircularList cll;

    cll.insert_at_head(1);
    cll.insert_at_head(2);
    cll.insert_at_head(3);

    cll.print();

    return 0;
}