#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <array>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//int random(int from, int to);

void opp_w_mas() {
    const int arraySize = 15;
    int numbersar[arraySize];

    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < arraySize; i++) {
        numbersar[i] = rand() % 101 - 50; // Генеруємо від -50 до 50
    }
    int copiedArray[arraySize]; // Створюємо копію масиву

    copy(numbersar, numbersar + arraySize, copiedArray);
    int min_element = copiedArray[0];
    for (int i = 1; i < arraySize; i++) {
        if (copiedArray[i] < min_element) {
            min_element = copiedArray[i];
        }
    }
    // Виводимо копію масиву
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Original array: " << endl;
    for (int i = 0; i < arraySize; i++) {
        if (copiedArray[i] == min_element) {
            SetConsoleTextAttribute(h, 4); // Змінити колір на червоний для найменшого елемента
        }
        cout << copiedArray[i] << " ";
        SetConsoleTextAttribute(h, 15);
    }
    cout << endl;
    // Знаходження найбільшого за абсолютним значенням від'ємного числа
    int max_negative = 0;
    for (int i = 0; i < arraySize; i++) {
        int num = numbersar[i];
        if (num < 0 && abs(num) > abs(max_negative)) {
            max_negative = num;
        }
    }

    // Заміна всіх додатніх чисел на абсолютне значення max_negative
    for (int i = 0; i < arraySize; i++) {
        if (numbersar[i] > 0) {
            numbersar[i] = abs(max_negative);
        }
    }

    // Виведення початкового та зміненого масиву
    cout << "Changed array: " << endl;
    for (int i = 0; i < arraySize; i++) {
        if (numbersar[i] > 0) {
            SetConsoleTextAttribute(h, 2); // Змінити колір на зелений для додатніх елементів
        }
        cout << numbersar[i] << " ";
        SetConsoleTextAttribute(h, 15);
    }
    cout << endl;
    system("pause");
    system("cls");
}

void plane_seat_reservation() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    const int totalSeats = 10;
    const int smokingSeats = 5;
    srand(time(0));
    bool seats[totalSeats] = { false };  // Масив для зберігання стану місць (false - вільно, true - зайнято)

    while (true) {
        cout << endl;
        cout << "Reservation of seats on the plane:" << endl;
        cout << "Are you smoking? (";
        SetConsoleTextAttribute(h, 12);
        cout << "yes = y ";
        SetConsoleTextAttribute(h, 15);
        cout << "/";
        SetConsoleTextAttribute(h, 11);
        cout << " no = n";
        SetConsoleTextAttribute(h, 15);
        cout<<"): ";

        string choice;
        SetConsoleTextAttribute(h, 14);
        cin >> choice;
        SetConsoleTextAttribute(h, 15);

        bool isSmoking = (choice == "y");

        int startSeat = (isSmoking) ? 0 : smokingSeats;
        int endSeat = (isSmoking) ? smokingSeats : totalSeats;

        bool seatsAvailable = false;

        for (int seat = startSeat; seat < endSeat; seat++) {
            if (!seats[seat]) {
                seats[seat] = true;
                seatsAvailable = true;
                break;
            }
        }

        if (seatsAvailable) {
            SetConsoleTextAttribute(h, 2);
            cout << "Reservated successfuly!" << endl;
            SetConsoleTextAttribute(h, 15);
            cout << endl;
            cout << "General condition of seats:" << endl;
            for (int seat = 0; seat < totalSeats; seat++) {
                if (seat == smokingSeats) {
                    SetConsoleTextAttribute(h, 12);
                    cout << "  <-smoking";
                    SetConsoleTextAttribute(h, 11);
                    cout << "  non-smoking->  "; // Виводимо пробіл для розділення секторів
                    SetConsoleTextAttribute(h, 15);
                }
                cout << seats[seat] << " ";
            }
        cout << endl;
        }
        else {
            cout << endl;
            SetConsoleTextAttribute(h, 4);
            cout << "Out of seats." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "Do you want to proceed reservation on another plane? (";
            SetConsoleTextAttribute(h, 11);
            cout << "yes = y ";
            SetConsoleTextAttribute(h, 15);
            cout << "/";
            SetConsoleTextAttribute(h, 12);
            cout << " no = n";
            SetConsoleTextAttribute(h, 15);
            cout << "): ";
            SetConsoleTextAttribute(h, 14);
            cin >> choice;
            SetConsoleTextAttribute(h, 15);

            if (choice != "y") {
                cout << endl;
                cout << "Thank you. See you next time!" << endl;
                break;
                system("clear");
                system("cls");
            }
            else if (choice == "y") {
                for (int seat = 0; seat < totalSeats; seat++) {
                    seats[seat] = 0;
                }
            }
        }
    }
    system("pause");
    system("cls");
}



void start_menu() {
    HANDLE col;
    col = GetStdHandle(STD_OUTPUT_HANDLE);
    int menuItems;
    do {
        cout << "1. Change positive array values " << endl;
        cout << "2. Reservation of seats on the plane " << endl;
        cout << "3. Array work " << endl;
        cout << "0. Exit " << endl;
        cout << "Choose task by its number " << endl;
        SetConsoleTextAttribute(col, 13);
        cin >> menuItems;
        SetConsoleTextAttribute(col, 15);
        switch (menuItems){
        case 1:
            opp_w_mas();
            break;

        case 2:
            plane_seat_reservation();
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

int main(void) {
    start_menu();
}