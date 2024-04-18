#include <iostream>
#include <string>

using namespace std;


class MyString {
private:
	char* str;

public:
	MyString() {
		str = nullptr;
	}
	MyString(const char* str) {
		this->str = strCopy(str);
	}

	void print() {
		cout << this->str;
	}

	~MyString() {
		delete[] this->str;
	}

	MyString& operator =(const MyString& other) {
		//if (other.str == nullptr) {
		//}
		if (this == &other) return *this;
		if (this->str != nullptr) {
			delete[] this->str;
		}
		this->str = strCopy(other.str);
		return *this;
	}

	MyString& operator +(const MyString& stroka) {
		int length1 = strlen(this->str);
		int length2 = strlen(stroka.str);
		MyString* newStr = nullptr;
		newStr = new MyString[length1 + length2 + 1];
		for (int i = 0; i < length1; i++)
		{
			newStr->str[i] = this->str[i];
		}
		for (int i = 0; i < length2; i++)
		{
			newStr->str[length1 + i] = this->str[i];
		}
		newStr->str[length1 + length2] = '\0';
		return *newStr;
	}
private:
	char* strCopy(const char* str) {
		char* newStr;
		int length = strlen(str);
		newStr = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			newStr[i] = str[i];
		}
		newStr[length] = '\0';
		return newStr;
	}
};

int main()
{


	/*char* test = new char[] {"12345"};
	MyString str1 = test;*/
	//str1.print();
	MyString str1 = "Test";
	MyString str2;
	str1.print();
	cout << endl;
	str2 = str1;
	str2.print();
	/*MyString str3;
	str3 = str1 + str2;
	str3.print();*/
}