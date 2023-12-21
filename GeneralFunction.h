#pragma once
#include <iostream>//������ � ������ ������ ������
#include <fstream> //����������� ���������� �������, �������������� �������� iostreams ��� �������������������, ���������� �� ������� ������
#include <string> //������ �� ��������
#include <sstream> //��� ������ � Istringstream ���������� ���������� ������������ ���� <sstream>. 
#include <limits> //���������� � ��������� ��������������� �������� ����� ������
#include <io.h> //��� ������ � ������ � �������
#include <regex> //��� ������ � ����������� �����������, ��� ������� ������������ ��� ������ � ��������� ��������� ����������

using namespace std;

int CheckInt();
string ReadStringWithoutWhitespace();

/// <summary>
/// �������� �����
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
bool FileExists(string fileName);

/// <summary>
/// ������ �� �����
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
bool OnlyRead(string fileName);

/// <summary>
/// �������� �� ���������� �����
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
bool IsValidFileName(const string& fileName);

/// <summary>
/// ���������� ����� �����
/// </summary>
/// <param name="path"></param>
/// <returns></returns>
string GetFileName(const string path);

/// <summary>
/// �������� �� ����������������� �����
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
bool IsReservedFileName(string fileName);

/// <summary>
/// ����������� �������
/// </summary>
/// <param name="copyArray"></param>
/// <param name="array"></param>
/// <param name="rows"></param>
/// <param name="columns"></param>
void CopyArray(int** copyArray, int** array, int rows, int columns);

/// <summary>
/// ������ �������
/// </summary>
/// <param name="array"></param>
/// <param name="rows"></param>
/// <param name="columns"></param>
void PrintArray(int** array, int rows, int columns);