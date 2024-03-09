#include <iostream>
#include <string>
using namespace std;

struct Product {
	string name;
	float volume;
	int* date;
};

int* parseDate(string date) {
	int* dateArray = new int[3];
	string str = "";
	for (int i = 0, j = 0; i < date.length(); i++)
	{
		if (date[i] == '.') {
			dateArray[j++] = stoi(str);
			str = "";
		}
		else if (i == date.length() - 1) {
			str += date[i];
			dateArray[j++] = stoi(str);
			str = "";
		}
		else {
			str += date[i];
		}
	}
	if (dateArray[0] > 31 ||
		dateArray[1] > 12 ||
		dateArray[2] > 9999
		) return nullptr;
	return dateArray;
}

Product* createProduct(string name, float volume, string date) {
	int* arrayDate = parseDate(date);
	if (arrayDate == nullptr) return nullptr;
	Product* product = new Product;
	product->name = name;
	product->volume = volume;
	product->date = arrayDate;
	return product;
}

void productInfo(Product* product) {
	cout << "Name: " << product->name
		<< "\nVolume: " << product->volume
		<< "\nDate: "
		<< product->date[0] << "."
		<< product->date[1] << "."
		<< product->date[2] << endl;

}

struct Fridge {
	string name = "VOLGA";
	float volumeCapacity = 0;
	float volume;
	int size = 0;
	Product** products = new Product * [0];
};

void addProduct(Fridge& fridge, Product* product) {
	if (fridge.volumeCapacity + product->volume > fridge.volume) {
		cout << "Fridge is full" << endl;
		return;
	}
	Product** buf = new Product* [fridge.size + 1];
	for (int i = 0; i < fridge.size; i++) {
		buf[i] = fridge.products[i];
	}
	buf[fridge.size] = product;
	fridge.volumeCapacity += product->volume;
	delete[] fridge.products;
	fridge.products = buf;
	fridge.size++;

}

void removeProduct(Fridge& fridge, Product* product) {
	if (fridge.volumeCapacity == 0) {
		cout << "Fridge is empty" << endl;
		return;
	}
	bool flag = 1;
	for (int i = 0; i < fridge.size; i++) {
		if ((fridge.products[i])->name == product->name) {
			flag = 0;
			break;
		}
	}
	if (flag) return;
	Product** buf = new Product * [fridge.size - 1];
	for (int count = 0, i = 0; i < fridge.size; i++) {
		if ((fridge.products[i])->name != product->name){
			buf[count++] = fridge.products[i];
		}
	}
	fridge.volumeCapacity -= product->volume;
	delete[] fridge.products;
	fridge.products = buf;
	fridge.size--;
}

void fridgeInfo(Fridge fridge) {
	cout << "---------------------------\n";
	cout << "Fridge: " << fridge.name << endl;
	cout << "Products: " << fridge.size << endl;
	cout << "Volume: " << fridge.volumeCapacity << "/" << fridge.volume << endl;
	cout << endl;
	for (int i = 0; i < fridge.size; i++) {
		productInfo(fridge.products[i]);
	}
	cout << "---------------------------\n";
}

void removeExpiredProducts(Fridge& fridge, string date) {
	int* arrayDate = parseDate(date);
	for (int i = 0; i < fridge.size; i++) {
		if (fridge.products[i]->date[2] < arrayDate[2]) {
			removeProduct(fridge, fridge.products[i]);
			continue;
		}
		else if (fridge.products[i]->date[2] == arrayDate[2] && fridge.products[i]->date[1] < arrayDate[1]) {
			removeProduct(fridge, fridge.products[i]);
			continue;
		}
		else if (fridge.products[i]->date[2] == arrayDate[2] && fridge.products[i]->date[1] == arrayDate[1] && fridge.products[i]->date[0] < arrayDate[0]) {
			removeProduct(fridge, fridge.products[i]);
		}
	}
}

int main()
{
	Product* pr1 = createProduct("Banana", 12, "14.03.2024");
	Product* pr2 = createProduct("Bread", 30, "05.03.2024");
	Product* pr3 = createProduct("eggs", 50, "12.05.2024");
	productInfo(pr1);
	Fridge fr1;
	fr1.name = "Volga";
	fr1.volume = 100;
	addProduct(fr1, pr1);
	addProduct(fr1, pr2);
	addProduct(fr1, pr3);
	fridgeInfo(fr1);
	removeExpiredProducts(fr1, "06.03.2024");
	fridgeInfo(fr1);
}