#include<iostream>
#include<list>
using namespace std;

//For using Linkedin List in Cpp, We would have to use Lists in STL. 

class Node {
public :
    int data; 

    Node* next; 
    Node(int val){
        data = val;
        next = NULL;
    }
};

 //Head is bascially a pointer of the first node. 
//We just have given it a name. 
//Similarly, we have TAIL pointer which points to the last node. 
class List{
    Node* head;
    Node* tail;

public: 
    List(){
        head = tail = NULL;
    };
    //Functions of LinkedList are 
    //1) push-front -> It push a new value on the front. Storing at the first of the LL.
    //2) push-back -> It push a new value from the back. Storing at the end of the LL. 


    //We will create a new function which should be void. 
    void push_front(int val){
        Node* newNode = new Node(val); // dynamic object which stays in the memory after the call. 
        //Node newNode(val); //This is static which create object in the memory. 
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{// when we are done creating the first node and pointing the HEAD and TAIL.
            
            newNode -> next = head; // (next)-> is a pointer which is pointing to the head. 
            //So, if we use push_front(), then any node created will have a pointer next which will
            //point to the head the starting node. 
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            tail-> next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "LL is empty \n";
        }
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> data << "->";
            temp = temp -> next;
        }
        cout << " NULL " <<  endl;
    }
};

int main()
{

    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_back(4);
    ll.push_back(5);

    ll.push_front(6);

    ll.pop_front();

    ll.printLL();

    //How to print the Linked Lists? 

    return 0;
}