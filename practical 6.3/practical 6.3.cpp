#include <iostream>
#include <queue>
using namespace std;

// -------- Fuel Class --------
class Fuel {
protected:
    string fuelType;

public:
    Fuel(string f) {
        fuelType = f;
    }

    void showFuel() {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// -------- Brand Class --------
class Brand {
protected:
    string brandName;

public:
    Brand(string b) {
        brandName = b;
    }

    void showBrand() {
        cout << "Brand: " << brandName << endl;
    }
};

// -------- Car Class (Hybrid Inheritance) --------
class Car : public Fuel, public Brand {
private:
    int carID;

public:
    // Constructor chaining
    Car(int id, string f, string b)
        : Fuel(f), Brand(b) {
        carID = id;
    }

    void displayCar() {
        cout << "\nCar ID: " << carID << endl;
        showFuel();
        showBrand();
        cout << "------------------------\n";
    }
};

// -------- MAIN FUNCTION --------
int main() {

    // -------- Method 1: Static Array --------
    cout << "=== Static Method ===\n";

    Car cars[2] = {
        Car(1, "Petrol", "Toyota"),
        Car(2, "Electric", "Tesla")
    };

    for (int i = 0; i < 2; i++) {
        cars[i].displayCar();
    }

    // -------- Method 2: Queue (Service Line) --------
    cout << "\n=== Queue Method (Service Line) ===\n";

    queue<Car> serviceQueue;

    serviceQueue.push(Car(3, "Diesel", "Hyundai"));
    serviceQueue.push(Car(4, "Petrol", "Honda"));

    while (!serviceQueue.empty()) {
        Car c = serviceQueue.front();
        c.displayCar();
        serviceQueue.pop();
    }

    return 0;
}
