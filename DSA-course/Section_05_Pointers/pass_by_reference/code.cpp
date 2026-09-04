#include<iostream>
using namespace std;

void changeA(int a){
    a = 20;
}

void changeApointer(int *ptr){
    *ptr = 20;
}

int main()
{   
    int a = 10;
    changeA(a);
    changeApointer(&a);

    cout << "inside main function : " << a << endl;

    cout << "inside main function : " << a << endl;

    return 0;
}