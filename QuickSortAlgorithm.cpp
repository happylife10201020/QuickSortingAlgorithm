//
// Created by Lee on 25. 10. 4.
//
// https://github.com/happylife10201020/QuickSortingAlgorithm

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


class SortArray {
public:
    vector<int> Array;
    string inputFileName, outputFileName;
    ifstream inputFile;
    ofstream outputFile;
    vector<int> copyArray1, copyArray2, copyArray3;
    int length ;

    SortArray(const string &inputFileName, const string &outputFileName); ;
    void getData() ;

    void QuickSort(int low, int high) ;
    void RandomQuickSort(int low, int high) ;
    void ThreeQuickSort(int low, int high) ;

    ~SortArray() ;
};

SortArray::SortArray(const string &inputFileName, const string &outputFileName) {
    this->inputFileName = inputFileName;
    this->outputFileName = outputFileName;

    inputFile.open(inputFileName);
    outputFile.open(outputFileName);

    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << inputFileName << endl;
        exit(1);
    }
    if (!outputFile.is_open()) {
        cerr << "Error opening output file: " << outputFileName << endl;
        inputFile.close();
        exit(1);
    }

    getData();
    QuickSort(0, length - 1);
    RandomQuickSort(0, length - 1);
    ThreeQuickSort(0, length - 1);
}


void SortArray::getData() {
    inputFile >> length ;
    for (int i = 0; i < length; i++) {
        int data ;
        if (inputFile >> data) {
            Array.push_back(data) ;
        } else {
            cout << "Error reading data from file " << inputFileName << endl;
            cout << "NOT ENOUGH NUMBERS" << endl;
            exit(1);
        }
    }
    copyArray1 = Array ;
    copyArray2 = Array ;
    copyArray3 = Array ;
}

void SortArray::QuickSort(int low, int high) {
    if (low >= high)
        return;

    int pivot = copyArray1[high] ;
    int i = low - 1 ;
    for (int j = low; j <= high - 1 ; j++) {
        if (copyArray1[j] <= pivot) {
            i++ ;
            swap(copyArray1[j], copyArray1[i]) ;
        }
    }
    swap(copyArray1[high], copyArray1[i + 1]) ;
    QuickSort(low, i);
    QuickSort(i + 2, high) ;
}

void SortArray::RandomQuickSort(int low, int high) {
    if (low >= high)
        return;

    int random = low + rand() % (high - low + 1) ;
    int pivot = copyArray2[random] ;
    swap(copyArray2[high], copyArray2[random]) ;
    int i = low - 1 ;
    for (int j = low; j <= high - 1 ; j++) {
        if (copyArray2[j] <= pivot) {
            i++ ;
            swap(copyArray2[j], copyArray2[i]) ;
        }
    }
    swap(copyArray2[high], copyArray2[i + 1]) ;
    RandomQuickSort(low, i);
    RandomQuickSort(i + 2, high) ;
}

void SortArray::ThreeQuickSort(int low, int high) {
    if (low >= high)
        return;

    int randArray[3] ;
    int random ;
    for (int i = 0; i<3; i++)
        randArray[i] = low + rand() % (high - low + 1) ;

    for (int i = 0; i<3; i++) {
        for (int j = i + 1; j<3; j++) {
            if (copyArray3[randArray[i]] > copyArray3[randArray[j]]) {
                swap(randArray[i], randArray[j]) ;
            }
        }
    }
    random = randArray[1] ;

    int pivot = copyArray3[random] ;
    swap(copyArray3[high], copyArray3[random]) ;
    int i = low - 1 ;
    for (int j = low; j <= high - 1 ; j++) {
        if (copyArray3[j] <= pivot) {
            i++ ;
            swap(copyArray3[j], copyArray3[i]) ;
        }
    }
    swap(copyArray3[high], copyArray3[i + 1]) ;
    ThreeQuickSort(low, i);
    ThreeQuickSort(i + 2, high) ;
}

SortArray::~SortArray() {
    const vector<int>* arrays[] = {&copyArray1, &copyArray2, &copyArray3};
    for (int i = 0; i < 3; i++) {
        const vector<int>& currentArray = *arrays[i];

        outputFile << currentArray[0] ;
        for (int j = 1; j < currentArray.size(); j++) {
            outputFile << " " << currentArray[j] ;
        }
        if (i < 2) {
            outputFile << endl ;
        }
    }

    inputFile.close() ;
    outputFile.close() ;
}



int main() {
    srand(time(NULL)) ;

    SortArray array("input.txt", "output.txt");

    return 0 ;
}