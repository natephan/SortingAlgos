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
void insertionSort(vector<int>& numVector);

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


    insertionSort(numVector);

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

void insertionSort(vector<int>& numVector) {
    for (int i = 1; i < numVector.size(); i++) {
        int j = i;
        while (numVector[j] < numVector[j - 1]) {
            int temp = numVector[j];
            numVector[j] = numVector[j - 1];
            numVector[j - 1] = temp;
            j--;
            if (j == 0) {
                break;
            }
        }
    }
}