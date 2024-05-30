#include <iostream>
#include <stack>
#include <concepts>

using namespace std;

class Human {

};
class Weapon : public Human{

};

class AK74 : public Weapon {

};

class M416 : public Weapon {

};

class M9Barrete : public Weapon {

};

class Ammo : public Weapon {
protected:
	int damage;
	string name;
public:
	virtual int getDamage() = 0;
	virtual string getName() = 0;
};

class Ammo556 : public Ammo {

};

class Ammo556PS : public Ammo556 {
public:
	Ammo556PS() {
		this->damage = 10;
		this->name = "Ammo556PS";
	}
	int getDamage() { return this->damage; }
	string getName() { return this->name; }
};

class Ammo556BP : public Ammo556{
public:
	Ammo556BP() {
		this->damage = 15;
		this->name = "Ammo556BP";
	}
	int getDamage() { return this->damage; }
	string getName() { return this->name; }
};

class Ammo762 : public Ammo {

};

class Ammo762PS : public Ammo762 {
public:
	Ammo762PS() {
		this->damage = 17;
		this->name = "Ammo762PS";
	}
	int getDamage() { return this->damage; }
	string getName() { return this->name; }
};

class Ammo762BP : public Ammo762 {
public:
	Ammo762BP() {
		this->damage = 23;
		this->name = "Ammo762BP";
	}
	int getDamage() { return this->damage; }
	string getName() { return this->name; }
};

class Ammo919 : public Ammo {

};

class Ammo919PS : public Ammo919 {
public:
	Ammo919PS() {
		this->damage = 5;
		this->name = "Ammo919PS";
	}
	int getDamage() { return this->damage; }
	string getName() { return this->name; }
};

class Ammo919BP : public Ammo919 {
public:
	Ammo919BP() {
		this->damage = 8;
		this->name = "Ammo919BP";
	}
	int getDamage() { return this->damage; }
	string getName() { return this->name; }
};

template<typename T>
concept AmmoType = is_base_of<Ammo, remove_pointer_t <T>>::value && !is_same_v<Ammo, remove_pointer_t <T>>;
template<AmmoType T>
class Magazin : public Weapon {
	int amount;
	stack<T> bullets;
public:
	Magazin(int amount) : amount(amount){};
	void load(T bullet) {
		if (bullets.size() >= amount) throw out_of_range("full");
		bullets.push(bullet);
	}
	T unload() {
		if(bullets.empty())throw out_of_range("empty");
		T bullet = bullets.top();
		bullets.pop();
		return bullet;
	}
	stack<T> fullUnload() {
		if (bullets.empty())throw out_of_range("empty");
		stack<T> unloadBullets = bullets;
		while (!bullets.empty) bullets.pop;
		return unloadBullets;
	}
	void info() {
		cout << "Type: " << bullets.top()->getName() << endl;
		cout << "Bullets: " << bullets.size() << endl;
	}
};

int main()
{
	Ammo556BP* ammo1 = new Ammo556BP;
	Ammo556PS* ammo2 = new Ammo556PS;
	Ammo762BP* ammo3 = new Ammo762BP;
	Ammo762PS* ammo4 = new Ammo762PS;
	Ammo919BP* ammo5 = new Ammo919BP;
	Ammo919PS* ammo6 = new Ammo919PS;
	Magazin<Ammo556*> m556(10);
	for (int i = 0; i < 5; i++){
		m556.load(new Ammo556BP);
		m556.load(new Ammo556PS);
	}
	m556.info();


}
