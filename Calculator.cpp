#include <iostream>
#include<Windows.h> 
#include <fstream>
#include<string>
#include <algorithm>

using namespace std;

double Sum(double number1, double number2) //ф-н суми
{
	return number1 + number2;
}

double Dif(double number1, double number2) //ф-н різниці
{
	return number1 - number2;
}
double Product(double number1, double number2)//ф-н множення
{
	return number1 * number2;
}
double Division(double number1, double number2) //ф-н ділення
{
	return number1 / number2;
}
void GetSqrt(double & number1 ,double& number2)//ф-н добування корення , передавання по силці
{	
	number1 =sqrt(number1);	
	number2 = sqrt(number2);
	
}
void СonvertBinary(int number1, int number2)//ф-н переведення числа в двійкову систему числення
{
	int* arr1 = new int[100];
	int* arr2 = new int[100];
	int t = 0, j=0;
	while (number1 != 0) {
		arr1[t] = number1 % 2;
		number1 = number1 / 2;		
		t++;		
	}
	while (number2 != 0) {
		arr2[j] = number2 % 2;
		number2 = number2 / 2;
		
		j++;
	}	
	for (int i = t-1; i >= 0; i--)
	{
		cout << arr1[i];
	}
	cout << endl;
	for (int i = j - 1; i >= 0; i--)
	{
		cout << arr2[i];
	}
	cout << endl;
	delete[] arr2;
	delete[] arr1;
}

void GetPow(double& number1, double power)//ф-н піднесення до степення
{
	number1 = pow(number1,power);	
}
void Menu() //ф-н виводу інформаційного меню
{
	cout << "\t\t\t\tВітаю!\nДана версія калькулятора підтримує наступні операції :додавання , віднімання,множення, ділення,піднесення до степення та знаходження корення" << endl;
	cout << "Для використання одної з операції потрібно ввести символ:\nдодаванн '+'\nВіднімання '-'\nМноження '*'\nДілення '/'\nПіднесення до степеня '^'\nЗнаходження кореня '$'" << endl;
}
void WritingFile(double results)
{	
		ofstream file("results.txt", ios_base::app);// Відкриваємо файл для дозапису

		if (!file.is_open()) {// Перевіряємо чи файл відкрився
			cout << "Файл не відкрито/Файл не створено";
			return;
		}
		else{
		file << results << "'\n'";// Записуємо результат у файл
		file.close();// Закриваємо файл	
		}
}
void WritingFile(double results, double results1)//перегрузка фукції запису в файл для добування корення
{
	ofstream file("results.txt", ios_base::app);// Відкриваємо файл для дозапису

	if (!file.is_open()) {// Перевіряємо чи файл відкрився
		cout << "Файл не відкрито/Файл не створено";
		return;
	}
	else {
		file << results <<results1<< "'\n'";// Записуємо результат у файл
		file.close();// Закриваємо файл	
	}
}

void WritingFile(string results)//перегрузка фукції запису в файл для ділення на нуль
{
	ofstream file("results.txt", ios_base::app);

	if (!file.is_open()) {
		cout << "Файл не відкрито/Файл не створено";
		return;
	}
	else {
		file << results << "'\n'";
		file.close();
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);//підключення української
	
	char operation;
	double  number1 = 0, number2 = 0;
	double results=0;
		
	char ch = 'y';//оголошення всіх змінних
	Menu();
		while (ch!='n')//цикл для багаторазового використання 
		{
			cout << "Введіть число a та b" << endl;
			cin >> number1 >> number2;
			cout << "Виберіть операцію '+' '-' '*' '/' '^' '$' '#'" << endl;
			cin >> operation;//введення потрібних данних

			switch (operation)
			{
			case '+':results = Sum(number1, number2);///виклик ф-н суми і вивід результату1
				WritingFile(results);
				cout << "Сума = "<<results << endl;
				break;
			case '-':results = Dif(number1, number2);//виклик ф-н різниці і вивід результату
				WritingFile(results);
				cout << "Різниця = " << results << endl;
				break;
			case '*':results =Product(number1, number2) ;//виклик ф-н добутку і вивід результату
				WritingFile(results);
				cout << "Добуток = " << results << endl;
				break;
			case '/':  if (number2 == 0){//перевірка чи користувач хоче ділити на 0
				cout << "На 0 не ділиться але якщо ви вичали ВишМат то результат  Infinity" << endl;
				WritingFile("Infinity");
				break;
			 }
			 else {
				results=Division(number1, number2);//виклик ф-н ділення і вивід результату
				WritingFile(results);
				cout << "Частка = " << results << endl;
				break;
			 }
			case '^':  
				GetPow(number1,number2);//виклик ф-н піднесення до степення
				cout <<"Піднесене число а до степеня "<<number2<<" = "<< number1 << endl;
				WritingFile(number1);
				break;
			case '$':
				GetSqrt(number1,number2);//виклик ф-н добування корення
				cout << "Корінь з числа а = " << number1 <<endl;
				WritingFile(number1 , number2);
				break; 		

			case '#':				
				СonvertBinary(number1, number2);
				//WritingFile(Getdva(number1 ));
				break;			
				
			 default:cout << "Ви ввели не вірну операцію" << endl;
				break;
			}			
			cout << "Якщо бажаєте припинити роботу введіть 'n' ,якщо хочете продовжити введіть будь-який символ" << endl;
			cin >> ch;
			system("cls");//чистим консоль
		}
		//return 0;
}