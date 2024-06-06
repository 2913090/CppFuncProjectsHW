#include <iostream>
#include <string>
using namespace std;

class Burger {
public:
    int salad;
    int cheese;
    int tomatoes;
    int patty;
    bool sauce;
    void show() {
        cout << "Salad: " << salad << endl;
        cout << "Cheese: " << cheese << endl;
        cout << "Tomatoes: " << tomatoes << endl;
        cout << "Patty: " << patty << endl;
        cout << "Sauce: " << sauce << endl;
    }

};

class BurgerBuilder {
private:
    Burger* result;
public:
    BurgerBuilder() {

    }
    ~BurgerBuilder() {
        delete result;
    }
    BurgerBuilder& reset() {
        this->result = new Burger();
        return *this;
    }
    BurgerBuilder& setSalad(int count) {
        this->result->salad = count;
        return *this;
    }
    BurgerBuilder& setCheese(int count) {
        this->result->cheese = count;
        return *this;
    }
    BurgerBuilder& setTomatoes(int count) {
        this->result->tomatoes = count;
        return *this;
    }
    BurgerBuilder& setPatty(int count) {
        this->result->patty = count;
        return *this;
    }
    BurgerBuilder& setSauce(bool sauce) {
        this->result->sauce = sauce;
        return *this;
    }
    Burger* getResult() {
        return this->result;
    }
};

class Director {
private:
    BurgerBuilder burger;
public:
    Burger* constructBurger1() {
        burger.reset().setCheese(1).setPatty(1).setSalad(1).setSauce(true).setTomatoes(1);
        return burger.getResult();
    }
    Burger* constructBurger2() {
        burger.reset().setCheese(2).setPatty(2).setSalad(0).setSauce(true).setTomatoes(0);
        return burger.getResult();
    }
    Burger* constructBurger3() {
        burger.reset().setCheese(3).setPatty(2).setSalad(2).setSauce(false).setTomatoes(2);
        return burger.getResult();
    }
};

int main()
{
    Director director;
    Burger Burger1 = *director.constructBurger1();
    Burger1.show();
}