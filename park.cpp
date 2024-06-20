#include "Param.h"

class Vehicle {
private:
    string licensePlate;
    int vehicleId;
    string vehicleType;
    static int curId;
public:
    Vehicle(string licensePlate, string vehicleType) : licensePlate(licensePlate), vehicleId(++curId), vehicleType(vehicleType){}

    int getVehicleId() {
        return vehicleId;
    }

    void info() {
        cout << "LicensePlate: " << licensePlate << endl;
        cout << "Id: " << vehicleId << endl;
        cout << "Type: " << vehicleType << endl;
    }
};

class ParkingSpot {
private:
    int spotId;
    bool isOccupied;
    string spotType;
public:

};

class ParkingTicket {
private:
    int ticketId;
    int vehicleId;
    static int spotId;
    time_t entryTime;
public:
    ParkingTicket(int vehicleId) {
        this->entryTime = time(nullptr);
    }

    double getTime() {
        return difftime(time(nullptr), entryTime);
    }
};

class ParkingLot {
private:
    vector<ParkingSpot> parkingSpots;
    vector<Vehicle> vehicles;
    vector<ParkingTicket> parkingTickets;
public:

};

class ParkingFeeCalculator {
private:
    float hourlyRate;
    float dailyRate;
public:
    void setHourlyRate(float hourlyRate) {
        this->hourlyRate = hourlyRate;
    }

    void setDailyRate(float dailyRate) {
        this->dailyRate = dailyRate;
    }

    float getHourlyRate() {
        return hourlyRate;
    }

    float setDailyRate() {
        return dailyRate;
    }


};

int Vehicle::curId = 0;

int main()
{
    setlocale(LC_ALL,"");
    int task;
    bool flag = true;
    while (flag) {
        cout << "Въезд транспортного средства(1)" << endl;
        cout << "Выезд транспортного средства(2)" << endl;
        cout << "Текущее состояние парковки(3)" << endl;
        cout << "Отчет о заработанных средствах(4)" << endl;
        cout << "Завершить работы программы и сохраненить данные(5)" << endl;

        switch (task) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:


            flag = false;
            break;
        }
    }
}