#include <iostream>
#include <stack>

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
public:
	virtual int getDamage() = 0;
};

class Ammo556 : public Ammo {

};

class Ammo556PS : public Ammo556 {
	Ammo556PS(int damage) {
		this->damage = damage;
	}
};

class Ammo556BP : public Ammo556{
	Ammo556BP(int damage) {
		this->damage = damage;
	}
};

class Ammo762 : public Ammo {

};

class Ammo762PS : public Ammo762 {
	Ammo762PS(int damage) {
		this->damage = damage;
	}
};

class Ammo762BP : public Ammo762 {
	Ammo762BP(int damage) {
		this->damage = damage;
	}
};

class Ammo919 : public Ammo {

};

class Ammo919PS : public Ammo919 {
	Ammo919PS(int damage) {
		this->damage = damage;
	}
};

class Ammo919BP : public Ammo919 {
	Ammo919BP(int damage) {
		this->damage = damage;
	}
};

int main()
{

}