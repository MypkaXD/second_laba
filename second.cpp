#include <iostream>
#include <string>
#include <windows.h>

int getValue()//получаю количество эл-тов + проверяю на их правильность
{
reload:
	std::cout << "Сколько элментов в массиве?" << std::endl;
	int N;
	std::cin >> N;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Что-то пошло не так, попробуйте заново" << std::endl;
		goto reload;
	}
	else
	{
		std::cin.ignore(32767, '\n');
		return N;
	}
}

void getStringOfU(std::string* array, int N)//добавляю элементы в массив
{
	for (int count = 0; count < N; ++count)
	{
		std::cout << "Введите " << count + 1 << "-ый элемент массива" << std::endl;
		std::getline(std::cin, array[count]);
	}
}
/*НЕНУЖНАЯ ШТУКА
void myMalloc2(std::string* newarray, int N)
{
	std::string* array = new std::string[N];
	for (int count = 0; count < N-1; ++count)
	{
		newarray[count] = array[count];
	}
	delete[] newarray;
	newarray = nullptr;
}

void myRealloc(std::string* array, int N) 
{
	std::string* newarray = new std::string[N];

	for (int count = 0; count < N-1; ++count)
	{
		newarray[count] = array[count];
	}
	delete[] array;
	array = nullptr;
	myMalloc2(newarray, N);
}
*/
void getStringOfEnd(std::string* array, int N)//добавляю элемент в последний индекс массива
{
	std::cout << "Введите " << N << "-ый элемент массива" << std::endl;
	std::getline(std::cin, array[N-1]);
}

int main()
{
	SetConsoleCP(1251);//ввод русский символов
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");//вывод русских слов

	int N = getValue();

	std::string* array = new std::string[N];//массив array с N-элементами 

	getStringOfU(array, N);

inputRN:
	std::cout << "Вы хотите добавить новый элемент в массив? y/n - да/нет." << std::endl;
	std::string qestions;
	std::getline(std::cin, qestions);
	if (qestions == "y")
	{
		N += 1;// прибаляю 1, чтобы добавить новый элемент в массив
		std::string* newarray = new std::string[N];// временный массив newarray с N элементами

		for (int countold = 0; countold < N - 1; ++countold)// заполняю временный массив старыми элементами кроме последнего индекса, он имеет произволные данные
		{
			newarray[countold] = array[countold];
		}
		delete[] array;//удаляю старый массив
		array = newarray;

		getStringOfEnd(array, N);//заполняю последний индекс нужными МНЕ данными

		goto inputRN;//перехожу через гото, тем самым реализую типо-бесконечного-цикла
	}
	else if (qestions == "n")
	{
		goto exitFromCpp;
	}
	else if (qestions != "n" && qestions != "y")
	{
		std::cin.clear();
		std::cout << "Что-то пошло не так, попробуйте заново" << std::endl;
		goto inputRN;
	}

exitFromCpp:
	std::cout << "Итоговый массив: ";
	for (int count = 0; count < N; ++count)
	{
		std::cout << array[count] << " ";
	}
	std::cout << "\n" << "Конец программы" << std::endl;
	delete[] array;
	array = nullptr;
	return 0;
}
