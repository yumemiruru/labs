#include <iostream>

using namespace std;

void calcSizeOfType() {
    cout << "Execution lab1...\n";
    cout << "Task 1\n";
    cout << "type int has " << sizeof(int) << " bytes\n";
    cout << "type short has " << sizeof(short) << " bytes\n";
    cout << "type long has " << sizeof(long) << " bytes\n";
    cout << "type char has " << sizeof(char) << " bytes\n";
    cout << "type float has " << sizeof(float) << " bytes\n";
    cout << "type double has " << sizeof(double) << " bytes\n";
    cout << "Completed\n";

    system("pause");
    system("cls");
}

void calc_square() {
    cout << "Task 2\n";
    double a, //first side
        b, //second ..
        c; //third ..
    double p, //half perimeter
        s; //square
    cout << "Input sides of triangle:";
    cin >> a >> b >> c;
    if (a < b + c && b < a + c && c < a + b) {
        p = (a + b + c) / 2;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << "Square of triangle is " << s << endl;
    }
    else {
        cout << "Incorect sides" << endl;
    }
    system("pause");
    system("cls");
}

void calcExp() {
    cout << "Task 3\n";
    int num;//beginner number
    long long num2;//2 exponentional
    long long num4;//4 exp
    long long num8;//8 exp
    cout << "Input source number: ";
    cin >> num;
    num2 = num * num;
    num4 = num2 * num2;
    num8 = num4 * num4;
    cout << num << "^8 = " << num8 << endl;

    system("pause");
    system("cls");

    cout << "Task 3.1\n";
    long long numexp;

    cout << "Input source number: ";
    cin >> numexp;
    numexp = numexp * numexp; //2nd exp
    numexp = numexp * numexp; //4th exp
    numexp = numexp * numexp; //8th exp
    cout << "Your number to the 8th power = " << numexp << endl;

    system("pause");
    system("cls");
}

void change_num() {
    cout << "Task 4 " << endl;
    int var1, //1 variable
        var2; //2 variable
    int temp; //buffer
    cout << "Method 1. With 3rd variable " << endl;
    cout << "Input values of two variables: ";
    cin >> var1 >> var2;
    cout << "Variables before changing: " << var1 << " and " << var2 << endl;
    temp = var1;
    var1 = var2;
    var2 = temp;
    cout << "Variables after changing: " << var1 << " and " << var2 << endl;
    system("pause");
    cout << "Method 2. Without 3rd variable " << endl;
    cout << "Input values of two variables: ";
    cin >> var1 >> var2;
    cout << "Variables before changing: " << var1 << " and " << var2 << endl;
    var1 = var1 + var2; //var1 -> var1 + var2
    var2 = var1 - var2; //var2 -> var1
    var1 = var1 - var2; //var1 -> var2
    cout << "Variables after changing: " << var1 << " and " << var2 << endl;
    system("pause");
    system("cls");
}
void calc_sec();

void start_menu() {
    int menuItems;
    do {
        cout << "1. Task 1. Define size of C++ types " << endl;
        cout << "2. Task 2. Calculate square of triangle " << endl;
        cout << "3. Task 3. Calculate number to the 8th power " << endl;
        cout << "4. Task 4. Replace numbers " << endl;
        cout << "5. Task 5. Calculate number of seconds " << endl;
        cout << "Choose task by its number " << endl;

        cin >> menuItems;

        switch (menuItems)
        {
        case 1:
            calcSizeOfType();
            break;

        case 2:
            calc_square();
            break;

        case 3:
            calcExp();
            break;

        case 4:
            change_num();
            break;

        case 5:
            calc_sec();
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

int main()
{
    
    //int numbytes;
    //numbytes = sizeof(int);
    //numbytes = sizeof(short);
    //numbytes = sizeof(long);
    //numbytes = sizeof(char);
    //numbytes = sizeof(float);
    //numbytes = sizeof(double);
    start_menu();
  
    
}
void calc_sec() {
    cout << "Task 5 " << endl;
    long long  numyear;
    long long  numsec;
    cout << "Input the number of years: " << endl;
    cin >> numyear;
    //numsec = numyear * 31536000;
    numsec = numyear * 60 * 60 * 24 * 365;
    cout << "There are " << numsec << " seconds in " << numyear << " years." << endl;
    system("pause");
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просмаь оки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
