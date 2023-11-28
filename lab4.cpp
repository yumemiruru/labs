#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void graphic() {
    short n;        /* external cycle parameter */
    double x;
    double y;    /* abscissa and ordinate of the graph */
    short h;        /* the position of the point on the screen */
    HANDLE col;
    col = GetStdHandle(STD_OUTPUT_HANDLE);
        /* external cycle - for 5 periods */
        for (n = 0; n < 5; n++) {
            /* table header output */
            printf("|   x   |      y     |\n");
            printf("|-------|------------|\n");
            /* internal cycle for one period */
            for (x = 0; x < 4; x += 0.25) {
                /* 1st segment */
                if (x < 2) y = -x + 2;
                /* 2nd segment */
                else y = 2 - sqrt(4 - (x - 2) * (x - 2));
                /* table row output */
                printf("| %5.2lf | %10.7lf |", x + n * 4, y);
                /* determining the position of the point */
                h = (y + 1) * 10;
                if (y - 1 - h * 10 > 0.5) h++;
                /* graph point output */
                for (; h > 0; h--) printf(" ");
                SetConsoleTextAttribute(col, 2);
                printf("*\n");
                SetConsoleTextAttribute(col, 15);
            }  /* end of internal cycle */
        }  /* end of outer loop */
    system("pause");
    system("cls");
}

void guess_number() {
    HANDLE col;
    col = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    int random_num = rand() % 11; //generating a random number from 0 to 10
    int guess_n; //guess number
    int attempts = 0; //number of attempts
    cout << "Guess my number! It's between 0 and 10. Give me your assumption\n";
    do {
        SetConsoleTextAttribute(col, 14);
        cin >> guess_n; //guess number input
        SetConsoleTextAttribute(col, 15);
        attempts++; //attempt counter
        if (guess_n < 0) {
            SetConsoleTextAttribute(col, 4);
            cout << "Your number does not belong to the set of given numbers\n";
            SetConsoleTextAttribute(col, 15);
            cout << "Take another guess\n";
        }
        if (guess_n > 10) {
            SetConsoleTextAttribute(col, 4);
            cout << "Your number does not belong to the set of given numbers\n";
            SetConsoleTextAttribute(col, 15);
            cout << "Take another guess\n";
        }
        else if (random_num > guess_n) {
            cout << "Quite wrong. ";
            SetConsoleTextAttribute(col, 6);
            cout << "My number is HIGHER.\n";
            SetConsoleTextAttribute(col, 15);
        }
        else if (random_num < guess_n) {
            cout << "Quite wrong. ";
            SetConsoleTextAttribute(col, 3);
            cout << "My number is LOWER.\n";
            SetConsoleTextAttribute(col, 15);
        }
    } while (random_num != guess_n);
    cout << "Congrats! ";
    SetConsoleTextAttribute(col, 2);
    cout << "You've guessed it right\n";
    SetConsoleTextAttribute(col, 15);
    cout << "Number of tries: ";
    SetConsoleTextAttribute(col, 11);
    cout << attempts << endl;
    SetConsoleTextAttribute(col, 15);
    system("pause");
    system("cls");
}

void mult_t_count() {
    HANDLE col;
    col = GetStdHandle(STD_OUTPUT_HANDLE);
        int correct_answers = 0;
        // initialization of the random number generator
        srand(time(NULL));

        for (int i = 1; i < 11; i++) {
            // generation of random numbers in the range from 2 to 9
            int num1 = 2 + rand() % 8;
            int num2 = 2 + rand() % 8;

            int correct_result = num1 * num2;

            int user_answer;
            cout << "Question:";
            SetConsoleTextAttribute(col, 13);
            cout << i;
            SetConsoleTextAttribute(col, 15);
            cout << " What is ";
            SetConsoleTextAttribute(col, 9);
            cout << num1;
            SetConsoleTextAttribute(col, 15);
            cout << " times ";
            SetConsoleTextAttribute(col, 9);
            cout << num2;
            SetConsoleTextAttribute(col, 15);
            cout << "? ";

            SetConsoleTextAttribute(col, 14);
            cin >> user_answer;
            SetConsoleTextAttribute(col, 15);

            if (user_answer == correct_result) {
                SetConsoleTextAttribute(col, 2);
                cout << "Correct!\n";
                SetConsoleTextAttribute(col, 15);
                correct_answers++;
            }
            else {
                SetConsoleTextAttribute(col, 4);
                cout << "False. ";
                SetConsoleTextAttribute(col, 15);
                cout << "Correct answer: ";
                SetConsoleTextAttribute(col, 3);
                cout << correct_result << endl;
                SetConsoleTextAttribute(col, 15);
            }
        }

        int score;

        switch (correct_answers) {
        case 10:
            score = 5;
            break;
        case 9:
            score = 4;
            break;
        case 8:
        case 7:
            score = 3;
            break;
        default:
            score = 2;
        }

        cout << "Your score: ";
        SetConsoleTextAttribute(col, 11);
        cout << score << endl;
        SetConsoleTextAttribute(col, 15);
        system("pause");
        system("cls");
}

void work_w_num() {
    HANDLE col;
    col = GetStdHandle(STD_OUTPUT_HANDLE);
    int number;
    int num_dst = 0;
    int digit_sum = 0;
    int digit_count = 0;
    int last_digit;

    cout << "Give me your number: ";
    SetConsoleTextAttribute(col, 14);
    cin >> number;
    SetConsoleTextAttribute(col, 15);
    do {
        last_digit = number % 10;
        digit_sum += last_digit;
        num_dst += last_digit;
        num_dst *= 10;
        digit_count++;
        number /= 10;
    } while (number != 0);
    num_dst /= 10;
    cout << "Number written backwards: ";
    SetConsoleTextAttribute(col, 11);
    cout << num_dst << endl;
    SetConsoleTextAttribute(col, 15);
    cout << "Number of digits: ";
    SetConsoleTextAttribute(col, 11);
    cout << digit_count << endl;
    SetConsoleTextAttribute(col, 15);
    cout << "Sum of digits: ";
    SetConsoleTextAttribute(col, 11);
    cout<< digit_sum << endl;
    SetConsoleTextAttribute(col, 15);
    system("pause");
    system("cls");
}

/*void class_w() {
    //дано декілька чисел, перевірити чи є вони додатними
    //перше число інкрементувати (+1) друге подвоїти (*2) треттє декрементувати (-1) незалежн від умови
    int num1 = 0, num2 = -1, num3 = 3;
    //if (++num1 > 0 && (num2 *= 2) > 0 && --num3 > 0) { третя умова не буде перевірена
    //if (++num1 > 0 & (num2 *= 2) > 0 & --num3 > 0) {
        cout << "numbers are positive" << endl;
    }
    else {
        cout << "numbers are negative" << endl;

    }
    cout << num1 << " " << num2 << " " << num3;
}*/


void start_menu() {
    HANDLE col;
    col = GetStdHandle(STD_OUTPUT_HANDLE);
    int menuItems;
    do {
        cout << "1. Show graph " << endl;
        cout << "2. Guess the number " << endl;
        cout << "3. Multiplication table counting " << endl;
        cout << "4. Work with numbers " << endl;
        cout << "0. Exit " << endl;
        cout << "Choose task by its number " << endl;
        SetConsoleTextAttribute(col, 13);
        cin >> menuItems;
        SetConsoleTextAttribute(col, 15);
        switch (menuItems)
        {
        case 1:
            graphic();
            break;

        case 2:
            guess_number();
            break;

        case 3:
            mult_t_count();
            break;

        case 4:
            work_w_num();
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
