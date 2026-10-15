#include<iostream>
#include<vector>
using namespace std;
 
int main()
{

    char str[] = {'a', 'b', 'c'};
    int arr[] = {1, 2, 3};
    cout << arr << endl;
    cout << str << endl;
    cout << strlen(str) << endl; // to find out the lenght of the string.

    char ch[] = "hello";//strings literal which will not change. 

    cout << ch[2] << endl;// to access specific char in the string using the same syntax. 

    char str1[13];

    cin >> str1;
    cout << "Output : " << str1 << endl; // if we type "Hello World" 
    // only Hello will be printed. 

    // In order to the the full name, we have to use a function called. 

    cout << "Type string again : " << str1 << endl;
    cin.getline(str1, 100);

    cout << "Output : " << str1 << endl;

    for(char ch : str1){
        cout << ch << " ";
    }

    return 0;
}