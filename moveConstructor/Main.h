#pragma once

#include <iostream>
using namespace std;

class MyString {
	char* str;
	int size;
	static int count;

public:
	MyString();
	MyString(int length);
	MyString(const char* Str);
	MyString(const MyString& string);
	MyString(const initializer_list<char>& list);
    MyString(MyString&& obj)
	{
		cout << "Move constructor\n";
		str = obj.str;
		obj.str = nullptr;
		size = obj.size;
	}
	MyString& operator=(MyString&& obj)
	{
		cout << "operator overload = move\n";
		if (this != &obj) {
			delete[] str;
			str = obj.str;
			obj.str = nullptr;
			size = obj.size;
		}
		return *this;
	}
	void StrInput();
	void Output();
	
	static int GetCount();
	int GetSize() const;
	char* GetStr() const;
	void SetSize(int newSize);
	void SetStr(char* newStr);

	MyString& operator++();
	MyString& operator--();
	MyString operator+(int number) const;
	MyString operator-(int number) const;
	MyString& operator=(const MyString& object);
	MyString operator++(int);
	MyString operator--(int);

	~MyString();
	char& operator[](int index);

	friend istream& operator>>(istream& is, MyString& myString);
	friend ostream& operator<<(ostream& os, const MyString& myString);
};

int MyString::count = 0;
MyString operator+(int number, const MyString& myString);


int main()
{
	MyString str1;
	cin >> str1;

	MyString str2(20);
	cin >> str2;

	MyString str3("Hello");

	cout << "\nObjects str: \n\n";


	cout << str1;
	cout << str2;
	cout << str3;
	cout << endl;

	MyString str4 = str3;
	cout << str4;
	cout << endl;

	MyString increment = ++str3;
	cout << "Increment: " << increment << endl;

	MyString decrement = --str3;
	cout << "Decrement: " << decrement << endl;

	MyString plus = str3 + 4;
	cout << "Plus: " << plus << endl;


	MyString minus = str3 - 2;
	cout << "Minus: " << minus << endl;

	str1 = str2;
	cout << str1 << endl;

	cout << "Operation of the postfix form of increment" << endl;
	increment++;
	cout << increment << endl;
	cout << "Operation of the postfix form of dikrimenta" << endl;
	decrement--;
	cout << decrement << endl;

	MyString HelloWorld = "Hello Word";
	MyString newString;
	newString = 4 + HelloWorld;
	cout << newString << endl;


	cout << "\nNumber of objects created " << MyString::GetCount() << endl;

	cout << "\nInitializer List" << endl;

	MyString WordList{ 'H','e','l','l','o','\0','W','o','r','l', 'd' };
	for (int i = 0; i < 11; i++) {
		cout << WordList[i] << ' ';
	}

	return 0;
}
