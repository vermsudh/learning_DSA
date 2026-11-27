#include<iostream>
#include<list>
using namespace std;


class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
    public:
    Node* flatten(Node* head) {
        //We have to return return a head but we have to conver the multi level DLL to single LL. 
        
        //Firstly, we can base check if our LL is empty or not? 
        if(head == nullptr){
            return nullptr;
        }

        //Now, since we have to return the head. 
        //We would have to travese over the DLL using the pointer and a loop. 
        //We would have initlize another pointer other than our orginal head in order to preserver the orginal
        //head. 
        Node* curr = head; // curr is the pointer which is pointing at head currently. 

        while(curr != nullptr){//we have to iteration until we get our last node which is tail. 
            if(curr -> child != nullptr){
                //Preserving Node 4 and Node 9 using pointers. 
                Node* next = curr -> next; // when curr was at Node 3. we are going to preserve Node 4 in next pointer

                //when we will get our curr at Node3 for instance. 
                //We know that our curr -> child is pointing to Node 7 now. 
                //and we have to print this [1,2,3,7,8,11,12,9,10,4,5,6]
                //which means, we have print 1 <=> <=> 2 <=> 3 <=> 7

                //We would have to print the second level DLL 
                // And again, we have to print the similar structure.
                //1 <=> <=> 2 <=> 3 <=> 7 <=> 8 <=> 11 <=> 12 <=> 9
                //We noticed that we have to perform same function again and again to print. 
                //We can use recursion by calling the function flatten again. 
                //Firstly we have to initlize a new head. 
                //Our child node of 3 which is 7 should become a newHead. newHead would be curr -> child
                //flatten(curr -> child);
                //Now curr -> next which is currently pointing to Node 4 should point to Node 7 instead. 

                curr -> next = flatten(curr -> child);

                //Now, suince this is a DLL. We need to connect prev pointer too to Node 7. 

                curr -> next -> prev = curr;
                //Node7.    -> prev = Node 3;

                //Now, we need to find the tail node. 
                //Using recursion, the current should reach to last node which is Node 12. 
                //In order to stop it. we would need to run a loop. 

                //We need to break the current connection of child node. 
                curr -> child = nullptr;
                

                //This will help us to find the tail. 
                while(curr -> next != nullptr){
                    curr = curr -> next; //Now curr is at Node 12. 
                }

                //Now, we have to connect Node 12 to Node 8.
                //Similarly, when curr will reach at Node 9 - it should connect to Node 4. 

                //We would need to preserve Node 4 before we make a newhead which is flatten(curr -> child);
                //We have preserved next node after curr which has node in this pointer -> next

                //We need a check now if our next does not point to nullptr. This can happen when we have 
                // our nodes have children nodes at last. 
                if(next != nullptr){
                    //We need to point form a next connection of our tail node to next which is Node 12 to Node 9
                    curr -> next = next;// form a next connection Node 12 -> Node 9
                    next -> prev = curr;// form a prev connection Node 12 <- Node 9
                }
            }
            curr = curr -> next;// this will to increment the curr. 
        }
        return head;
    }
};