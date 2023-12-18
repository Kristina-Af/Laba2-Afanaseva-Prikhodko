#include "GeneralFunction.h"

using namespace std;

//Проверка пользовательского ввода числа
int CheckInt() {
	int tmp = 0;
	cin >> tmp;
	while (cin.fail()) {//функция в стандартной библиотеке C++, которая позволяет нам проверить, успешно ли прошло чтение данных из стандартного ввода
		cout << "Введено некорректное значение, попробуйте еще раз: ";
		cin.clear();  //снимает флаг ошибки с cin (чтобы будущие операции ввода-вывода работали корректно)
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');  //устанавливает максимальное количество символов для игнорирования. ('\n' - прекращается игнорирование)
		cin >> tmp;
	}
	cin.ignore(numeric_limits<streamsize> ::max(), '\n');
	return tmp;
}
 
//Проверка на пустой ввод строки.
string ReadStringWithoutWhitespace() {
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

//проверка файла
bool File_Exists(string FileName) { //проверяет существование указанного файла или каталога 
	const char* path = FileName.c_str();
	if (!_access(path, 0)) { //access - Проверка прав доступа к файлу.
		return true;
	}
	else {
		return false;
	}
}

//чтение из файла
bool Only_Read(string FileName) {
	const char* path = FileName.c_str(); //Функция c_str () возвращает указатель на символьный массив, который содержит строку объекта стринг (string) в том виде, в котором она размещалась бы, во встроенном строковом типе.
	if (_access(path, 2)) {
		return true;
	}
	else
		return false;
}

//проверка на допустимые имена
bool IsValidFilename(const string& filename) {
	static const regex pattern("^[a-zA-Z0-9_\\-\\.]+$");
	return regex_match(filename, pattern);
}

//полученние имени файла
string getFilename(const string path) {
	size_t pos = path.find_last_of("\\"); // Ищем последний символ '/' или '\'
	if (pos != string::npos) { // Если символ найден
		return path.substr(pos + 1); // Возвращаем имя файла после найденного символа
	}
	return path; // Если символ не найден, возвращаем исходный путь
}

//проверка на зарезервированные имена
bool IsReservedFileName(string FileName) {
	const int QuantityOfReservedNames = 22;
	string ReservedNames[QuantityOfReservedNames] = { "con", "prn" , "aux" , "nul" , "com1" , "com2" , "com3" , "com4" , "com5" , "com6" , "com7" , "com8" , "com9" ,
	"lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6", "lpt7", "lpt8", "lpt9" };

	size_t pos = FileName.find_first_of(".");
	if (pos != string::npos) { //string::npo - Эта константа часто используется для индикации отсутствия позиции символа или подстроки в строке.
		FileName = FileName.substr(0, pos); //для извлечения подстрок из определенной строки - substr()
	}

	for (int i = 0; i < QuantityOfReservedNames; i++) {
		if (_stricmp(FileName.c_str(), ReservedNames[i].c_str()) == 0) { //функция stricmp() осуществляет лексикографическое сравнение двух строк, оканчивающихся нулевыми символами.
			return true;
		}
	}
	return false;
}

//копирование массива
void CopyArray(int** copyarray, int** array, int strings, int columns) {
	for (int i = 0; i < strings; i++) {
		for (int j = 0; j < columns; j++) {
			copyarray[i][j] = array[i][j];
		}
	}
}

//печать массива
void PrintArray(int** array, int strings, int columns) {
	for (int i = 0; i < strings; i++) {
		for (int j = 0; j < columns; j++) {
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
}