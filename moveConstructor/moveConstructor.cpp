#include "Main.h"

MyString::MyString() : MyString(80) {
}

MyString::MyString(int length) : size(length) {
	str = new char[size + 1];
	strcpy_s(str, size + 1, "");
	count++;
}

MyString::MyString(const char* Str) : MyString(strlen(Str)) {
	strcpy_s(str, size + 1, Str);
	cout << "The copy constructor worked" << endl;
}

MyString::MyString(const MyString& string) : MyString(string.size) {
	strcpy_s(str, size + 1, string.str);
}

MyString::MyString(const initializer_list<char>& list) : MyString(list.size()) {
	int length = list.size();
	char* current = str;

	for (auto ptr = list.begin(); ptr != list.end(); ptr++) {
		*current = *ptr;
		current++;
	}
}

void MyString::StrInput() {
	cout << "Enter a string: ";
	cin.getline(str, size + 1);
}

void MyString::Output() {
	cout << "String: " << str << endl;
}

int MyString::GetCount()
{
	return count;
}

int MyString::GetSize() const
{
	return size;
}

char* MyString::GetStr() const
{
	return str;
}

void MyString::SetSize(int newSize) {
	size = newSize;
}

void MyString::SetStr(char* newStr) {
	str = newStr;
}
MyString& MyString::operator++ () {

	int newSize = size + 1;
	char* newString = new char[newSize + 1];

	strcpy_s(newString, newSize + 1, str);
	newString[size] = 'x';
	newString[newSize] = '\0';

	delete[] str;
	str = newString;
	size = newSize;

	return *this;
}

MyString& MyString::operator-- () {

	if (size > 0) {

		int newSize = size - 1;
		char* newString = new char[newSize + 1];

		strncpy_s(newString, newSize + 1, str, newSize);
		newString[newSize] = '\0';

		delete[] str;
		str = newString;
		size = newSize;
	}

	return *this;
}

MyString MyString::operator+(int number) const {

	if (number < 0) {
		return *this;
	}

	int newSize = size + number;
	char* newStr = new char[newSize + 1];

	strcpy_s(newStr, newSize + 1, str);

	for (int i = size; i < newSize; ++i) {

		newStr[i] = 'x';
	}
	newStr[newSize] = '\0';

	MyString newString(newStr);

	delete[] newStr;

	return newString;

}
char& MyString::operator[](int index){

	return str[index];
}
MyString MyString::operator-(int number) const {

	if (number <= 0 || number > size) {
		return *this;
	}

	int newSize = size - number;
	char* newStr = new char[newSize + 1];

	strncpy_s(newStr, newSize + 1, str, newSize);

	newStr[newSize] = '\0';

	MyString newString(newStr);

	delete[] newStr;
	return newString;
}

MyString& MyString::operator=(const MyString& object)
{
	cout << "Copy assignment\n";
	if (!(this == &object))
	{
		if (str != nullptr)
		{
			delete[] str;
		}
		if (object.str == nullptr)
		{
			str = nullptr;
			size = object.size;
			return *this;
		}
		str = new char[strlen(object.str) + 1];
		strcpy_s(str, strlen(object.str) + 1, object.str);
		size = object.size;
		return *this;
	}
	return *this;
}


MyString MyString::operator++ (int) {

	MyString temp(*this);
	operator++();
	return temp;
}

MyString MyString::operator-- (int) {

	MyString temp(*this);
	operator--();
	return temp;
}

MyString::~MyString() {
	delete[] str;
	count--;
}


istream& operator>>(istream& is, MyString& myString) {
	cout << "Enter a string: ";
	is.getline(myString.str, myString.size + 1);
	return is;
}

ostream& operator<<(ostream& os, const MyString& myString) {
	os << "String: " << myString.str << '\t';
	os << "Size of string = " << myString.size << '\n';
	return os;
}

MyString operator+(int number, const MyString& myString) {

	if (number < 0) {
		return myString;
	}

	MyString temp;

	temp.SetSize(myString.GetSize() + number);
	temp.SetStr(new char[temp.GetSize() + 1]);

	for (int i = 0; i < number; ++i) {

		temp.GetStr()[i] = 'x';
	}

	if (myString.GetStr() != nullptr) {
		strcpy_s(temp.GetStr() + number, myString.GetSize() + 1, myString.GetStr());
	}

	return temp;
}