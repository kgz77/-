#include<iostream>
#include<string>

using namespace std;

class Int {
private:
	long long num;//число 
public:
	Int() :num(0) {}		       //конструктор по умолчанию num = 0
	Int(long long num) :num(num) {}//конструктор с аргументом
	//метод для вывода значения на экран
	void show() { cout << "num : " << this->num << endl; }
	//перегрузка оператора + 
	Int operator +(const Int& R) {
		Int result;
		result.num = this->num + R.num;//Вычисление суммы
		//проверка на переполнения и бросать исключение
		if ((result.num < INT32_MIN) || (result.num > INT32_MAX))
			throw "Ошибка! Выход за границы типа int \n ";
		return result;
	}
	//перегрузка оператора -
	Int operator -(const Int& R) {
		Int result;
		result.num = num - R.num;
		if ((result.num < INT32_MIN) || (result.num > INT32_MAX))
			throw "Ошибка! Выход за границы типа int \n ";
		return result;
	} 
	//перегрузка оператора *
	Int operator *(const Int& R) {
		Int result;
		result.num = num * R.num;
		if ((result.num < INT32_MIN) || (result.num > INT32_MAX))
			throw "Ошибка! Выход за границы типа int \n ";
		return result;
	}
	//перегрузка оператора /
	Int operator /(const Int& R) {
		try{
			if (R.num == 0)
				throw "На ноль делить нельзя!";
		}
		catch (char* str) {
			cout << "\n" << str << endl;
		}
		Int result;
		result.num = num / R.num;
		if ((result.num < INT32_MIN) || (result.num > INT32_MAX))
			throw "Ошибка! Выход за границы типа int \n ";
		return result;
	}
	//Перегрузка оператора ++ 
	Int operator ++() {
		++num;
		return *this;
	}

	Int operator++(int) {
		num++;
		return *this;
	}
	~Int() {}
};



int main() {
	setlocale(LC_ALL, "ru");
	Int  C, D, E, F;
	int x, y, m;
	do
	{
		cout << "\nВведите первое число : ";
		cin >> x;
		cout << "Введите второе число : ";
		cin >> y;
		Int A(x), B(y);
		cout << "1 - Сложение\n2 - Вычитание\n3 - Умножение\n4 - Деление\n0 - Инкремент" << endl;
		cout << "Выберите действие : ";
		cin >> m; 
		try {
			switch (m)
			{
			case 1: C = A + B; C.show(); cout << endl; break;
			case 2: D = A - B; D.show(); cout << endl; break;
			case 3: E = A * B; E.show(); cout << endl; break;
			case 4: F = A / B; F.show(); cout << endl; break;
			default:
				break;
			}
		}
		catch (const char* str) {
			cout << str;
		}
	} while (m != 0);

	cout << "Инкрементирование " << endl;
	++C;
	C.show();
	cout << endl;

	C++;
	C.show();
	cout << endl;

	cout << endl;


	system("pause");
	return 0;
}