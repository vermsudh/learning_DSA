#include<iostream>
#include<vector>
using namespace std;
 
int main()
{

    string str = "apna college";// strings are dynamic in nature which can change the size on runtime. 

    cout << str << endl;

    char chArr[] = "Hello College"; // we can't change the characters in the char.

    // Just like we have vectors which can change its size dynamizally and better to use than array. 
    // similarly we have strings instead of using character arrays. 

    string str2; 

    getline(cin, str2);

    cout << str2 << endl;

    //run a loop. 
    string str3 = "Sudhanshu";

    for(int i = 0; i < str3.length(); i++){
        cout << str3[i] << " ";
    }
    cout << endl;

    for(char ch : str3){
        cout << ch << " ";
    }
    return 0;
}