#include<iostream>
#include<vector>
using namespace std;

void selectionSort(int arr[], int n){

    // first we traverse over our elements. 
    for(int i = 0; i < n -1; i++){
        // we assume that our first index value is the min. 
        int smallest_index = i;
        // Now, we need to traverse over the next elements to find the min value. because we dont know if the assumed value is the min or not
        for(int j = i + 1; j < n; j++){// we dont have to take the first element as we have already taken that and assumed that one as min.
            if(arr[j] < arr[smallest_index]){
                smallest_index= j; // if we find any element that is smaller than our assumed min, we will update the min
            }
        }
        //now, we know for 1st ieration, we have our min element, we just need to swap it with first element.
        swap(arr[smallest_index], arr[i]);
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

    selectionSort(arr,n);

    cout << " After sort : " ;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}