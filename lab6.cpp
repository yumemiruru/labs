#include <iostream>
#include <array>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;

void task1() {
    HANDLE col;
    col = GetStdHandle(STD_OUTPUT_HANDLE);
    const int num_rows = 9; // Кількість рядків матриці
    const int num_cols = 9;
    int matrix[num_rows][num_cols];
    int c = 0;
    int n = 0;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_rows; j++) {
            if ((i > j && i + j < num_rows - 1) || (i < j && i + j > num_rows - 1)) {
                matrix[i][j] = ++c;
            }
            else {
                matrix[i][j] = n;
            }
        }
    }
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (matrix[i][j] == n) {
                SetConsoleTextAttribute(col, 3);
            }
            cout<< setw(3) << matrix[i][j];
            if (matrix[i][j] == n) {
                SetConsoleTextAttribute(col, 15);
            }
        }
        cout << endl;
    }
    system("pause");
    system("cls");
}
void task2() {
    HANDLE col;
    col = GetStdHandle(STD_OUTPUT_HANDLE);
    const int num_rows = 5; // Кількість рядків
    const int num_cols = 5; // Кількість стовпців
    int matrix[num_rows][num_cols];
        
 
        std::cout << "Start matrix: " << endl;
        cout << endl;
        srand(time(0));
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                matrix[i][j] = rand() % 100; // Генеруємо випадкове число від 0 до 99
            }
        }
        
        int copiedArray[num_rows][num_cols];

        // Ручне копіювання елементів
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                copiedArray[i][j] = matrix[i][j];
            }
        }

        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {

                std::cout << setw(4) << matrix[i][j] << ' ';
            }
            std::cout << endl;
        }
        cout << endl;
        std::cout << "Matrix after changing elemnts in rows: " << endl;
        cout << endl;
        for (int i = 0; i < num_rows; ++i) {
            int maxVal = matrix[i][0];
            int maxIdx = 0;
            // Знаходження максимального елемента в рядку
            for (int j = 1; j < num_cols; ++j) {
                if (matrix[i][j] > maxVal) {
                    maxVal = matrix[i][j];
                    maxIdx = j;
                }
            }
            int temp = matrix[i][0];
            matrix[i][0] = maxVal;
            matrix[i][maxIdx] = temp;
        }
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (j == 0) {
                    SetConsoleTextAttribute(col, 12);
                }
                std::cout << setw(4) << matrix[i][j] << ' ';
                if (j == 0) {
                    SetConsoleTextAttribute(col, 15);
                }
            }
            std::cout << endl;
        }
        cout << endl;
        std::cout << "Matrix after changing elemnts in columns: " << endl;
        cout << endl;
        for (int j = 0; j < num_cols; ++j) {
            int minVal = copiedArray[0][j];
            int minIdx = 0;
            // Знаходження мінімального елемента в стовпці
            for (int i = 1; i < num_rows; ++i) {
                if (copiedArray[i][j] < minVal) {
                    minVal = copiedArray[i][j];
                    minIdx = i;
                }
            }
            int temp = copiedArray[num_rows - 1][j];
            copiedArray[num_rows - 1][j] = minVal;
            copiedArray[minIdx][j] = temp;
        }

        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (i == 4) {
                    SetConsoleTextAttribute(col, 9);
                }
                std::cout << setw(4) << copiedArray[i][j] << ' ';
                if (i == 4) {
                    SetConsoleTextAttribute(col, 15);
                }
            }
            std::cout << endl;
        }
        system("pause");
        system("cls");
}

void start_menu() {
    HANDLE col;
    col = GetStdHandle(STD_OUTPUT_HANDLE);
    int menuItems;
    do {
        cout << "1. Show special matrix " << endl;
        cout << "2. Show max in rows and min in columns " << endl;
        cout << "0. Exit " << endl;
        cout << "Choose task by its number " << endl;
        SetConsoleTextAttribute(col, 13);
        cin >> menuItems;
        SetConsoleTextAttribute(col, 15);
        switch (menuItems)
        {
        case 1:
            task1();
            break;

        case 2:
            task2();
            break;

        case 0:
            SetConsoleTextAttribute(col, 6);
            cout << "See you next time\n ";
            SetConsoleTextAttribute(col, 15);
            break;

        default:
            SetConsoleTextAttribute(col, 12);
            cout << "Incorrect choice\n";
            SetConsoleTextAttribute(col, 15);
            break;
        }
    } while (menuItems != 0);
}
int main()
{
    start_menu();
}

