
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
 *  ----------------------------------------------------------------------------
 */

#include <iostream>
#include "ctime"
#include "algorithm"


using namespace std;

int binarySearch(int arr[], int l, int r, int x, int iterationCount);
int findSubsetLinearSearch(int * arr1, int arr1Len, int * arr2, int arr2Len , clock_t & timeAlgo1);
int findSubsetSortedArrayBinarySearch(int * arr1, int arr1Len , int * arr2, int arr2Len , clock_t & timeAlgo2);
int findSubsetFrequencyTable(int * arr1, int arr1Len , int * arr2, int arr2Len , clock_t & timeAlgo3);

int main() {
    
    int arr [] = {1,2,3,7,9,11,121,132};

    if(binarySearch(arr,0, 8 ,11, 0)){
        cout << "Element is found " << endl;
    }

    else {
        cout << "Element is not found " << endl;
    }

}

int findSubsetLinearSearch(int * arr1, int arr1Len, int * arr2, int arr2Len , clock_t & timeAlgo1){
    for(int a = 0; a < arr2Len; a++){
        bool isFound = false;
        
        for(int b = 0; b < arr1Len; b++){
            if(arr1[b] == arr2[a]){
                isFound = true;
                break;
            }
        }

        if(isFound == false){
            return 0; // it shows that there is no match and the subsets are not unique
        }
    }
    return 1;
}

int findSubsetSortedArrayBinarySearch(int * arr1, int arr1Len , int * arr2, int arr2Len , clock_t & timeAlgo2){
    sort(arr2, arr2 + arr2Len); // Since the sorting is not part of the homework i did use the standart library
}

int findSubsetFrequencyTable(int * arr1, int arr1Len , int * arr2, int arr2Len , clock_t & timeAlgo3){

}

int binarySearch(int arr[], int l, int r, int x, int iterationCount)
{
    if (r >= l) {

        int mid = l + (r - l) / 2;

        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "Iteration number is: " << iterationCount << endl;
        cout << "pivot point element number is: " << mid << endl;
        cout << "pivot point element choosed is: " << arr[mid] << endl;
        cout << "-----------------------------------------------------------------------------" << endl;

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




