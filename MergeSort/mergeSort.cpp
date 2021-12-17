#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

void fileToString(int argc, char** argv, ifstream& ReadFile);
void fileToVector(ifstream& ReadFile, vector<int>& numVector);
void mergeSort(vector<int>& numVector, int left, int right);
void _merge(vector<int>& numVector, int left, int middle, int right);

int main(int argc, char** argv) {
    
    ifstream ReadFile;
    fileToString(argc, argv, ReadFile);

    vector<int> numVector;

    fileToVector(ReadFile, numVector);

    cout << "Before Sorting: " << endl;
    for (auto &i : numVector) {
        cout << i << " ";
    }
    cout << endl;
    cout << "After Sorting: " << endl;


    mergeSort(numVector, 0, numVector.size() - 1);

    for (auto &i : numVector) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

void fileToString(int argc, char** argv, ifstream& ReadFile) {
    if (argc < 2) {
        cout << "No file input, terminating..." << endl;
        exit(0);
    }

    if (argc > 2) {
        cout << "Only one file allowed, terminating..." << endl;
        exit(0);
    }

    ReadFile.open(argv[1]);

    if (!ReadFile.is_open()) {
        cout << "Could not find file: " << argv[1] << endl;
        exit(0);
    }
}

void fileToVector(ifstream& ReadFile, vector<int>& numVector) {
    string input;

    while (std::getline(ReadFile, input, ' ')) {
        try {
            numVector.push_back(std::stoi(input));
        }
        catch (std::invalid_argument &e) {
            cout << "Invalid argument " << input << "found, terminating..." << endl;
            exit(0);
        }
        catch (std::out_of_range &e) {
            cout << input << " is out of range, terminating..." << endl;
            exit(0);
        }
        catch (std::exception &e) {
            cout << "Exception encountered, terminating..." << endl;
            exit(0);
        }
    }
}

void mergeSort(vector<int>& numVector, int left, int right) {
    if (left >= right) {
       return;
    }

    int middle = left + ((right - left) / 2);

    mergeSort(numVector, left, middle);
    mergeSort(numVector, middle + 1, right);
    _merge(numVector, left, middle, right);

    return;
}

void _merge(vector<int>& numVector, int left, int middle, int right) {
    vector<int> leftVector;
    vector<int> rightVector;

    for (int i = left; i <= right; i++) {
        if (i <= middle) {
            leftVector.push_back(numVector[i]);
        }
        else {
            rightVector.push_back(numVector[i]);
        }
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = left;

    
    while (leftIndex < leftVector.size() && rightIndex < rightVector.size()) {
        if (leftVector[leftIndex] < rightVector[rightIndex]) {
            numVector[mainIndex] = leftVector[leftIndex];
            leftIndex++;
        }
        else {
            numVector[mainIndex] = rightVector[rightIndex];
            rightIndex++;
        }
        mainIndex++;
    }

    if (leftIndex < leftVector.size()) {
        while (leftIndex < leftVector.size()) {
            numVector[mainIndex] = leftVector[leftIndex];
            leftIndex++;
            mainIndex++;
        }
    }

    if (rightIndex < rightVector.size()) {
        while (rightIndex < rightVector.size()) {
            numVector[mainIndex] = rightVector[rightIndex];
            rightIndex++;
            mainIndex++;
        }
    }

    return;
}