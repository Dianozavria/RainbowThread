#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <iomanip> 
#include <sstream>
#include <locale>
#include <vector>
#include <algorithm>
#include <cctype>
#include <limits>

#ifdef max
#undef max
#endif

using namespace std;
void catalog();
void cart();
void logIn();
void registration();
void account();
bool loginCheck(string login);
bool passwordCheck(string login, string password);
void passwordWrite(string login, string password);
bool passwordProtect(string password);
void loginWrite(string login);
void personalAccount();
void admin();
void orders();
void currentUser(string username);
void passwordChange();
void logOut();
bool ifLogIn();
string currentUsername();
void tempUser(string username);
string tempUsername();
void tempPasswordChange();
void productAdd();
bool adminCheck(string login, string password);
void adminLogIn();
void addToCart();
bool ifCodeIsFree(string str);
vector<string> stringToVector(string str);
void delFromCart();
void makeOrder();
void writeOrder();
void users();
int countOrders();

void mainMenu()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	system("cls");

	if (currentUsername() == "admin")
	{
		cout << "-----------------------------------" << endl;
		cout << "|            РадугаНить           |" << endl;
		cout << "|                                 |" << endl;
		cout << "|         1. Каталог              |" << endl;
		cout << "|         2. Панель админа        |" << endl;
		cout << "|         3. Выйти                |" << endl;
		cout << "|                                 |" << endl;
		cout << "-----------------------------------" << endl;
	}
	else if (ifLogIn())
	{
		cout << "-----------------------------------" << endl;
		cout << "|            РадугаНить           |" << endl;
		cout << "|                                 |" << endl;
		cout << "|         1. Каталог              |" << endl;
		cout << "|         2. Личный кабинет       |" << endl;
		cout << "|         3. Выйти                |" << endl;
		cout << "|                                 |" << endl;
		cout << "-----------------------------------" << endl;
	}
	else
	{
		cout << "-----------------------------------" << endl;
		cout << "|            РадугаНить           |" << endl;
		cout << "|                                 |" << endl;
		cout << "|         1. Каталог              |" << endl;
		cout << "|         2. Личный кабинет       |" << endl;
		cout << "|         3. Выйти                |" << endl;
		cout << "|                                 |" << endl;
		cout << "-----------------------------------" << endl;
	}

	switch (_getch())
	{
	case '1':
		catalog();
		break;
	case '2':
		if (currentUsername() == "admin")
		{
			admin();
		}
		else if (ifLogIn())
		{
			personalAccount();
		}
		else
		{
			account();
		}
		break;
	case '3':
		exit(0);
		break;
	}
}

void account()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	system("cls");

	cout << "-----------------------------------" << endl;
	cout << "|          Личный кабинет         |" << endl;
	cout << "|                                 |" << endl;
	cout << "|         1. Регистрация          |" << endl;
	cout << "|         2. Вход                 |" << endl;
	cout << "|         3. Вход как админ       |" << endl;
	cout << "|         4. Главное меню         |" << endl;
	cout << "|         5. Выйти                |" << endl;
	cout << "|                                 |" << endl;
	cout << "-----------------------------------" << endl;

	switch (_getch())
	{
	case '2':
		logIn();
		break;
	case '3':
		adminLogIn();
		break;
	case '1':
		registration();
		break;
	case '4':
		mainMenu();
		break;
	case '5':
		exit(0);
		break;
	}
}

void logIn()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	ofstream fout;
	string login, password;
	system("cls");

	cout << "-----------------------------------" << endl;
	cout << "|              Вход               |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Введите логин ";
	cin >> login;

	if (loginCheck(login))
	{
		cout << "Введите пароль ";
		cin >> password;

		if (passwordCheck(login, password))
		{
			currentUser(login);
			personalAccount();
		}
		else if (!passwordCheck(login, password))
		{
			tempUser(login);

			system("cls");
			cout << "-----------------------------------" << endl;
			cout << "|              Вход               |" << endl;
			cout << "|                                 |" << endl;
			cout << "|     Вы неверно ввели пароль!    |" << endl;
			cout << "|                                 |" << endl;
			cout << "|   1 - чтобы повторить вход      |" << endl;
			cout << "|   2 - чтобы изменить пароль     |" << endl;
			cout << "|                                 |" << endl;
			cout << "-----------------------------------" << endl;

			switch (_getch())
			{
			case '1':
				logIn();
				break;
			case '2':
				tempPasswordChange();
				break;
			}
		}
	}
	else
	{
		system("cls");

		cout << "-----------------------------------" << endl;
		cout << "|              Вход               |" << endl;
		cout << "|                                 |" << endl;
		cout << "|Такого пользователя не существует|" << endl;
		cout << "|                                 |" << endl;
		cout << "| 1 - чтобы повторить попытку     |" << endl;
		cout << "| 2 - чтобы перейти к регистрации |" << endl;
		cout << "| 3 - главное меню                |" << endl;
		cout << "|                                 |" << endl;
		cout << "-----------------------------------" << endl;

		switch (_getch())
		{
		case '1':
			logIn();
			break;
		case '2':
			registration();
			break;
		case '3':
			mainMenu();
			break;
		}
	}
}

void registration()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	string login, password;
	int count = 0;
	system("cls");

	cout << "-----------------------------------" << endl;
	cout << "|           Регистрация           |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Введите логин ";
	cin >> login;

	if (!loginCheck(login))
	{
		loginWrite(login);
		cout << "Введите пароль (минимум 8 символов) "<<endl;
		cin >> password;

		if (!passwordProtect(password))
		{
			currentUser(login);
			passwordWrite(login, password);

			system("cls");
		}
		else
		{
			system("cls");

			cout << "-----------------------------------" << endl;
			cout << "|           Регистрация           |" << endl;
			cout << "|                                 |" << endl;
			cout << "|  Введите более надёжный пароль  |" << endl;
			cout << "|      (минимум 8 символов)       |" << endl;
			cout << "|                                 |" << endl;
			cout << "-----------------------------------" << endl;

			cin >> password;

			if (passwordProtect(password))
			{
				system("cls");

				cout << "-----------------------------------" << endl;
				cout << "|           Регистрация           |" << endl;
				cout << "|                                 |" << endl;
				cout << "|        Ошибка регистрации       |" << endl;
				cout << "|        Повторите попытку        |" << endl;
				cout << "|                                 |" << endl;
				cout << "|   1 - чтобы повторить попытку   |" << endl;
				cout << "|   2 - главное меню              |" << endl;
				cout << "|                                 |" << endl;
				cout << "-----------------------------------" << endl;

				switch (_getch())
				{
				case '1':
					registration();
					break;
				case '2':
					mainMenu();
					break;
				}
			}
		}
	}

	else if (loginCheck(login))
	{
		system("cls");

		cout << "-----------------------------------" << endl;
		cout << "|           Регистрация           |" << endl;
		cout << "|                                 |" << endl;
		cout << "|Такой пользователь уже существует|" << endl;
		cout << "|                                 |" << endl;
		cout << "|     Хотите войти в аккаунт?     |" << endl;
		cout << "|         1. Да   2. Нет          |" << endl;
		cout << "-----------------------------------" << endl;

		switch (_getch())
		{
		case '1':
			logIn();
			break;
		case '2':
			mainMenu();
			break;
		}
	}
}

bool loginCheck(string login)
{
	ifstream fin;
	fin.open("login.txt");
	string line;
	int result = 0;

	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			if (login == line)
			{
				result = 1;
				fin.close();
				break;
			}
		}

		if (result == 0)
		{
			return false;
		}
	}
	else
	{
		result = false;
	}

	if (result == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool passwordCheck(string login, string password)
{
	ifstream fin;
	fin.open(login + "_password.txt");
	string line;
	int result = 0;

	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			if (password == line)
			{
				result = 1;
				fin.close();
				break;
			}
		}

		if (result == 0)
		{
			result = false;
		}
	}
	else
	{
		result = false;
	}

	if (result == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool passwordProtect(string password)
{
	int count = 0;
	int count_1 = 0;
	int count_2 = 0;
	char temp = password[0];

	if (!password.empty() && size(password) >= 8)
	{
		if (password == "12345678" || password == "87654321")
		{
			return false;
		}

		for (int i = 0; i <= size(password); i++)
		{
			if (password[i] == ' ')
			{
				count++;
			}

			if (i >= 1 && password[i] == password[i - 1])
			{
				count_1++;
			}

			if (password[i] == i + 1)
			{
				count_2++;
			}
		}
		if (count == 1 || count_1 == size(password) || count_2 == size(password))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

void loginWrite(string login)
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	ofstream fout;
	fout.open("login.txt", ios::app);

	if (fout.is_open())
	{
		fout << login << endl;
		fout.close();
	}

	else if (!fout.is_open())
	{
		system("cls");

		cout << "-----------------------------------" << endl;
		cout << "|           Регистрация           |" << endl;
		cout << "|                                 |" << endl;
		cout << "|        Ошибка регистрации       |" << endl;
		cout << "|        Повторите попытку        |" << endl;
		cout << "|                                 |" << endl;
		cout << "|    1 - чтобы повторить попытку  |" << endl;
		cout << "|    2 - главное меню             |" << endl;
		cout << "|                                 |" << endl;
		cout << "-----------------------------------" << endl;

		switch (_getch())
		{
		case '1':
			registration();
			break;
		case '2':
			mainMenu();
			break;
		}
	}
}

void passwordWrite(string login, string password)
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	ofstream fout;
	fout.open(login + "_password.txt", ios::out);

	if (fout.is_open())
	{
		fout << password << endl;
		fout.close();
		system("cls");

		cout << "-------------------------------------" << endl;
		cout << "|           Регистрация             |" << endl;
		cout << "|                                   |" << endl;
		cout << "|        Регистрация успешно        |" << endl;
		cout << "|            завершена              |" << endl;
		cout << "|                                   |" << endl;
		cout << "| 1 - чтобы зайти в личный кабинет  |" << endl;
		cout << "| 2 - чтобы перейти в главное меню  |" << endl;
		cout << "|                                   |" << endl;
		cout << "-------------------------------------" << endl;

		switch (_getch())
		{
		case '1':
			personalAccount();
			break;
		case '2':
			mainMenu();
			break;
		}
	}

	else if (!fout.is_open())
	{
		system("cls");

		cout << "-----------------------------------" << endl;
		cout << "|           Регистрация           |" << endl;
		cout << "|                                 |" << endl;
		cout << "|        Ошибка регистрации       |" << endl;
		cout << "|        Повторите попытку        |" << endl;
		cout << "|                                 |" << endl;
		cout << "|    1 - чтобы повторить попытку  |" << endl;
		cout << "|    2 - главное меню             |" << endl;
		cout << "|                                 |" << endl;
		cout << "-----------------------------------" << endl;

		switch (_getch())
		{
		case '1':
			registration();
		case '2':
			mainMenu();
		}
	}

}

void personalAccount()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	system("cls");

	cout << "-----------------------------------" << endl;
	cout << "|          Личный кабинет         |" << endl;
	cout << "|                                 |" << endl;
	cout << "|         1. История заказов      |" << endl;
	cout << "|         2. Каталог              |" << endl;
	cout << "|         3. Корзина              |" << endl;
	cout << "|         4. Сменить пароль       |" << endl;
	cout << "|         5. Главное меню         |" << endl;
	cout << "|         6. Выйти из аккаунта    |" << endl;
	cout << "|         7. Выйти                |" << endl;
	cout << "-----------------------------------" << endl;

	switch (_getch())
	{
	case '1':
		orders();
		break;
	case '2':
		catalog();
		break;
	case '3':
		cart();
		break;
	case '5':
		mainMenu();
		break;
	case '4':
		passwordChange();
		break;
	case '6':
		logOut();
		break;
	case '7':
		exit(0);
		break;
	}
}

void passwordChange()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	string current_password = "", new_password, temp;
	system("cls");
	cout << "-----------------------------------" << endl;
	cout << "|          Смена пароля           |" << endl;
	cout << "-----------------------------------" << endl << endl;

	cout << "Введите текущий пароль" << endl;
	cin >> current_password;

	if (passwordCheck(currentUsername(), current_password))
	{
		cout << "Введите новый пароль" << endl;
		cin >> new_password;
		cout << "Повторите новый пароль" << endl;
		cin >> temp;

		if (passwordCheck(currentUsername(), current_password) && new_password == temp && !passwordProtect(new_password))
		{
			fstream file(currentUsername() + "_password.txt", fstream::out | fstream::trunc);
			file << new_password << endl;
			file.close();
		}
		else
		{
			system("cls");
			cout << "-----------------------------------" << endl;
			cout << "|          Смена пароля           |" << endl;
			cout << "|            Ошибка!              |" << endl;
			cout << "|   Нажмите любую клавишу, чтобы  |" << endl;
			cout << "|    вернутся в личный кабинет    |" << endl;
			cout << "-----------------------------------" << endl << endl;

			_getch();
			personalAccount();
		}

		system("cls");
		cout << "-----------------------------------" << endl;
		cout << "|          Смена пароля           |" << endl;
		cout << "|     Пароль успешно изменён!     |" << endl;
		cout << "|   Нажмите любую клавишу, чтобы  |" << endl;
		cout << "|     перейти в личный кабинет    |" << endl;
		cout << "-----------------------------------" << endl << endl;

		_getch();
		personalAccount();
	}
	else
	{
		system("cls");
		cout << "-----------------------------------" << endl;
		cout << "|           Смена пароля          |" << endl;
		cout << "|             Ошибка!             |" << endl;
		cout << "|     Вы ввели неверный пароль    |" << endl;
		cout << "|   Нажмите любую клавишу, чтобы  |" << endl;
		cout << "|    вернутся в личный кабинет    |" << endl;
		cout << "-----------------------------------" << endl << endl;

		_getch();
		personalAccount();
	}
}

void logOut()
{
	ofstream file("current_user.txt", ofstream::out | ofstream::trunc); // очистка файла
	file.close();
	mainMenu();
}

void currentUser(string username)
{
	ofstream fout("current_user.txt", ios::out);
	fout << username << endl;
	fout.close();
}

bool ifLogIn()
{
	ifstream fin("current_user.txt");
	string user = "";

	if (fin.is_open())
	{
		string line;
		while (getline(fin, line))
		{
			user = line;
		}
		fin.close();

		if (user.empty())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

string currentUsername()
{
	fstream file("current_user.txt", ios::in | ios::app);
	string line, username = "";

	if (file.is_open())
	{
		while (getline(file, line))
		{
			username = line;
		}
		file.close();
	}
	return username;
}

void tempUser(string username)
{
	ofstream fout("temp_user.txt", ios::out);
	fout << username << endl;
	fout.close();
}

string tempUsername()
{
	ifstream fin("temp_user.txt");
	string line, username;

	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			username = line;
		}
		fin.close();
	}
	return username;
}

void tempPasswordChange()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	string new_password, temp;
	system("cls");
	cout << "-----------------------------------" << endl;
	cout << "|          Смена пароля           |" << endl;
	cout << "-----------------------------------" << endl << endl;

	cout << "Введите новый пароль" << endl;
	cin >> new_password;
	cout << "Повторите новый пароль" << endl;
	cin >> temp;

	if (new_password == temp)
	{
		fstream file(tempUsername() + "_password.txt", fstream::out | fstream::trunc);
		file << new_password << endl;
		file.close();
		currentUser(tempUsername());
	}

	system("cls");
	cout << "-----------------------------------" << endl;
	cout << "|          Смена пароля           |" << endl;
	cout << "|     Пароль успешно изменён!     |" << endl;
	cout << "|   Нажмите любую клавишу, чтобы  |" << endl;
	cout << "|      перейти в главное меню     |" << endl;
	cout << "-----------------------------------" << endl << endl;

	_getch();
	mainMenu();
}

void catalog()
{
	setlocale(LC_ALL, "rus");
	fstream file("catalog.txt", ios::in | ios::app);
	SetConsoleOutputCP(CP_UTF8);
	string name, code, price, line;
	system("cls");

	cout << "-----------------------------------------------" << endl;
	cout << "|                   Каталог                   |" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "|      Название     |  Цена(руб)/шт |   Код   |" << endl;
	cout << "-----------------------------------------------" << endl;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (!line.empty())
			{
				stringstream ss(line);
				getline(ss, name, ',');
				getline(ss, price, ',');
				getline(ss, code);

				if (!name.empty() && !price.empty() && !code.empty())
				{
					cout << "|   " << setw(15) << left << name << " | " << setw(13) << right << fixed << setprecision(2) << price << " | " << setw(7) << code << " |" << endl;
					cout << "-----------------------------------------------" << endl;
				}
			}
		}
		file.close();

		if (currentUsername() != "admin")
		{
			cout << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "|      1 - добавления товаров в корзину       |" << endl;
			cout << "|      2 - возврат в главное меню             |" << endl;
			cout << "|      3 - перейти в личный кабинет           |" << endl;
			cout << "-----------------------------------------------" << endl;

			switch (_getch())
			{
			case '1':
				addToCart();
				break;
			case '2':
				mainMenu();
				break;
			case '3':
				if (ifLogIn())
				{
					personalAccount();
				}
				else
				{
					account();
				}
				break;
			}
		}
		else if (currentUsername() == "admin")
		{
			cout << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "|      1 - переход в панель админа            |" << endl;
			cout << "|      2 - возврат в главное меню             |" << endl;
			cout << "-----------------------------------------------" << endl;

			switch (_getch())
			{
			case '1':
				admin();
				break;
			case '2':
				mainMenu();
				break;
			}
		}

	}
}

void cart()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	system("cls");
	string username = currentUsername(), line, count, price, name, code;
	double total_price = 0;
	fstream file(username + "_cart.txt", ios::app);
	file.close();
	ifstream fin(username + "_cart.txt");

	if (fin.is_open())
	{
		system("cls");
		cout << "----------------------------------------------------------" << endl;
		cout << "|                   Корзина                              |" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "|      Название     |  Цена(руб)/шт |  Кол-во |    Код   |" << endl;
		cout << "----------------------------------------------------------" << endl;

		while (getline(fin, line))
		{
			stringstream ss(line);
			getline(ss, name, ',');
			getline(ss, price, ',');
			getline(ss, count, ',');
			getline(ss, code);

			if (!name.empty() && !price.empty() && !code.empty() && !count.empty())
			{
				total_price += stod(price) * stod(count);

				cout << "|   " << setw(15) << left << name << " | " << setw(13) << right << fixed << setprecision(2) << price << " | " << setw(7) << count << " | " << setw(9) << code << "|" << endl;
				cout << "----------------------------------------------------------" << endl;
			}
		}
		cout << setw(48) << left << "Общая стоимость: " << fixed << setprecision(2) << total_price << " руб." << endl;
		cout << "----------------------------------------------------------" << endl;

		fin.close();

		cout << endl << "1 - удаление товара/товаров " << endl;
		cout << "2 - оформлени заказа " << endl;
		cout << "3 - возврат в главное меню " << endl;

		switch (_getch())
		{
		case '1':
			delFromCart();
			break;
		case '2':
			makeOrder();
			break;
		case '3':
			mainMenu();
			break;
		}

	}
}

void admin()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	system("cls");

	cout << "------------------------------------" << endl;
	cout << "|        Панель администратора     |" << endl;
	cout << "|                                  |" << endl;
	cout << "| 1. Дабавить продукцию в каталог  |" << endl;
	cout << "| 2. Просмотр всех пользователей   |" << endl;
	cout << "| 3. Главное меню                  |" << endl;
	cout << "| 4. Выйти из профиля админа       |" << endl;
	cout << "| 5. Выйти                         |" << endl;
	cout << "|                                  |" << endl;
	cout << "------------------------------------" << endl;

	switch (_getch())
	{
	case '1':
		productAdd();
		break;
	case '2':
		users();
		break;
	case '3':
		mainMenu();
		break;
	case '4':
		logOut();
		mainMenu();
		break;
	case '5':
		exit(0);
		break;
	}
}

void orders()
{
	system("cls");
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	string username = currentUsername(), line, name = "", count = "", price = "", total_price = "", code = "";
	double temp = 0, countOrd = countOrders();
	ifstream file(username + "_orders.txt", ios::in | ios::app);

	if (file.is_open())
	{
		bool hasOrders = false;

		cout << "------------------------------------------------" << endl;
		cout << "|                 История заказов              |" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "|      Название     |  Цена(руб)/шт |  Кол-во  |" << endl;
		cout << "------------------------------------------------" << endl;

		while (getline(file, line))
		{
			hasOrders = true;

			if (line == "1")
			{
				if (temp > 0)
				{
					ostringstream os;
					os << fixed << setprecision(2) << temp;
					total_price = os.str();

					cout << setw(40) << left << "Общая стоимость: " << fixed << setprecision(2) << total_price << " руб." << endl;
					cout << "------------------------------------------------" << endl << endl;
				}

				countOrd--;
				if (countOrd > 0)
				{
					cout << "------------------------------------------------" << endl;
					cout << "|      Название     |  Цена(руб)/шт |  Кол-во  |" << endl;
					cout << "------------------------------------------------" << endl;
				}

				temp = 0;
				total_price = "";
			}
			else
			{
				getline(file, line);
				stringstream ss(line);
				getline(ss, name, ',');
				getline(ss, price, ',');
				getline(ss, count, ',');
				getline(ss, code);

				if (!name.empty() && !price.empty() && !count.empty())
				{
					double item_price = stod(price);
					int item_count = stoi(count);
					double item_total = item_price * item_count;
					temp += item_total;
					total_price = to_string(temp);

					cout << "|   " << setw(15) << left << name << " | " << setw(13) << right << fixed << setprecision(2) << price << " | " << setw(8) << count << " |" << endl;
					cout << "------------------------------------------------" << endl;

				}
			}

		}

		if (!hasOrders)
		{
			system("cls");
			cout << "------------------------------------------------" << endl;
			cout << "|                 История заказов              |" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "|      Вы не сделали ещё ни одного заказа      |" << endl;
			cout << "|        1 - чтобы перйти в каталог            |" << endl;
			cout << "|        2 - чтобы перйти в главное меню       |" << endl;
			cout << "------------------------------------------------" << endl;

			switch (_getch())
			{
			case '1':
				catalog();
				break;
			case '2':
				mainMenu();
				break;
			}
		}

		cout << "Нажмите любую клавишу, чтобы вернутся в главное меню..." << endl;
		_getch();
		mainMenu();
	}
	else
	{
		system("cls");
		cout << "------------------------------------------------" << endl;
		cout << "|                 История заказов              |" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "|                    Ошибка                    |" << endl;
		cout << "|        1 - чтобы перйти в каталог            |" << endl;
		cout << "|        2 - чтобы перйти в главное меню       |" << endl;
		cout << "------------------------------------------------" << endl;

		switch (_getch())
		{
		case '1':
			catalog();
			break;
		case '2':
			mainMenu();
			break;
		}
	}
}

void productAdd()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	fstream file("catalog.txt", ios::app);

	if (file.is_open())
	{
		string name, price, code;

		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "|             Добавление продуктов            |" << endl;
		cout << "-----------------------------------------------" << endl << endl;

		cout << "Введите название товара" << endl;
		cin >> name;
        cout << "Введите цену товара" << endl;
		cin >> price;
        cout << "Введите код товара" << endl;
		cin >> code;

		if (ifCodeIsFree(code))
		{
			file << endl << name << "," << price << "," << code << endl;

			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "|        Успешно добавлен новый продукт       |" << endl;
			cout << "|     1 - чтобы просмотреть каталог           |" << endl;
			cout << "|     2 - чтобы добавить ещё товар            |" << endl;
			cout << "|     3 - чтобы вернутья в главное меню       |" << endl;
			cout << "-----------------------------------------------" << endl << endl;

			switch (_getch())
			{
			case '1':
				catalog();
				break;
			case '2':
				productAdd();
				break;
			case '3':
				mainMenu();
				break;
			}
		}
		else
		{
			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "|      Ошибка, данный код уже существует      |" << endl;
			cout << "|             Введите код еще раз             |" << endl;
			cout << "-----------------------------------------------" << endl << endl;

			cin >> code;
			if (ifCodeIsFree(code))
			{
				file << endl << name << ", " << price << ", " << code << endl;

				system("cls");
				cout << "-----------------------------------------------" << endl;
				cout << "|        Успешно добавлен новый продукт       |" << endl;
				cout << "|     1 - чтобы просмотреть каталог           |" << endl;
				cout << "|     2 - чтобы вернутья в главное меню       |" << endl;
				cout << "-----------------------------------------------" << endl << endl;

				switch (_getch())
				{
				case '1':
					catalog();
					break;
				case '2':
					mainMenu();
					break;
				}
			}
			else
			{
				system("cls");
				cout << "----------------------------------------------" << endl;
				cout << "|                    Ошибка                  |" << endl;
				cout << "|     1 - чтобы повторить попытку            |" << endl;
				cout << "|     2 - чтобы вернуться в главное меню     |" << endl;
				cout << "----------------------------------------------" << endl << endl;

				switch (_getch())
				{
				case '1':
					productAdd();
					break;
				case '2':
					mainMenu();
					break;
				}
			}
		}
		file.close();
	}
	else
	{
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "|             Добавление продуктов            |" << endl;
		cout << "|                                             |" << endl;
		cout << "|              Ошибка добавления              |" << endl;
		cout << "|                                             |" << endl;
		cout << "|     1 - чтобы повторить попытку             |" << endl;
		cout << "|     2 - чтобы вернуться в меню админа       |" << endl;
		cout << "|                                             |" << endl;
		cout << "-----------------------------------------------" << endl;

		switch (_getch())
		{
		case '1':
			productAdd();
			break;
		case '2':
			admin();
			break;
		}
	}
}

bool adminCheck(string login = "", string password = "")
{
	if (login == "admin" && password == "admin")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void adminLogIn()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	string login, password;
	system("cls");
	cout << "------------------------------------" << endl;
	cout << "|           Вход как админ         |" << endl;
	cout << "------------------------------------" << endl << endl;

	cout << "Введите логин админа" << endl;
	cin >> login;
	cout << "Введите пароль админа" << endl;
	cin >> password;

	if (adminCheck(login, password))
	{
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "| Вы успешно вошли в качестве админа!|" << endl;
		cout << "|                                    |" << endl;
		cout << "|    Нажмите любую клавишу, чтобы    |" << endl;
		cout << "|            продолжить              |" << endl;
		cout << "--------------------------------------" << endl;

		currentUser("admin");
		_getch();
		admin();
	}
	else
	{
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "|                Ошибка!             |" << endl;
		cout << "|                                    |" << endl;
		cout << "|  1 - чтобы повторить попытку       |" << endl;
		cout << "|  2 - чтобы перейти в главное меню  |" << endl;
		cout << "|                                    |" << endl;
		cout << "--------------------------------------" << endl;

		switch (_getch())
		{
		case '1':
			adminLogIn();
			break;
		case '2':
			mainMenu();
			break;
		}
	}
}

void addToCart()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	string username = currentUsername();

	if (username != "")
	{
		string line, count, code, name, price, file_code;
		cout << endl << "Введите код товара" << endl;
		cin >> code;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		ifstream fin("catalog.txt", ios::in);
		ofstream fout(username + "_cart.txt", ios::app);

		if (ifCodeIsFree(code))
		{
			cout << "Ошибка! Товара с данным кодом не существует" << endl;
			cout << "1 - чтобы добавить другой товар" << endl;
			cout << "2 - чтобы Перейти в главное меню" << endl;

			switch (_getch())
			{
			case '1':
				addToCart();
				break;
			case '2':
				mainMenu();
				break;
			}
		}
		else if (fin.is_open() && fout.is_open())
		{
			cout << "Введите необходимое кол-во штук товара" << endl;
			cin >> count;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			while (getline(fin, line))
			{
				stringstream ss(line);
				getline(ss, name, ',');
				getline(ss, price, ',');
				getline(ss, file_code);

				if (code == file_code)
				{
					fout << name << "," << price << "," << count << "," << code << endl;
				}
			}

			fin.close();
			fout.close();
			cout << "Товар успешно добавлен в корзину!" << endl;
			cout << "1 - чтобы добавить еще товары" << endl;
			cout << "2 - чтобы перейти в корзину" << endl;
			cout << "3 - чтобы перейти в главное меню" << endl;

			switch (_getch())
			{
			case '1':
				addToCart();
				break;
			case '2':
				cart();
				break;
			case '3':
				mainMenu();
				break;
			}
		}
		else
		{
			cout << "Ошибка!" << endl;
			cout << "1 - чтобы повторить попытку" << endl;
			cout << "2 - чтобы перейти в главное меню" << endl;

			switch (_getch())
			{
			case '1':
				catalog();
				break;
			case '2':
				mainMenu();
				break;
			}
		}
	}
	else if (username == "")
	{
		system("cls");
		cout << "Ошибка!" << endl;
		cout << "Вам необходимо войти в аккаунт или зарегистрироваться для добавления \nтоваров в корзину" << endl << endl;
		cout << "1 - вход в личный кабинет" << endl;
		cout << "2 - возвращение в главное меню" << endl;

		switch (_getch())
		{
		case '1':
			account();
			break;
		case '2':
			mainMenu();
			break;
		}
	}
}

void delFromCart()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	string price, name, code, count, line, file_code;
	cout << endl << "Введиет код товара, который нужно удалить" << endl;
	cin >> code;
	ifstream fin(currentUsername() + "_cart.txt", ios::in);
	ofstream fout("temp.txt", ios::out | ios::trunc);

	if (fin.is_open() && fout.is_open())
	{
		while (getline(fin, line))
		{
			stringstream ss(line);
			getline(ss, name, ',');
			getline(ss, price, ',');
			getline(ss, count, ',');
			getline(ss, file_code);

			if (code != file_code)
			{
				fout << line << endl;
			}
		}

		fin.close();
		fout.close();
		fin.open("temp.txt");
		fout.open(currentUsername() + "_cart.txt", ios::out | ios::trunc);

		if (fin.is_open() && fout.is_open())
		{
			while (getline(fin, line))
			{
				fout << line << endl;
			}

			fin.close();
			fout.close();

			cout << "Успешно!" << endl;
			cout << "1 -  чтобы перейти в корзину" << endl;
			cout << "2 -  чтобы перейти в главное меню" << endl;

			switch (_getch())
			{
			case '1':
				cart();
				break;
			case '2':
				mainMenu();
				break;
			}
		}
	}
}

bool ifCodeIsFree(string code)
{
	string name, file_code, price, line;
	int temp = 0;
	fstream file("catalog.txt", ios::in | ios::app);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			stringstream ss(line);
			getline(ss, name, ',');
			getline(ss, price, ',');
			getline(ss, file_code);

			if (file_code == code)
			{
				file.close();
				return false;
			}
		}
		file.close();
		return true;
	}
	return false;
}

vector<string> stringToVector(string str)
{
	vector<string> codes;
	istringstream ss(str);
	string item;

	while (getline(ss, item, ' '))
	{
		codes.push_back(item);
	}
	return codes;
}

void makeOrder()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	string temp;
	system("cls");
	cout << "------------------------------------" << endl;
	cout << "|          Оформление заказа       |" << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "Введите ваши ФИО" << endl;	
	getline(cin, temp);
	cout << "Введите ваш номер телефона" << endl;
	getline(cin, temp);
	cout << "Выберите споссоб доставки: 1 - самовывоз или 2 - доставка курьером" << endl;
	getline(cin, temp);
	cout << "Выберите способ оплаты: 1 - наличными или 2 - картой" << endl;
	getline(cin, temp);

	if (temp == "1")
	{
		cout << "Будем ждать вас по адресу ул.Мавотя 1" << endl;
		cout << "Спасибо за заказ. В ближайшее время с вами свяжется администрартор" << endl << endl;
		writeOrder();
		fstream file(currentUsername() + "_cart.txt", ios::out | ios::trunc);
		file.close();
		cout << "1 - чтобы выйти " << endl;
		cout << "2 - чтобы перейти в главное меню" << endl;
		switch (_getch())
		{
		case '1':
			exit(0);
			break;
		case '2':
			mainMenu();
			break;
		}
	}
	else if (temp == "2")
	{
		cout << "Введите город для доставки" << endl;
		getline(cin, temp);
		cout << "Введите улицу для доставки" << endl;
		getline(cin, temp);
		cout << "Введите номер дома для доставки" << endl;
		getline(cin, temp);
		cout << "Введите номер квартиры для доставки(если нет, то нажмите Enter)" << endl;
		getline(cin, temp);
		system("cls");
		cout << "Спасибо за заказ. В ближайшее время с вами свяжется администрартор" << endl << endl;
		writeOrder();
		fstream file(currentUsername() + "_cart.txt", ios::out | ios::trunc);
		file.close();
		cout << "1 - чтобы выйти " << endl;
		cout << "2 - чтобы перейти в главное меню" << endl;

		switch (_getch())
		{
		case '1':
			exit(0);
			break;
		case '2':
			mainMenu();
			break;
		}
	}
}

void writeOrder()
{
	string line, username = currentUsername(), name = "", price = "", count = "", code = "";
	ifstream fin(username + "_cart.txt", ios::in);
	fstream file(username + "_orders.txt", ios::app);

	if (fin.is_open() && file.is_open())
	{
		while (getline(fin, line))
		{
			if (!line.empty())
			{
				file << endl << line << endl;
			}
		}
		file << "1" << endl;
		fin.close();
		file.close();
		file.open(username + "_cart", ios::out | ios::trunc);
		file.close();
	}
}

void users()
{
	system("cls");
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(CP_UTF8);
	ifstream fin("login.txt", ios::in);
	string line;

	if (fin.is_open())
	{
		cout << "---------------------------------" << endl;
		cout << "|         Все пользователи      |" << endl;
		cout << "---------------------------------" << endl << endl;

		while (getline(fin, line))
		{
			cout << line << endl;
		}
		cout << "Нажмите любую клавишу, чтобы вернуться в главное меню" << endl;
		_getch();
		mainMenu();
	}
	else
	{
		cout << "Ошибка! Ещё никто не зарегистрировался" << endl;
		cout << "Нажмите любую клавишу, чтобы вернуться в главное меню" << endl;
		_getch();
		mainMenu();
	}
}

int countOrders()
{
	ifstream fin(currentUsername() + "_orders.txt", ios::in);
	string line;
	int count = 0;

	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			if (line == "1")
			{
				count++;
			}
		}
		fin.close();
	}
	return count;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, rect.top, 700, 650, TRUE);
	fstream file("catalog.txt", ios::app);
	file.close();
	logOut();
	mainMenu();
}