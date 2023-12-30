#include "GeneralFunction.h"

using namespace std;


int CheckInt() { //Проверка пользовательского ввода числа
	int check = 0;
	cin >> check;
	while (cin.fail()) {//функция в стандартной библиотеке C++, которая позволяет нам проверить, успешно ли прошло чтение данных из стандартного ввода
		cout << "Введено некорректное значение, попробуйте еще раз: ";
		cin.clear();  //снимает флаг ошибки с cin (чтобы будущие операции ввода-вывода работали корректно)
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');  //устанавливает максимальное количество символов для игнорирования. ('\n' - прекращается игнорирование)
		cin >> check;
	}
	cin.ignore(numeric_limits<streamsize> ::max(), '\n');
	return check;
}
 

string ReadStringWithoutWhitespace() { //Проверка на пустой ввод строки
	string input;
	while (true) {
		getline(cin, input);  //Чтобы считать всю строку, можно применить метод `getline()`. Он принимает два объекта — `std::cin` и переменную, в которую надо считать строку.
		istringstream iss(input);  //istringstream - поток ввода, работающий с строками.
		if (iss >> input && !isspace(input[0])) { //Функция isspace проверяет параметр сharacter, является ли он символом пробела.знак >> позволяет извлекать данные из строки по указанному формату
			return input;
		}
		else {
			cout << "Ошибка: входные данные не должны содержать пробелов. Повторите попытку ввода." << endl;
		}
	}
}


bool FileExists(string fileName) { //проверяет существование указанного файла или каталога 
	const char* path = fileName.c_str();
	if (!_access(path, 0)) { //access - Проверка прав доступа к файлу.
		return true;
	}
	else {
		return false;
	}
}


bool OnlyRead(string fileName) {
	const char* path = fileName.c_str(); //Функция c_str () возвращает указатель на символьный массив, который содержит строку объекта стринг (string) в том виде, в котором она размещалась бы, во встроенном строковом типе.
	if (_access(path, 2)) {
		return true;
	}
	else
		return false;
}


bool IsValidFileName(const string& filename) {
	static const regex pattern("^[a-zA-Z0-9_\\-\\.]+$");
	return regex_match(filename, pattern);
}


string GetFileName(const string path) {
	size_t pos = path.find_last_of("\\"); // Ищем последний символ '/' или '\'
	if (pos != string::npos) { // Если символ найден
		return path.substr(pos + 1); // Возвращаем имя файла после найденного символа
	}
	return path; // Если символ не найден, возвращаем исходный путь
}


bool IsReservedFileName(string fileName) {
	const int quantityOfReservedNames = 22;
	string ReservedNames[quantityOfReservedNames] = { "con", "prn" , "aux" , "nul" , "com1" , "com2" , "com3" , "com4" , "com5" , "com6" , "com7" , "com8" , "com9" ,
	"lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6", "lpt7", "lpt8", "lpt9" };

	size_t pos = fileName.find_first_of(".");
	if (pos != string::npos) { //string::npo - Эта константа часто используется для индикации отсутствия позиции символа или подстроки в строке.
		fileName = fileName.substr(0, pos); //для извлечения подстрок из определенной строки - substr()
	}

	for (int i = 0; i < quantityOfReservedNames; i++) {
		if (_stricmp(fileName.c_str(), ReservedNames[i].c_str()) == 0) { //функция stricmp() осуществляет лексикографическое сравнение двух строк, оканчивающихся нулевыми символами.
			return true;
		}
	}
	return false;
}


void CopyArray(int* copyArray, int* array, int size) {
	for (int i = 0; i < size; i++) {
		copyArray[i] = array[i];
	}
}


void PrintArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}