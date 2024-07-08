// basalgs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <locale.h>
#include "BasAlgs.h"

using namespace std;
int endofmenu = 0, pressed_enter = 0;

void menu(string* name, int n, int id) {
	system("cls");
	int code = 0;
	for (int i = 0; i < n; i++) {
		if (i == id) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << "> " << name[i] << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		}
		else {
			cout << name[i] << endl;
		}
	}
}


int input(int n, int id) {
	int keycode = _getch();
	if (keycode == 224) {
		keycode = _getch();
	}

	switch (keycode) {
	case 72:
		id -= 1;
		if (id < 0) {
			id = n - 1;
		}
		break;
	case 80:
		id += 1;
		if (id == n) {
			id = 0;
		}
		break;
	case 13:
		system("cls");
		keycode = 0;
		switch (id) {
		case 0: {
			int* a, n, sum;
			cout << "Количество чисел: ";
			cin >> n;
			a = new int[n];
			cout << "Числа: ";
			for (int i = 0; i < n; i++) {
				cin >> a[i];
			}
			sum = basalg1(a, n);
			cout << "Сумма: " << sum;
			while (keycode != 13) {
				keycode = _getch();
			}
			break;
		}
		case 1: {
			int* a = 0, n = 0, min = 0, l = 0;
			cout << "Количество чисел: ";
			cin >> n;
			cout << "Числа: ";
			a = new int[n];
			for (int i = 0; i < n; i++) {
				cin >> a[i];
			}
			basalg2(a, n, min, l);
			cout << "Минимум: " << min << ". Индекс: " << l;
			while (keycode != 13) {
				keycode = _getch();
			}
			break;
		}
		case 2: {
			int n, k = 0, len = 0;
			cout << "Количество слов: ";
			cin >> n;
			string* name = new string[n], * best = new string[n];
			cout << "Слова: ";
			for (int i = 0; i < n; i++) {
				cin >> name[i];
			}
			basalg3(name, n, k, best);
			cout << "Хорошие варианты: " << endl;
			for (int i = 0; i < k; i++) {
				cout << best[i] << endl;
			}
			while (keycode != 13) {
				keycode = _getch();
			}
			break;
		}
		case 3: {
			int n = 0, l = -1;
			string* name, ctrl;
			cout << "Количество слов: ";
			cin >> n;
			name = new string[n];
			cout << "Список слов: " << endl;
			for (int i = 0; i < n; i++) {
				cin >> name[i];
			}
			cout << "Поиск: ";
			cin >> ctrl;
			l = basalg4(name, n, ctrl);
			if (l == -1) {
				cout << "Слово не найдено!";
			}
			else {
				cout << "Слово найдено! Индекс: " << l;
			}
			while (keycode != 13) {
				keycode = _getch();
			}
			break;
		}
		case 4: {
			int n = 0, l = -1;
			string* name, ctrl;
			
			cout << "Количество слов: ";
			cin >> n;
			
			name = new string[n];
			cout << "Список слов: " << endl;
			for (int i = 0; i < n; i++) {
				cin >> name[i];
			}
			cout << "Поиск: ";
			cin >> ctrl;
			l = basalg5(name, n, ctrl);
			if (l == -1) {
				cout << "Слово не найдено!";
			}
			else {
				cout << "Слово найдено! Индекс: " << l;
			}
			while (keycode != 13) {
				keycode = _getch();
			}
			break;
		}
		case 5: {
			int n = 0, k = 0;
			string* name, * list;
			cout << "Количество элементов: ";
			cin >> n;
			name = new string[n];
			list = new string[n];
			cout << "Введите список: " << endl;
			for (int i = 0; i < n; i++) {
				cin >> name[i];
			}
			basalg61(n, name, list, k);
			cout << "Список без повторений: " << endl;
			for (int i = 0; i < k; i++) {
				cout << list[i] << endl;
			}
			while (keycode != 13) {
				keycode = _getch();
			}
			break;
		}
		case 6: {
			int* rate, n = 0, k = 0;
			string* name, * list;
			cout << "Количество элементов: ";
			cin >> n;
			name = new string[n];
			list = new string[n];
			rate = new int[n];
			cout << "Введите список: " << endl;
			for (int i = 0; i < n; i++) {
				cin >> name[i];
			}
			basalg62(n, name, list, rate, k);
			cout << "Список без повторений: " << endl;
			cout << "Имя\t\t\tРейтинг" << endl;
			for (int i = 0; i < k; i++) {
				cout << list[i] << "\t\t\t" << rate[i] << endl;
			}
			while (keycode != 13) {
				keycode = _getch();
			}
			break;
		}
		case 7: {
			int n = 0, k = 0, * summa, * ch;
			string* name, * list;
			cout << "Количество элементов: ";
			cin >> n;
			name = new string[n];
			list = new string[n];
			summa = new int[n];
			ch = new int[n];
			cout << "Введите список: " << endl;
			for (int i = 0; i < n; i++) {
				cin >> name[i];
				cin >> ch[i];
			}
			basalg63(n, ch, name, k, list, summa);
			cout << "Список без повторений с хар-кой: " << endl;
			cout << "Имя\t\t\tХаракстеристика" << endl;
			for (int i = 0; i < k; i++) {
				cout << list[i] << "\t\t\t" << summa[i] << endl;
			}
			while (keycode != 13) {
				keycode = _getch();
			}
			break;
		}
		case 8: {
			int k = 0;
			string str, * w;
			cout << "Введите строку: ";
			getline(cin, str);
			w = new string[str.length() / 2 + 1];
			basalg9(str, k, w);
			cout << "Найденные слова: " << endl;
			for (int i = 0; i < k; i++) {
				cout << w[i] << endl;
			}
			while (keycode != 13) {
				keycode = _getch();
			}
			break;
		}
		case 9: {
			string str, * w;
			int k = 0;
			cout << "Введите строку: ";
			getline(cin, str);
			w = new string[str.length() / 2 + 1];
			basalg10(str, k, w);
			cout << "Найденные слова: " << endl;
			for (int i = 0; i < k; i++) {
				cout << w[i] << endl;
			}
			while (keycode != 13) {
				keycode = _getch();
			}
			break;
		}
		case 10: {
			endofmenu = 1;
			break;
		}
		}
		break;
	}

	return id;
}

int main() {
	setlocale(LC_ALL, "ru-RU");
	int id = 0;

	string itemnames[11] = { "1 - Суммирование", "2 - Минимальное число", "3 - Отбор по 1 букве", "4 - Лин. поиск", "5 - Бин. поиск", "6 - Слова без повтор.", "7 - Рейтинг", "9 - Характеристики", "9 - Деление на слова", "10 - Деление на слова с разделителями", "Выход" };

	menu(itemnames, 11, id);
	while (endofmenu != 1) {
		id = input(11, id);
		menu(itemnames, 11, id);
	}

	system("cls");
	cout << "До свидания!" << endl;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
