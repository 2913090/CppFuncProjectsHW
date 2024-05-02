#include <iostream>
#include <string>

using namespace std;


class MyString {
private:
	char* str;

public:
	MyString() {
		str = new char[]{'\0'};
	}
	MyString(const char* str) {
		this->str = strCopy(str);
	}

	~MyString() {
		delete[] this->str;
	}

	friend ostream& operator << (ostream& out, MyString& myStr) {
		out << myStr.str;
		return out;
	}

	int length() {
		return strlen(this->str);
	}

	MyString& operator =(const MyString& other) {
		if (this == &other) return *this;
		if (this->str != nullptr) {
			delete[] this->str;
		}
		this->str = strCopy(other.str);
		return *this;
	}

	MyString& operator +(const MyString& other) {
		MyString* newStr = new MyString;
		*newStr += *this;
		*newStr += other;
		return *newStr;
	}

	void operator +=(const MyString& other) {
		int length1 = strlen(this->str);
		int length2 = strlen(other.str);
		char* newStr = new char[length1 + length2 + 1];
		for (int i = 0; i < length1; i++)
		{
			newStr[i] = this->str[i];
		}
		for (int i = 0; i < length2; i++)
		{
			newStr[length1 + i] = other.str[i];
		}
		newStr[length1 + length2] = '\0';
		delete[] this->str;
		this->str = newStr;
	}

	char& operator [](int index) {
		if (index >= this->length() || index < 0) throw;
		return this->str[index];
	}

	bool operator ==(MyString& other) {
		if (this->length() != other.length()) return false;
		for (int i = 0; i < other.length(); i++){
			if (this->str[i] != other.str[i]) return false;
		}
		return true;
	}

	bool operator !=(MyString& other) {
		if (this->length() != other.length()) return true;
		for (int i = 0; i < other.length(); i++) {
			if (this->str[i] != other.str[i]) return true;
		}
		return false;
	}

	bool operator >(MyString& other) {
		int length = (this->length() > other.length()) ? other.length() : this->length();
		for (int i = 0; i < length; i++) {
			if (this->str[i] > other.str[i]) return true;
		}
		if (this->length() > other.length()) return true;
		return false;
	}

	bool operator <(MyString& other) {
		int length = (this->length() > other.length()) ? other.length() : this->length();
		for (int i = 0; i < length; i++) {
			if (this->str[i] < other.str[i]) return true;
		}
		if (this->length() < other.length()) return true;
		return false;
	}

	bool operator >=(MyString& other) {
		if (this == &other) return true;
		if (this > &other) return true;
		return false;
	}

	bool operator <=(MyString& other) {
		if (this == &other) return true;
		if (this < &other) return true;
		return false;
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
	//for (int i = 0; i < 255; i++){
	//	cout << i << " " << char(i) << endl;
	//}
	MyString str2 = "Hello";
	MyString str1 = "hel";
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str1 << " == " << str2 << " = " << (str1 == str2) << endl;
	cout << str1 << " != " << str2 << " = " << (str1 != str2) << endl;
	cout << str1 << " > " << str2 << " = " << (str1 > str2) << endl;
	cout << str1 << " < " << str2 << " = " << (str1 < str2) << endl;
	cout << str1 << " >= " << str2 << " = " << (str1 >= str2) << endl;
	cout << str1 << " <= " << str2 << " = " << (str1 <= str2) << endl;
}