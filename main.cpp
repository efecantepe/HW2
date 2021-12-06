
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
int * createArr2(int & length2,int range, int powerMultiplier);
int * createArr1(int multiplier, int & length1, int & range, int nothing);

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
    
    /* 
        When the program produce the timeAlgo1 as the output 0 we will send multiple loops to produce 
        correct result 
    */

   int c;

    double timeResult = 0;
    int returnResult = 1;

    clock_t start = clock();
    for(c = 1 ; c <= 1; c++){ // One loop is enough but just for test I added one more loop.
        for(int a = 0; a < arr2Len; a++){
            bool isFound = false;
            for(int b = 0; b < arr1Len; b++){
                if(arr2[a] == arr1[b]){
                   isFound = true;     
                }
            }

        }
    }
        
    timeAlgo1 = double((clock() - start) / (double) c);
    return returnResult;
}

int findSubsetSortedArrayBinarySearch(int * arr1, int arr1Len , int * arr2, int arr2Len , double & timeAlgo2){
    sort(arr2, arr2 + arr2Len); // Since the sorting is not part of the homework i did use the standart library
    int result = 1;
    clock_t start = clock();
    int c;

    for(c = 1; c <= 40; c++){
        for(int a = 0; a < arr1Len; a++){
        if(binarySearch(arr2, 0, arr2Len - 1, arr1[a]) == -1){
            timeAlgo2 = 1000 * (double (clock() - start) / CLOCKS_PER_SEC);
            result = 1;
            }
        }
    }

   
    timeAlgo2 = (1000 * (double(clock() - start) / CLOCKS_PER_SEC)) / c;
    return result;
}

int findSubsetFrequencyTable(int * arr1, int arr1Len , int * arr2, int arr2Len , double & timeAlgo3, int range){
    clock_t start = clock();
    int result = 1;
    int biggestNumber = arr1[0];

    int c;

    for(c = 1; c <= 40; c++){

        for(int a = 1; a < arr1Len; a++){

            if(arr1[a] > biggestNumber){
                biggestNumber = arr1[a];
            }

        }
        
        int * frequencyTable = new int[biggestNumber + 1];

        for(int a = 0; a < arr1Len; a++){
            frequencyTable[arr1[a]]++;
        }

        for(int a = 0; a < arr2Len; a++){
            if(frequencyTable[arr2[a]] == 0){
                result = 0;
            }
            frequencyTable[arr2[a]]--;
        }

    }

    

    timeAlgo3 = (1000 * (double) (clock() - start) / CLOCKS_PER_SEC) / c;   
    return result;
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
    double timeAlgo4;
    double timeAlgo5;
    double timeAlgo6;

    int algo1Result;
    int algo2Result;
    int algo3Result;
    int algo4Result;
    int algo5Result;
    int algo6Result;

    int arr1Length;
    int arr2Length;
    int arr3Length;
    int range; 
    
    /*
        Range will be calculated in the createArr1 with pass by reference and reused in the createArr2
        arr1Length and arr2Length both will be used with pass by refence to calculate
    */ 
    for(int a = 1 ; a <= 10; a++){
        int * arr1  = createArr1(a, arr1Length,range);
        sort(arr1, arr1 + arr1Length);
        int * arr2  = createArr2(arr2Length,range, 0);
        int * arr3  = createArr2(arr3Length, range, 1);

        /*
            Different implementation of all algorithms and all range varieties
        */

        algo1Result = findSubsetLinearSearch(arr1, arr1Length, arr2, arr2Length, timeAlgo1);
        algo2Result = findSubsetSortedArrayBinarySearch(arr1, arr1Length, arr2, arr2Length, timeAlgo2);
        algo3Result = findSubsetFrequencyTable(arr1, arr1Length, arr2, arr2Length, timeAlgo3 ,range);
        algo4Result = findSubsetLinearSearch(arr1, arr1Length, arr3, arr3Length, timeAlgo4);
        algo5Result = findSubsetSortedArrayBinarySearch(arr1, arr1Length, arr2, arr2Length, timeAlgo5);
        algo6Result = findSubsetFrequencyTable(arr1, arr1Length, arr2, arr2Length, timeAlgo6, range);


        myfile <<  arr1Length << "\n" << arr2Length << "\n" << timeAlgo1 << "\n"<< "**********************\n"  
               <<  arr1Length << "\n" << arr2Length << "\n" << timeAlgo2 << "\n"<< "**********************\n"   
               <<  arr1Length << "\n" << arr2Length << "\n" << timeAlgo3 << "\n"<< "**********************\n"  
               <<  arr1Length << "\n" << arr3Length << "\n" << timeAlgo4 << "\n"<< "**********************\n"  
               <<  arr1Length << "\n" << arr3Length << "\n" << timeAlgo5 << "\n"<< "**********************\n"  
               <<  arr1Length << "\n" << arr3Length << "\n" << timeAlgo6 << "\n"<< "**********************\n"; 
               
        delete [] arr1;
        delete [] arr2;
        cout << "Cycle "  << a << endl;
    } 
}

int * createArr1(int multiplier, int & arr1Length,int & range){
    arr1Length = multiplier * pow(10,6);
    int * arr1 = new int [arr1Length];
    range = arr1Length; // Setting the range one minus from the  total length of the arr

    for(int a = 0; a < arr1Length; a++){
        int randomDecision = rand() % 2; // For increasing the randomness of the algorithm
        if(randomDecision == 1){
            arr1[a] = (int)(static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * range);
        }

        else{
            arr1[a] = (int)(static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * (range / 2));
        }
    }
    
    return arr1;
}

int * createArr2(int & arr2Length,int range, int powerMultiplier){
    arr2Length = (int) pow(10,3 + powerMultiplier);
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

int * createArr1(int multiplier, int & arr1Length, int & range, int nothing){
    arr1Length = multiplier * pow(10,5);
    range = arr1Length;
    int * result = new int [arr1Length];
    int * pickArray = new int [arr1Length];

    for(int a = 0; a < arr1Length; a++){
        pickArray[a] = a;
    }

    for(int a = 0; a < arr1Length; a++){
        int r = a + rand() % (arr1Length - a);
        result[a] = pickArray[r];
        pickArray[r] = pickArray[a];
    }

    return result;

}




