#include <iostream>
#include<Windows.h> 
using namespace std;

double Sum(double a, double b) //ф-н суми
{
	return a + b;
}

double Dif(double a, double b) //ф-н різниці
{
	return a - b;
}
double Product(double a, double b)//ф-н множення
{
	return a * b;
}
double Division(double a, double b) //ф-н ділення
{
	return a / b;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);//підключення української
	
	char oper;
	double  a = 0, b = 0;
	char ch = 'y';//оголошення всіх змінних
		
		while (ch!='n')//цикл для багаторазового використання 
		{
			cout << "Введіть число a та в" << endl;
			cin >> a >> b;
			cout << "Виберіть операцію" << endl;
			cin >> oper;//введення потрібних данних

			switch (oper)
			{
			case '+':cout << Sum(a, b) << endl;///виклик ф-н суми і вивід результату
				break;
			case '-':cout << Dif(a, b) << endl;//виклик ф-н різниці і вивід результату
				break;
			case '*':cout << Product(a, b) << endl;//виклик ф-н добутку і вивід результату
				break;
			case '/':  if (b == 0){//перевірка чи користувач хоче ділити на 0
				cout << "На 0 не ділиться" << endl;
				break;
			 }
			 else {
				cout << Division(a, b) << endl;//виклик ф-н ділення і вивід результату
				break;
			 }
			 default:cout << "Ви ввели не вірну операцію" << endl;
				break;
			}
			cout << "Якщо бажаєте припинити роботу введіть 'n' ,якщо хочете продовжити введіть будь-який символ" << endl;
			cin >> ch;
			system("cls");//чистим консоль
		}
		return 0;
}