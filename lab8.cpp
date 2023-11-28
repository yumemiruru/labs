#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
void fill_array(int*& dyn_ar, int size);
void process_array(int* dyn_ar, int size, int*& even_arr, int& new_size);

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int size;
    cout << "Enter the size of the array: ";
    SetConsoleTextAttribute(hConsole, 14);
    cin >> size;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    int* array = nullptr;
    int* new_ar = nullptr;
    int new_size;
    fill_array(array,size);

    process_array(array, size, new_ar, new_size);
    delete[] array;
    delete[] new_ar;
}

void fill_array(int*&dyn_ar,int size) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(static_cast<unsigned>(time(0)));

    if (size > 0) {
        dyn_ar = new int[size];
        cout << "Original array:" << endl;
        for (int i = 0; i < size; i++) {
            *(dyn_ar + i) = rand() % 150-50;
            if (*(dyn_ar + i) % 2 == 0) {
                SetConsoleTextAttribute(hConsole, 11);
            }
            cout << setw(5) << *(dyn_ar + i);
            SetConsoleTextAttribute(hConsole, 15);
        }
        cout << endl;
    }
    else {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Invalid array size." << endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout << endl;
    }
}

void process_array(int*dyn_ar, int size, int*&even_arr, int&new_size) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int num_sp = 0;
    for (int i = 1; i < size-1; i++) {
        if (*(dyn_ar+i) > *(dyn_ar+i-1) && *(dyn_ar+i) < *(dyn_ar+i+1)) {
            num_sp++;
        }
    }
    cout << endl;
    cout << "Number of elements ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "greater than the previous";
    SetConsoleTextAttribute(hConsole, 15);
    cout << " and ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "lesser than the next";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<": ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << num_sp << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;

    cout << "New array with ";
    SetConsoleTextAttribute(hConsole, 11);
    cout << "even ";
    SetConsoleTextAttribute(hConsole, 15);
    cout << "elements: " << endl;
    new_size = 0;

    
    for (int i = 0; i < size; i++) {
        if (*(dyn_ar+i) % 2 == 0) {
            new_size++;
        }
    }

    
    even_arr = new int[new_size];

    
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (*(dyn_ar+i) % 2 == 0) {
            even_arr[index++] = *(dyn_ar + i);
        }
    }
    for (int i = 0; i < new_size; i++) {
        cout << setw(5) << *(even_arr + i);
    }
    cout << endl;
}
