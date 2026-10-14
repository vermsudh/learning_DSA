#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    
    vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.emplace_back(6);

    cout << vec.size() << endl;//3
    cout << vec.capacity() << endl;//4

    for(int n : vec){
        cout << n << " ";
    }

    cout << endl << "value at index 2 is : " << vec[2] << " or " << vec.at(2) << endl;
    cout << endl << "value at front :  " << vec.front() << endl << "value at back :  "  << vec.back() << endl;
    
    vector<int> vec2(3, 10); // 3 is the size and values is 10.
    
    vec2.erase(vec2.begin() + 2);
    for(int n : vec2){
        cout << n << " ";
    }

    vec2.insert(vec2.begin() + 1 , 100);

    for(int n : vec2){
        cout << n << " ";
    }

    vector<int> vec3 = {2, 3 ,4};
    vec3.clear();

    cout << endl << "size of vec3 after clear :" << vec3.size() << endl ;//0
    cout << endl << "capacity of vec3 after clear :" <<  vec3.capacity() << endl; //3

    return 0;
}