#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <windows.h>
using namespace std;
#define N 3
#define M 3
void func(int mas1[]);

int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int mas1[N * M];
srand(static_cast<unsigned>(time(nullptr)));
for (int i = 0; i < N*M; i++)
{
	mas1[i]=rand() % 99 + 1;
}
SetConsoleTextAttribute(hConsole, 10);
cout << "Original ";
SetConsoleTextAttribute(hConsole, 15);
cout << "one - dimensional array: " << endl;
	for (int i = 0; i < N * M; i++) {
		cout << setw(4) << mas1[i];
	}
	cout << endl;
	func(mas1);
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\nNew one-dimensional array ";
    SetConsoleTextAttribute(hConsole, 15);
    cout<< "after increasing values of its elements : " << endl;
	for (int i = 0; i < N * M; i++) {
		cout << setw(4) << mas1[i];
	}
	cout << endl;
}

void func(int mas1[]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int mas2[N][M];
    cout << "\nOriginal array to ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "two-dimensional array";
    SetConsoleTextAttribute(hConsole, 15);
    cout<< ":" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mas2[i][j] = mas1[i * M + j];
            if (i == 0) {
                SetConsoleTextAttribute(hConsole, 11);
            }
            else if (i == 1) {
                SetConsoleTextAttribute(hConsole, 13);
            }
            else if (i == 2) {
                SetConsoleTextAttribute(hConsole, 14);
            }
            cout << setw(4) << mas2[i][j] << " ";
            SetConsoleTextAttribute(hConsole, 15);
        }
        cout << endl;
    }
    cout << "\nTwo-dimensional array ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "after increasing values of its elements";
    SetConsoleTextAttribute(hConsole, 15);
    cout << ": " << endl;
    for (int i = 0; i < N; ++i) {
        int max_val = mas2[i][0];

        // Знаходження максимального елемента в рядку
        for (int j = 1; j < M; j++) {
            if (mas2[i][j] > max_val) {
                max_val = mas2[i][j];
            }

        }
        for (int j = 0; j < M; ++j) {
            mas2[i][j] += max_val;
        }

    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0) {
                SetConsoleTextAttribute(hConsole, 11);
            }
            else if (i == 1) {
                SetConsoleTextAttribute(hConsole, 13);
            }
            else if (i == 2) {
                SetConsoleTextAttribute(hConsole, 14);
            }
            cout << setw(4) << mas2[i][j] << " ";
            SetConsoleTextAttribute(hConsole, 15);
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mas1[i * M + j] = mas2[i][j];
        }
    }
    cout << endl;
}

