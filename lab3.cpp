#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;
void check_coord() { //Task 1 check if the point falls into the given area. check coordinations
    double x;
    double y;/* point coordinates */
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    /* entering coordinates */
    printf("Enter value of the coordinate x: ");
    scanf("%lf", &x);
    printf("Enter value of the coordinate y: ");
    scanf("%lf", &y);
    /* checking conditions */
    if ((x < 0) && (y < 0)) { //coordinate values in the third quarter of the circle
        printf("The point ");
        SetConsoleTextAttribute(h, 5);
        printf("(%.2lf; %.2lf)", x, y);
        SetConsoleTextAttribute(h, 12);
        printf(" does not fall ");
        SetConsoleTextAttribute(h, 15);
        printf("into the given area\n");
    }
    else {
        if (x * x + y * y <= 1) { //the equation of the circle
            printf("The point ");
            SetConsoleTextAttribute(h, 5);
            printf("(%.2lf; %.2lf)", x, y);
            SetConsoleTextAttribute(h, 10);
            printf(" falls ");
            SetConsoleTextAttribute(h, 15);
            printf("into the given area\n");
        }
        else {
            printf("The point ");
            SetConsoleTextAttribute(h, 5);
            printf("(%.2lf; %.2lf)", x, y);
            SetConsoleTextAttribute(h, 12);
            printf(" does not fall ");
            SetConsoleTextAttribute(h, 15);
            printf("into the given area\n");
        }
        
    }
    system("pause");
    system("cls");
}
    
    void quadratic_equation() {
        double a, b, c; //coefficients in the equation
        double x1, x2;  //roots of the equation
        double d; //discriminant
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        printf("Quadratic equation has the following form: ");
        SetConsoleTextAttribute(h, 6);
        printf("a");
        SetConsoleTextAttribute(h, 15);
        printf("x^2+");
        SetConsoleTextAttribute(h, 6);
        printf("b");
        SetConsoleTextAttribute(h, 15);
        printf("x+");
        SetConsoleTextAttribute(h, 6);
        printf("c");
        SetConsoleTextAttribute(h, 15);
        printf("=0\n");
        //inputing values
        printf("enter the value of the coefficient a ");
        SetConsoleTextAttribute(h, 6);
        scanf("%lf", &a);
        SetConsoleTextAttribute(h, 15);
        printf("enter the value of the coefficient b ");
        SetConsoleTextAttribute(h, 6);
        scanf("%lf", &b);
        SetConsoleTextAttribute(h, 15);
        printf("enter the value of the coefficient c ");
        SetConsoleTextAttribute(h, 6);
        scanf("%lf", &c);
        SetConsoleTextAttribute(h, 15);
        d = (b * b) - (4 * a * c); //checking the discriminant value
        if ((d >= 0) && (a!=0) && (b!=0 )) {
            x1 = (-b + sqrt(d)) / 2 * a; //calculating the roots of the eq
            x2 = (-b - sqrt(d)) / 2 * a;
            printf("The roots of the equation are ");
            SetConsoleTextAttribute(h, 10);
            printf("%lf", x1);
            SetConsoleTextAttribute(h, 15);
            printf(" and ");
            SetConsoleTextAttribute(h, 10);
            printf("%lf", x2);
            SetConsoleTextAttribute(h, 15);
        }
        else {
            SetConsoleTextAttribute(h, 15);
            printf("The obtained data ");
            SetConsoleTextAttribute(h, 12);
            printf("do not correspond ");
            SetConsoleTextAttribute(h, 15);
            printf("to the values of the quadratic equation");
        }
        system("pause");
        system("cls");
    }
    void start_menu() {
        int menuItems;
        do {
            cout << "1. Task 1. Check if the point falls into the given area " << endl;
            cout << "2. Task 2. Calculate the roots of the quadratic equation " << endl;
            cout << "0. Exit " << endl;

            cin >> menuItems;

            switch (menuItems)
            {
            case 1:
                check_coord();
                break;

            case 2:
                quadratic_equation();
                break;

            case 0:
                cout << "See you next time ";
                break;

            default:
                cout << "Incorrect choice";
                break;
            }
        } while (menuItems != 0);
    }


int main() {
    start_menu();
}

