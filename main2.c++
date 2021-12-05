#include <iostream>
#include "ctime"
#include "algorithm"
#include "fstream"
#include "math.h"

using namespace std;

void printArr(int * arr, int length);

int main(){

    clock_t start = clock();
    int * arr1 = new int [1000000];
    
    for(int a = 0; a < 10000000; a++){
        arr1[a] = a;
    }

    sort(arr1, arr1 + 100000);
    
    cout << clock() - start << endl;
}

void printArr(int * arr, int length){

    for(int a = 0; a < length; a++){
        cout << arr[a] << " ";
    }

    cout << endl;
}
