#include <iostream>
using namespace std;

class Transport {

public:
    virtual void move() = 0;
    virtual void sound() = 0;
};

class WaterTransport : public Transport {

};

class GroundTransport : public Transport {

};

class AirTransport : public Transport {

};


class Car : public GroundTransport {
    float Engine;
public:

    Car(float Engine) {
        this->Engine = Engine;
    }
    void move() {
        cout << "Drive car" << endl;
    }
    void sound() {
        cout << "Beep!" << endl;
    }

};

class SportCar : public Car {
    string carcase;
public:

    SportCar(float Engine, string carcase) : Car(Engine) {
        this->carcase = carcase;
    }
    void move() {
        cout << "Drive sportcar" << endl;
    }
    void sound() {
        cout << "Wroom Wroom!" << endl;
    }

};


class Bicycle : public GroundTransport {
    float diametrDisc;
public:
    Bicycle(float diametrDisc) {
        this->diametrDisc = diametrDisc;
    }
    void move() {
        cout << "Drive bicycle" << endl;
    }
    void sound() {
        cout << "Dziiin!" << endl;
    }

};

class Train : public GroundTransport {
    int VagonsCount;
public:
    Train(int VagonsCount) {
        this->VagonsCount = VagonsCount;
    }
    void move() {
        cout << "Drive" << endl;
    }
    void sound() {
        cout << "Tuduk Tuduk!" << endl;
    }
};

class Submarine : public WaterTransport {
    float Square;
public:
    Submarine(float Square) {
        this->Square = Square;
    }
    void move() {
        cout << "Swim" << endl;
    }
    void sound() {
        cout << "AAAAAAAAAAAAAAAAAAAAAAAA!" << endl;
    }
};

class Boat : public WaterTransport {
    float width;
public:
    Boat(float width) {
        this->width = width;
    }
    void move() {
        cout << "Swim" << endl;
    }
    void sound() {
        cout << "UUUUUU!" << endl;
    }
};

class Plane : public AirTransport {
    int passagireMest;
public:
    Plane(int passagireMest) {
        this->passagireMest = passagireMest;
    }
    void move() {
        cout << "plane" << endl;
    }
    void sound() {
        cout << "RUIRURUURUSIAIUR!" << endl;
    }
};

class Hellycopter : public AirTransport {
    float lenth;
public:
    Hellycopter(float lenth) {
        this->lenth = lenth;
    }
    void move() {
        cout << "plane" << endl;
    }
    void sound() {
        cout << "TUUTUTUTU!" << endl;
    }
};


class WaterParking {
public:
    string name;
    WaterTransport** transports = new WaterTransport * [0];
    int size = 0;

    WaterParking(string name) {
        this->name = name;
    }

    void addTransport(WaterTransport* transport) {
        WaterTransport** buf = new WaterTransport * [size + 1];
        for (int i = 0; i < size; i++)
        {
            buf[i] = this->transports[i];
        }
        buf[size++] = transport;
        delete[] this->transports;
        this->transports = buf;
    }

    void info() {
        for (int i = 0; i < size; i++)
        {
            transports[i]->sound();
        }
    }


};

class GroundParking {
public:
    string name;
    GroundTransport** transports = new GroundTransport * [0];
    int size = 0;

    GroundParking(string name) {
        this->name = name;
    }

    void addTransport(GroundTransport* transport) {
        GroundTransport** buf = new GroundTransport * [size + 1];
        for (int i = 0; i < size; i++)
        {
            buf[i] = this->transports[i];
        }
        buf[size++] = transport;
        delete[] this->transports;
        this->transports = buf;
    }

    void info() {
        for (int i = 0; i < size; i++)
        {
            transports[i]->sound();
        }
    }


};

class AirParking {
public:
    string name;
    AirTransport** transports = new AirTransport * [0];
    int size = 0;

    AirParking(string name) {
        this->name = name;
    }

    void addTransport(AirTransport* transport) {
        AirTransport** buf = new AirTransport * [size + 1];
        for (int i = 0; i < size; i++)
        {
            buf[i] = this->transports[i];
        }
        buf[size++] = transport;
        delete[] this->transports;
        this->transports = buf;
    }

    void info() {
        for (int i = 0; i < size; i++)
        {
            transports[i]->sound();
        }
    }


};

int main()
{
    WaterParking waterPark("Blue Sea Parking");
    Boat* t1 = new Boat(30);
    Submarine* t2 = new Submarine(30);

    waterPark.addTransport(t1);
    waterPark.addTransport(t2);
    waterPark.info();

    cout << endl;

    AirParking airPark("Air Park");
    Plane* t3 = new Plane(30);
    Hellycopter* t4 = new Hellycopter(12.5);
    airPark.addTransport(t3);
    airPark.addTransport(t4);
    airPark.info();

    cout << endl;

    GroundParking groundPark("Ground Park");
    Car* t5 = new Car(30);
    SportCar* t6 = new SportCar(100, "gg");

    groundPark.addTransport(t5);
    groundPark.addTransport(t6);
    groundPark.info();
}