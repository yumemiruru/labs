#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <windows.h>
using namespace std;
void fill_array(int** two_d_array, int N, int M) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            two_d_array[i][j] = rand() % 99 + 1;
        }
    }
}
void print_array(int** two_d_array, int N, int M) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Original array:\n";
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            SetConsoleTextAttribute(hConsole, 11); 
        }
        else if (i == 1) {
            SetConsoleTextAttribute(hConsole, 13); 
        }
        else if (i == 2) {
            SetConsoleTextAttribute(hConsole, 14);
        }
        for (int j = 0; j < M; j++) {
            cout << setw(4) << two_d_array[i][j] << " ";
        }

        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, 15);
}
// Функція для підрахунку суми позитивних елементів в одному рядку
int calc_row_sum(int* row, int M) {
    int sum = 0;
    for (int j = 0; j < M; j++) {
        if (row[j] > 0) {
            sum += row[j];
        }
    }
    return sum;
}
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int N = 3;  // Кількість рядків
    int M = 3;  // Кількість стовпців
    int** two_d_array = new int* [N];
    for (int i = 0; i < N; i++) {
        two_d_array[i] = new int[N];
    }
    fill_array(two_d_array, N, M);
    print_array(two_d_array, N, M);
    // Застосування функції підрахунку суми до кожного рядка та виведення результатів
    cout << "Sum of positive elements in row: \n";
    for (int i = 0; i < M; i++) {
        int row_sum = calc_row_sum(two_d_array[i], N);
        cout << i + 1 << ": ";
        if (i == 0) {
            SetConsoleTextAttribute(hConsole, 11); 
        }
        else if (i == 1) {
            SetConsoleTextAttribute(hConsole, 13);
        }
        else if (i == 2) {
            SetConsoleTextAttribute(hConsole, 14);
        }
        cout<< row_sum << endl;
        SetConsoleTextAttribute(hConsole, 15);
    }
    
    // Звільнення пам'яті для двовимірного масиву
    for (int i = 0; i < N; i++) {
        delete[] two_d_array[i];
    }
    delete[] two_d_array;
    return 0;
}

