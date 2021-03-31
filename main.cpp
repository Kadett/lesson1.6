#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <algorithm>


using namespace std;


///======================================= start Task 1 functions =====================================///
void initArray(int *arr, int size) {
    int tmp = 0;
    for (int i = 0; i < size; ++i) {
        arr[i] = tmp;
        long tmp2 = tmp * 2 - 1;
        if (tmp2 >= INT32_MAX) { // Проверка на превышение максимального значение INT
            tmp = 1;
        } else {
            tmp *= 2;
        }

    }
}

// Task 1
int getSizeArray() {
    int size = 0;
    while (true) {
        cout << "Enter array size(integer value):\n";
        cin >> size;
        if (cin.fail()) {
            cout << "Error. Please enter integer value:\n";
            cin.clear();
            cin.ignore(INT32_MAX, '\n');

        } else {
            return size;
        }
    }
}

// Task 1
void printArray() {
    int size = getSizeArray();
    int *arr = new int[size];
    initArray(arr, size);

}

///======================================= end Task 1 functions =====================================///


///======================================= start Task 2 functions =====================================///

/// Тут сложнее разбить на несколько функций. Проще было в одной сделать. ))) ///
void create2DArray(int **ptr, int rows) {
    for (int i = 0; i < rows; ++i) {
        ptr[i] = new int[rows];
    }
}

void init2DArray(int **ptr, int columns, int rows) {
    srand(time(0));
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            ptr[i][j] = rand() % 1000;
        }
    }
}

void print2DArray(int **ptr, int columns, int rows) {
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << ptr[i][j] << " ";
        }
        cout << "\n";
    }
}

///======================================= end Task 2 functions =====================================///



///======================================= start Task 3 functions =====================================///
string getFileName() {
    string res;
    cin >> res;
    return res;
}

void createFile(const string &firstFileName, const string &data) {
    ofstream file(firstFileName);
    file << data;
}

///======================================= end Task 3 functions =====================================///

///======================================= start Task 4 functions =====================================///
string readTextFromFile(const string &nameFile) {

    ifstream fin;
    string result;
    fin.open(nameFile);
    if (fin.is_open()) {
        char ch;
        while (fin.get(ch)) {
            result += ch;
        }
    } else {
        cout << "Error. Can not open file " << nameFile << ".\n";
    }
    fin.close();
    return result;
}

bool writeTextToFile(const string &nameFile, const string &data) {
    ofstream fout;
    fout.open(nameFile);
    if (fout.is_open()) {
        fout << data;
        fout.close();
        return true;
    } else {

        fout.close();
        return false;
    }

}

void mergeFiles() {
    string nameFile1, nameFile2, nameFile3, textFile1, textFile2, textFile3;
    cout << "enter file names for merge\n";
    cin >> nameFile1 >> nameFile2;
    cout << "\nenter file name fot result file\n";
    cin >> nameFile3;

    textFile1 = readTextFromFile(nameFile1);
    textFile2 = readTextFromFile(nameFile2);
    textFile3 = textFile1 + textFile2;

    if (writeTextToFile(nameFile3, textFile3)) {
        cout << "writing is ok";
    } else {
        cout << "Error. Can't write to file " << nameFile3 << endl;
    }
}

///======================================= end Task 4 functions =====================================///

///======================================= start Task 5 functions =====================================///
void toLower(string& str){
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return tolower(c); });
}
bool findText() {
    string nameFile, wordForFind, text;
    cout << "enter file name for find:\n";
    cin >> nameFile;
    cout << "enter word for find:\n";
    cin >> wordForFind;
    text = readTextFromFile(nameFile);
    toLower(text);
    toLower(wordForFind);

    int a;
    a = text.find(wordForFind);
    if (a >= 0) {
        cout << "word \"" << wordForFind << "\" is found\n";
        return true;
    } else {
        cout << "word \"" << wordForFind << "\" is not found\n";
        return false;
    }
}

///======================================= end Task 5 functions =====================================///

int main() {

    // Task 1
    printArray();

    // Task 2


    const int columns = 4, rows = 4;
    int ** ptrArray = new int *[columns];
    create2DArray(ptrArray, rows);
    init2DArray(ptrArray, columns, rows);
    print2DArray(ptrArray, columns, rows);



    // Task 3
    string firstFileName, secondFileName;
    firstFileName = getFileName();
    secondFileName = getFileName();
    string str1 = "London is the capital of Great Britain, its political, economic and cultural centre.";
    string str2 = "It's one of the largest cities in the world. Its population is more than million people.";

    createFile(firstFileName, str1);
    createFile(secondFileName, str2);

    // Task 4
    mergeFiles();

    // Task 5

    findText();

    return 0;
}
