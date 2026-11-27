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
// Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
// Output: [1,2,3,7,8,11,12,9,10,4,5,6]
// Explanation: The multilevel linked list in the input is shown.
// After flattening the multilevel linked list it becomes:

class Solution {
    public:
    Node* flatten(Node* head) {
        //We will solve this question using recursion which means we are going to call flatten function again
        // and again to flatten the multilevel to single leverl DLL;

        //This function will need to return a node pointer which is head. 
        // code here
        //First of all, we can check a base check which is if our head is equal to nullptr? 
        
        if(head == nullptr){
            return nullptr;
        }
        
        //We are going to divide this problem into different steps. 

        //Make a current pointer. 
        Node* curr = head;

        while(curr != nullptr){
            if(curr -> child != nullptr){

                //Preserving those nodes which are appearing after nodes which have child nodes. 
                //Example: Node 4, 9.
                Node* next = curr -> next;//We are going to preserve the current next node. 


                //3) iteration we will find our child node which is Node 7. 
                //Now, we are going to make this child node as a new Head to travese over the 2nd level DLL. 
                //Therefore, we are going to recall our function now with a new head. 
                // flatten(curr -> child); // we know that curr -> child is the new head now. 

                //We need to establish a connection our curr -> next should be now pointing to new head 
                curr -> next = flatten(curr -> child); //Node3 -> Node7

                //since this is double LL, we need to initlize the prev pointer too. 
                //Now connection new head prev pointer to curr.
                curr -> next -> prev = curr; //Node 7 childHead -> prev should point to curr Node 3

                //Disconnect the pointers of Node 3 and 4. 
                //Now the current node which is 3, its child pointer should be deleteed.
                curr -> child = nullptr;

                //Now, we would need to find the tail of the DLL. 
                //In order to find the nullptr, we would need to check if our newHead nodes is pointing to nullptr? 
                //The moment we find any node which is pointing to null.
                //We will get our tail. 

                while(curr -> next != nullptr){
                    curr = curr -> next;
                }
                //Now, our curr is at tail node. whhich is Node 12. 
                //We need to connect our node 12 to Node 9 now. 

                //We have to make sure that we preserve node 9 to make a connection. 
                //We know that when our Node 8 had a child. We have Node 9 after this.
                //So when we were pointing at Node8. Its next pointer was orginially pointing to Node 9 before
                //we made new connections. 
                //So we would need the connection of this in order to attach our tail to Node 9
                //Node* next = curr -> next;

                //Now we have next as the node. 

                if(next != nullptr)// we need to check if our next is not pointing to null. This could have 
                //happened if we had child nodes at Node 10. 
                {
                    curr -> next = next;//making next connection with node 12 -> node 9
                    next -> prev = curr;//making prev connection with node 12 <- node 9
                }
            }

            //We need to move curr. 
            curr = curr -> next;
        }
        return head;
    }
};
 
int main()
{
    return 0;
}