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
void quickSort(vector<int>& numVector, int left, int right);
int partition(vector<int>& numVector, int left, int right);

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


    quickSort(numVector, 0, numVector.size() - 1);

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

void quickSort(vector<int>& numVector, int left, int right) {
    if (left >= right) {
       return;
    }

    int partitionIndex = partition(numVector, left, right);

    quickSort(numVector, left, partitionIndex - 1);
    quickSort(numVector, partitionIndex  + 1, right);

    return;
}

int partition(vector<int>& numVector, int left, int right) {
    int pivot = numVector[right];
    int i = left - 1;

    for (int j = left; j <= right; j++) {
        if (numVector[j] < pivot) {
            i++;
            int temp = numVector[j];
            numVector[j] = numVector[i];
            numVector[i] = temp;
        }
    }

    int temp = numVector[i + 1];
    numVector[i + 1] = numVector[right];
    numVector[right] = temp;
    return i + 1;
}