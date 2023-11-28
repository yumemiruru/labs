#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <windows.h>
int main() {
	setlocale(LC_ALL, "Ukrainian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color 5F");
	HANDLE h; //link on the window of the console
	char name1[7], name2[10], name3[11];
	char manun1[10], manun2[6], manun3[4];
	int nop1, nop2, nop3;
	int price1, price2, price3;
	h = GetStdHandle(STD_OUTPUT_HANDLE); //set link on the standart console
	SetConsoleTextAttribute(h, 14);
	/* Введення фактичних даних */
	printf("1. Введіть: назву, виробника, к-ть складових частин, ціну: ");
	SetConsoleTextAttribute(h, 9);
	scanf("%s %s %d %d", name1, manun1, &nop1, &price1);
	SetConsoleTextAttribute(h, 14);
	printf("2. Введіть: назву, виробника, к-ть складових частин, ціну: ");
	SetConsoleTextAttribute(h, 9);
	scanf("%s %s %d %d", name2, manun2, &nop2, &price2);
	SetConsoleTextAttribute(h, 14);
	printf("3. Введіть: назву, виробника, к-ть складових частин, ціну: ");
	SetConsoleTextAttribute(h, 9);
	scanf("%s %s %d %d", name3, manun3, &nop3, &price3);
	SetConsoleTextAttribute(h, 14);
	/* Виведення таблиці */ /* Виведення заголовків */
	SetConsoleTextAttribute(h, 8);
	printf("-----------------------------------------------------------------\n");
	printf("|");
	SetConsoleTextAttribute(h, 4);
	printf("Офісні пакети                                                 ");
	SetConsoleTextAttribute(h, 8);
	printf(" | \n");
	//printf("|Офісні пакети                                                  |\n");
	
	SetConsoleTextAttribute(h, 8);
	printf("|---------------------------------------------------------------|\n");
	SetConsoleTextAttribute(h, 5);
	printf("|   Найменування  |  Виробник | Кількість складових  | Ціна ($) |\n");
	printf("|                 |           |        частин        |          |\n");
	SetConsoleTextAttribute(h, 8);
	printf("|-----------------|-----------|----------------------|----------|\n");
	SetConsoleTextAttribute(h, 10);
	/* виведення рядків фактичних даних */
	printf("| %15s | %9s | %-20d | %8d |\n", name1, manun1, nop1, price1);
	printf("| %15s | %9s | %-20d | %8d |\n", name2, manun2, nop2, price2);
	printf("| %15s | %9s | %-20d | %8d |\n", name3, manun3, nop3, price3);
	/* виведення приміток */
	SetConsoleTextAttribute(h, 8);
	printf("|---------------------------------------------------------------|\n");
	SetConsoleTextAttribute(h, 3);
	printf("|Примітка: можливо безкоштовно отримати продукт StarOffice      |\n");
	printf("|          через Internet                                       |\n");
	SetConsoleTextAttribute(h, 8);
	printf("-----------------------------------------------------------------\n");
	return 0;
}
//Office Microsoft 4 870
//SmartSute Lotus 5 1020
//StarOffice Sun 4 9