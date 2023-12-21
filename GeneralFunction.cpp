#include "GeneralFunction.h"

using namespace std;


int CheckInt() { //�������� ����������������� ����� �����
	int check = 0;
	cin >> check;
	while (cin.fail()) {//������� � ����������� ���������� C++, ������� ��������� ��� ���������, ������� �� ������ ������ ������ �� ������������ �����
		cout << "������� ������������ ��������, ���������� ��� ���: ";
		cin.clear();  //������� ���� ������ � cin (����� ������� �������� �����-������ �������� ���������)
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');  //������������� ������������ ���������� �������� ��� �������������. ('\n' - ������������ �������������)
		cin >> check;
	}
	cin.ignore(numeric_limits<streamsize> ::max(), '\n');
	return check;
}
 

string ReadStringWithoutWhitespace() { //�������� �� ������ ���� ������
	string input;
	while (true) {
		getline(cin, input);  //����� ������� ��� ������, ����� ��������� ����� `getline()`. �� ��������� ��� ������� � `std::cin` � ����������, � ������� ���� ������� ������.
		istringstream iss(input);  //istringstream - ����� �����, ���������� � ��������.
		if (iss >> input && !isspace(input[0])) { //������� isspace ��������� �������� �haracter, �������� �� �� �������� �������.���� >> ��������� ��������� ������ �� ������ �� ���������� �������
			return input;
		}
		else {
			cout << "������: ������� ������ �� ������ ��������� ��������. ��������� ������� �����." << endl;
		}
	}
}


bool FileExists(string fileName) { //��������� ������������� ���������� ����� ��� �������� 
	const char* path = fileName.c_str();
	if (!_access(path, 0)) { //access - �������� ���� ������� � �����.
		return true;
	}
	else {
		return false;
	}
}


bool OnlyRead(string fileName) {
	const char* path = fileName.c_str(); //������� c_str () ���������� ��������� �� ���������� ������, ������� �������� ������ ������� ������ (string) � ��� ����, � ������� ��� ����������� ��, �� ���������� ��������� ����.
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
	size_t pos = path.find_last_of("\\"); // ���� ��������� ������ '/' ��� '\'
	if (pos != string::npos) { // ���� ������ ������
		return path.substr(pos + 1); // ���������� ��� ����� ����� ���������� �������
	}
	return path; // ���� ������ �� ������, ���������� �������� ����
}


bool IsReservedFileName(string fileName) {
	const int quantityOfReservedNames = 22;
	string ReservedNames[quantityOfReservedNames] = { "con", "prn" , "aux" , "nul" , "com1" , "com2" , "com3" , "com4" , "com5" , "com6" , "com7" , "com8" , "com9" ,
	"lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6", "lpt7", "lpt8", "lpt9" };

	size_t pos = fileName.find_first_of(".");
	if (pos != string::npos) { //string::npo - ��� ��������� ����� ������������ ��� ��������� ���������� ������� ������� ��� ��������� � ������.
		fileName = fileName.substr(0, pos); //��� ���������� �������� �� ������������ ������ - substr()
	}

	for (int i = 0; i < quantityOfReservedNames; i++) {
		if (_stricmp(fileName.c_str(), ReservedNames[i].c_str()) == 0) { //������� stricmp() ������������ ������������������ ��������� ���� �����, �������������� �������� ���������.
			return true;
		}
	}
	return false;
}


void CopyArray(int** copyArray, int** array, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			copyArray[i][j] = array[i][j];
		}
	}
}


void PrintArray(int** array, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
}