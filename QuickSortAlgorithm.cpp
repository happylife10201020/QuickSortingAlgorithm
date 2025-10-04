//
// Created by Lee on 25. 10. 4.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class SortArray {
public:
    vector<int> Array;
    string inputFileName, outputFileName;
    vector<int> coppyArray1, coppyArray2, coppyArray3;
    vector<int> sorted1, sorted2, sorted3;
    int length ;

    void getData(const string &filename) ;

    void QuickSort(int low, int high) ;
    void RandomQuickSort(int low, int high) ;
    void ThreeQuickSort(int low, int high) ;
};

int main() {
    SortArray array;
    array.inputFileName = "input.txt";
    array.outputFileName = "output.txt";

    array.getData(array.inputFileName);
    array.QuickSort(0, array.length - 1);
    array.RandomQuickSort(0, array.length - 1);
    array.ThreeQuickSort(0, array.length - 1);
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
    int key = coppyArray1[low] ;

}

void SortArray::RandomQuickSort(int low, int high) {

}

void SortArray::ThreeQuickSort(int low, int high) {

}