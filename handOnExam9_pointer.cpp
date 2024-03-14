/*======================================================================================
Design a function that can sort an array of integers. Also write a main program to 
call the function and sort the following integer array in ascending order. 
Display the integer array before and after sorting.
{3, 8, 10, 30, 2, 16, 27, 13, 22, 17, 42, 33, 38, 29, 14}
========================================================================================*/
#include <iostream>

using namespace std;

int* bubbleSort(int a[], int lenth){
    for(int i = 0; i < lenth - 1; i++){
        for(int j = 0; j < lenth - i - 1; j++){
            if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }

    return a;
}

int main(){
    int array[15] = {3, 8, 10, 30, 2, 16, 27, 13, 22, 17, 42, 33, 38, 29, 14};

    int *ptr = bubbleSort(array, 15);

    cout << "The array after bubbleSorted : ";
    for(int i = 0; i < 15; i++){
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;

    return 0;
}