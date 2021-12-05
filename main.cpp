
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
#include "math.h"


using namespace std;

int * createArr1(int multiplier, int & length1, int & range);
int * createArr2(int & length2,int range);

void startProcess(ofstream & myFile);
int binarySearch(int arr[], int l, int r, int x);
int findSubsetLinearSearch(int * arr1, int arr1Len, int * arr2, int arr2Len , double & timeAlgo1);
int findSubsetSortedArrayBinarySearch(int * arr1, int arr1Len , int * arr2, int arr2Len , double & timeAlgo2);
int findSubsetFrequencyTable(int * arr1, int arr1Len , int * arr2, int arr2Len , double & timeAlgo3);

int main() {
    
    ofstream myfile;
    myfile.open("NewFile.txt");

    startProcess(myfile);
    myfile.close();
    cout <<  "Project has ended" << endl;
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

        if(isFound == true){
            timeAlgo1 = 1000 * double (clock() - start) / CLOCKS_PER_SEC;
            return 0; // it shows that there is no match and the subsets are not unique
        }
    }

    timeAlgo1 = 1000 * double (clock() - start) / CLOCKS_PER_SEC;
    return 1;
}

int findSubsetSortedArrayBinarySearch(int * arr1, int arr1Len , int * arr2, int arr2Len , double & timeAlgo2){
    sort(arr2, arr2 + arr2Len); // Since the sorting is not part of the homework i did use the standart library
    clock_t start = clock();
    for(int a = 0; a < arr2Len; a++){
        if(binarySearch(arr1, 0, arr1Len - 1, arr2[a]) == -1){
            timeAlgo2 = 1000 * double(clock() - start) / CLOCKS_PER_SEC;
            return 0;
        }
    }
    timeAlgo2 = 1000 * double(clock() - start) / CLOCKS_PER_SEC;
    return 1;
}

int findSubsetFrequencyTable(int * arr1, int arr1Len , int * arr2, int arr2Len , double & timeAlgo3, int range){
    clock_t start = clock();

    int * arr1FrequencyTable = new int [range + 1];
    int * arr2FrequencyTable = new int [range + 1];

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

void startProcess(ofstream & myfile){
    
    double timeAlgo1;
    double timeAlgo2;
    double timeAlgo3;

    int algo1Result;
    int algo2Result;
    int algo3Result;

    int arr1Length;
    int arr2Length;
    int range; 
    
    /*
        Range will be calculated in the createArr1 with pass by reference and reused in the createArr2
        arr1Length and arr2Length both will be used with pass by refence to calculate
    */ 
    for(int a = 1 ; a <= 10; a++){
        int * arr1  = createArr1(a, arr1Length,range);
        sort(arr1, arr1 + arr1Length);
        int * arr2  = createArr2(arr2Length,range);
        algo1Result = findSubsetLinearSearch(arr1, arr1Length, arr2, arr2Length, timeAlgo1);
        algo2Result = findSubsetSortedArrayBinarySearch(arr1, arr1Length, arr2, arr2Length, timeAlgo2);
        algo3Result = findSubsetFrequencyTable(arr1, arr1Length, arr2, arr2Length, timeAlgo3 ,range);

        myfile << "Arr1 Length: " << arr1Length << "\tArr2 Length: " << arr2Length << "\tTime of Algorithm: " << timeAlgo1 << "\t\t\tAlgorithm Result: " << algo1Result << "\n";   
        myfile << "Arr1 Length: " << arr1Length << "\tArr2 Length: " << arr2Length << "\tTime of Algorithm: " << timeAlgo2 << "\t\t\tAlgorithm Result: " << algo2Result << "\n";
        myfile << "Arr1 Length: " << arr1Length << "\tArr2 Length: " << arr2Length << "\tTime of Algorithm: " << timeAlgo3 << "\t\t\tAlgorithm Result: " << algo3Result << "\n";   
        myfile << "\n";

        delete [] arr1;
        delete [] arr2;
    } 
}

int * createArr1(int multiplier, int & arr1Length,int & range){
    arr1Length = multiplier * pow(10,5);
    int * arr1 = new int [arr1Length];
    range = arr1Length; // Setting the range one minus from the  total length of the arr

    for(int a = 0; a < arr1Length; a++){
        int randomDecision = rand() % 2;
        if(randomDecision == 1){
            arr1[a] = (int)(static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * range);
        }

        else{
            arr1[a] = (int)(static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * (range / 2));
        }
    }
    
    return arr1;
}

int * createArr2(int & arr2Length,int range){
    arr2Length = (int) pow(10,3);
    int * result = new int [arr2Length];
    int * rangeArray = new int [range];

    for(int a = 0; a < range; a++){
        rangeArray[a] = a; // Creating our range array to picking fully randomized numbers 
    }

    for(int a = 0; a < arr2Length; a++){
        int r = a + rand() % (range - a);
        result[a] = rangeArray[r];
        rangeArray[r] = rangeArray[a];
    }

    return result;
}




