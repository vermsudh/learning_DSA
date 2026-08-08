#include <iostream>
using namespace std;

int main(){

    cout << "Type the value of n : ";
    int n;
    cin >> n;

    //top
    for(int i = 1; i <= n; i++){ // outer loop

        // 1) print the stars
        // 2) print the spaces X 2
        // 3) Print the stars again with the inner loop

        // print the triangle first
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        //print the spaces on the second inner loop
        // for(int j = n - i ; j >= 0; j--){
        //     cout << " ";
        // }
        // //print the spaces again as we have divided the top pattern into 4 parts
        // for(int j = n - i ; j >= 0; j--){
        //     cout << " ";
        // }

         for (int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }

        // We can write the spcaes foor twice like this : 2*(n - i)
        // for(int j = 2 * (n - i) ; j > 0; j--){
        //      cout << " ";
        // }

        //print the stars
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        // print the stars again on the third inner loop
        cout << endl;
    }// top outer loop ends

        //bottom
        for(int i = n; i >= 1; i--){
            //print the stars

            for(int j = 1; j <= i; j++){
                cout << "*";
            }
            // middle spaces

            for(int j = 1; j <= 2 * (n -i); j++ ){
                cout << " ";
            }
            // print the stars agin
            for(int j = 1; j <= i; j++){
                cout << "*";
            }
            cout << endl;
    }

    return 0;
}