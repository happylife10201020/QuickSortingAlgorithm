//
// Created by Lee on 25. 10. 4.
//

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
    vector<int> coppyArray1, coppyArray2, coppyArray3;
    int length ;

    void getData(const string &filename) ;

    void QuickSort(int low, int high) ;
    void RandomQuickSort(int low, int high) ;
    void ThreeQuickSort(int low, int high) ;

    void PrintArray(const vector<int> &array) ;
};

int main() {
    srand(time(NULL)) ;

    SortArray array;
    array.inputFileName = "input.txt";
    array.outputFileName = "output.txt";

    array.getData(array.inputFileName);
    array.QuickSort(0, array.length - 1);
    array.RandomQuickSort(0, array.length - 1);
    array.ThreeQuickSort(0, array.length - 1);

    array.PrintArray(array.coppyArray1);
    array.PrintArray(array.coppyArray2);
    array.PrintArray(array.coppyArray3);
}

void SortArray::getData(const string &filename) {
    ifstream inputFile;
    inputFile.open(filename);

    if (!inputFile.is_open()) {
        cerr << "Error opening file " << filename << endl;
        exit(1);
    }

    inputFile >> length ;
    for (int i = 0; i < length; i++) {
        int data ;
        if (inputFile >> data) {
            Array.push_back(data) ;
        } else {
            cout << "Error reading data from file " << filename << endl;
            cout << "NOT ENOUGH NUMBERS" << endl;
            exit(1);
        }
    }
    coppyArray1 = Array ;
    coppyArray2 = Array ;
    coppyArray3 = Array ;

    inputFile.close();
}

void SortArray::QuickSort(int low, int high) {
    if (low >= high)
        return;

    int pivot = coppyArray1[high] ;
    int i = low - 1 ;
    for (int j = low; j <= high - 1 ; j++) {
        if (coppyArray1[j] <= pivot) {
            i++ ;
            swap(coppyArray1[j], coppyArray1[i]) ;
        }
    }
    swap(coppyArray1[high], coppyArray1[i + 1]) ;
    QuickSort(low, i);
    QuickSort(i + 2, high) ;
}

void SortArray::RandomQuickSort(int low, int high) {
    if (low >= high)
        return;

    int random = low + rand() % (high - low + 1) ;
    int pivot = coppyArray2[random] ;
    swap(coppyArray2[high], coppyArray2[random]) ;
    int i = low - 1 ;
    for (int j = low; j <= high - 1 ; j++) {
        if (coppyArray2[j] <= pivot) {
            i++ ;
            swap(coppyArray2[j], coppyArray2[i]) ;
        }
    }
    swap(coppyArray2[high], coppyArray2[i + 1]) ;
    RandomQuickSort(low, i);
    RandomQuickSort(i + 2, high) ;
}

void SortArray::ThreeQuickSort(int low, int high) {

}

void SortArray::PrintArray(const vector<int> &array) {
    static ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cout << "ERROR OPENING OUTPUT FILE" << endl;
        exit(1);
    }
    outputFile << array[0] ;
    for (int i = 1; i < array.size(); i++) {
        outputFile << " " << array[i] ;
    }

    if (!(array == coppyArray3)) {
        outputFile << endl ;
    }else {
        outputFile.close() ;
    }
}