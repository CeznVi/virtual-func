#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <bitset> //для використання функцій переводу у двійковий формат символів


using namespace std;

// Базовий клас принт файл
class printFile
{
protected:
	string text;

public:

	virtual void Display(const char* path);
	virtual void print();

};

//Нащадок. Друкує вміст файлу у вигляді кодування аскі.
class printFileAscii : public printFile
{

public:
	virtual void print() override;
};

//Нащадок. Друкує вміст файлу у вигляді восьмеричного (oct) кодування.
class printFileOct : public printFile
{

public:
	virtual void print() override;
};

//Нащадок. Друкує вміст файлу у вигляді шістнадцяткового (hex) кодування.
class printFileHex : public printFile
{

public:
	virtual void print() override;
};

void printFile::Display(const char* path)
{
	char temp{};
	ifstream fin;

	fin.open(path, std::ios::in);

	if (!fin)
	{
		std::cerr << "Помилка читання файлу...\n";
		exit(1);
	}
	//else
	//	cout << "Файл завантажено\n";

	if (fin.is_open())
	{
		while (fin.read(&temp, sizeof(char)))
			text += temp;
	}

	
	fin.close();
	print();
}

void printFile::print()
{
	cout << "Вміст файлу:\n";
	cout << text << '\n';
}

void printFileAscii::print()
{
	cout << "\nВміст файлу у вигляді кодування ASCII:\n";

	for (size_t i{}; i < text.size(); i++)
		cout << toascii(text[i]) << ' ';

	cout << '\n';
}

void printFileOct::print()
{
	cout << "\nВміст файлу у вигляді восьмеричного (oct) кодування:\n";

	for (size_t i{}; i < text.size(); i++)
		cout << bitset<8>(text[i]) << ' ';

	cout << '\n';
}

void printFileHex::print()
{
	cout << "\nВміст файлу у вигляді шістнадцяткового (hex) кодування:\n";

	for (size_t i{}; i < text.size(); i++)
		cout << hex << toascii(text[i]) << ' ';

	cout << '\n';
}
