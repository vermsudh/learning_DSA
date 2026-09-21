#include<iostream>
#include<vector>
using namespace std;
 
//more optmazied apprach in orde to stop the sorting once the sorting is completed.
void bubbleSort(int arr[], int n){ 
    for(int i = 0; i < n -1; i++){
        //optimization to make the loop stop when the array has been sorted. 
        bool isSwap = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            return;
        }
    }
}

int main()
{
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};

    cout << "Before sort : ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr,n);

    cout << " After sort : " ;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}