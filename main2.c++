#include <iostream>
#include "ctime"
#include "algorithm"
#include "fstream"
#include "math.h"

using namespace std;

void printArr(int * arr, int length);


int binarySearch(int arr[], int l, int r, int x){ 
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

int findSubsetSortedArrayBinarySearch(int * arr1, int arr1Len , int * arr2, int arr2Len , double & timeAlgo2){
    sort(arr2, arr2 + arr2Len); // Since the sorting is not part of the homework i did use the standart library
    printArr(arr2, arr2Len);
    clock_t start = clock();
    for(int a = 0; a < arr2Len; a++){
        if(binarySearch(arr1, 0, arr1Len, arr2[a]) == -1){
            timeAlgo2 = 1000 * (double (clock() - start) / CLOCKS_PER_SEC);
        }

        else{

        } 
    }
    timeAlgo2 = 1000000 * (double(clock() - (double)start));

    delete [] arr1;
    delete [] arr2;

    return 1;
}


int main(){

    double time;
    for(int a = 0; a < 100; a++){

        int power = pow(10,5);

        int * arr1 = new int [power];
        int * range = new int [power];
        int * arr2 = new int [100];

        for(int a = 0; a < power; a++){
            arr1[a] = a;
            range[a] = a;
        }

        for(int a = 0; a < 10; a++){
            int r = rand() % power;
            arr2[a] = range[r] + 24;
            range[r] = range[a];
        }

        for(int a = 0; a < 10; a++){
            cout << arr2[a] << " ";
        }

        int x;
        cin >> x;
        
        findSubsetSortedArrayBinarySearch(arr1, power, arr2, 10, time);
        cout << "Time is: " << time << "\n"; 
    }


}

void printArr(int * arr, int length){

    for(int a = 0; a < length; a++){
        cout << arr[a] << " ";
    }

    cout << endl;
}


