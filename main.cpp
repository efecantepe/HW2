
/**
 *  @file main.cpp
 *  @author Efe Can Tepe 
 *  @brief  HW2 
 *  @version 0.1
 *  @date 2021-11-30
 * 
 *  This is the homework2 for the Bilkent University CS201 class. It is a simple algorithm analysis
 *  program which compare 3 algorithms by their complexity
 *  
 *  ASSUMPTIONS FOR SIMPLICITY
 *  ----------------------------------------------------------------------------
 *  1- arr1 is sorted
 *  2- length of arr2 is always smaller or equal to arr1
 *  3- arr2 contains only unique items. Since it is asserted that algorithms will produce same results
 *     under the same conditions
 *  4- I will not use any negative number in the array since the termination of the all my algorithms  
 *  ----------------------------------------------------------------------------
 */

#include <iostream>
#include "ctime"
#include "algorithm"
#include "fstream"


using namespace std;

int binarySearch(int arr[], int l, int r, int x, int iterationCount);
int findSubsetLinearSearch(int * arr1, int arr1Len, int * arr2, int arr2Len , double & timeAlgo1);
int findSubsetSortedArrayBinarySearch(int * arr1, int arr1Len , int * arr2, int arr2Len , double & timeAlgo2);
int findSubsetFrequencyTable(int * arr1, int arr1Len , int * arr2, int arr2Len , double & timeAlgo3);

int main() {
    
    
}

int findSubsetLinearSearch(int * arr1, int arr1Len, int * arr2, int arr2Len , double & timeAlgo1){
    
    clock_t start = clock();
    for(int a = 0; a < arr2Len; a++){
        bool isFound = false;
        
        for(int b = 0; b < arr1Len; b++){
            if(arr1[b] == arr2[a]){
                isFound = true;
                break;
            }
        }

        if(isFound == false){
            timeAlgo1 = 1000 * double (clock() - start) / CLOCKS_PER_SEC;
            return 0; // it shows that there is no match and the subsets are not unique
        }
    }

    timeAlgo1 = 1000 * double (clock() - start) / CLOCKS_PER_SEC;
    return 1;
}

int findSubsetSortedArrayBinarySearch(int * arr1, int arr1Len , int * arr2, int arr2Len , double & timeAlgo2){
    sort(arr2, arr2 + arr2Len); // Since the sorting is not part of the homework i did use the standart library
    for(int a = 0; a < arr2Len; a++){
        if(binarySearch(arr1, 0, arr1Len - 1, arr2[a],0) == -1){
            return 0;
        }
    }
    return 1;
}

int findSubsetFrequencyTable(int * arr1, int arr1Len , int * arr2, int arr2Len , double & timeAlgo3, int range){
    clock_t start = clock();
    int * arr1FrequencyTable = new int [];

    int * arr1FrequencyTable = new int [range];
    int * arr2FrequencyTable = new int [range];

    for(int a = 0; a < arr1Len; a++){
        arr1FrequencyTable[arr1[a]]++;
    }

    for(int a = 0; a < arr2Len; a++){
        arr2FrequencyTable[arr2[a]]++;
    }

    for(int a = 0; a < arr2Len; a++){
        if(arr2FrequencyTable[arr2[a]] != 0 && arr1FrequencyTable[arr2[a]] == 0){
            timeAlgo3 = 1000 * double(clock() - start) / CLOCKS_PER_SEC;
            return 0;
        }
    }

    timeAlgo3 = 1000 * double(clock() - start) / CLOCKS_PER_SEC;
    return 1;
}

int binarySearch(int arr[], int l, int r, int x, int iterationCount){
    if (r >= l) {

        int mid = l + (r - l) / 2;


        iterationCount++;

        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x, iterationCount);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x, iterationCount);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}




