#include <iostream>
#include <stack>

using namespace std;

class Engine {
public:
	string engineNo;
	string company;
	double volume;
	Engine() {}
	Engine(string engineNo, string company, double volume) {
		this->engineNo = engineNo;
		this->company = company;
		this->volume = volume;
	}
	void Show() {
		cout << "Engine Company: " << company << "\nEngine No: " << engineNo << "\nEngine Volume: " << volume << endl;
	}
};

class Vehicle {
public:
	static int staticId;
	int id;
	string vendor;
	string model;
	Engine engine;

	Vehicle(string _vendor, string _model, Engine _engine) {
		id = staticId++;
		vendor = _vendor;
		model = _model;
		engine = _engine;
	}
	virtual void Show() {
		cout << "Id: " << id << "\nVendor: " << vendor << "\nModel: " << model << "\n";
		engine.Show();
	}
};
int Vehicle::staticId = 100;

class Car : public Vehicle {
public:
	bool hasSpoiler;

	Car(string vendor, string model, Engine engine, bool _hasSpoiler) : Vehicle(vendor, model, engine) {
		hasSpoiler = _hasSpoiler;
	}

	void Show() {
		cout << endl;
		cout << "*****Car*****\n";
		Vehicle::Show();
		cout << "Spoiler: " << (hasSpoiler ? "var" : "yox") << endl;
	}
};

class Ship : public Vehicle {
public:
	bool hasSail;

	Ship(string vendor, string model, Engine engine, bool _hasSpoiler) : Vehicle(vendor, model, engine) {
		hasSail = _hasSpoiler;
	}

	void Show() {
		cout << endl;
		cout << "*****Ship*****\n";
		Vehicle::Show();
		cout << "Sail: " << (hasSail ? "var" : "yox") << endl;
	}
};

class Airplane : public Vehicle {
public:
	int engineCount;
	int passengercapacity;
	Airplane(string vendor, string model, Engine engine, bool _hasSpoiler,int _engineCount,int _passengercapacity) : Vehicle(vendor, model, engine) {
		engineCount = _engineCount;
		passengercapacity = _passengercapacity;

	}

	void Show() {
		cout << endl;
		cout << "*****Airplane*****\n";
		Vehicle::Show();
		cout << "Engine count : " << engineCount << endl;
		cout << "Passenger capacity : " << passengercapacity << endl;
	}
};

class Garrage {
public:
	stack<Vehicle*> vehicles;

	void AddVehicle(Vehicle* vehicle) {
		vehicles.push(vehicle);
	}

	void ShowAllVehicles() {
		while (!vehicles.empty()) {
			vehicles.top()->Show();
			vehicles.pop();
		}
	}
};

void main() {
	Garrage* garrage = new Garrage();
	garrage->AddVehicle(new Car("Wolksvagen", "Touareg", Engine("3.0 V6 TSI", "Wolksavegn", 3.6), false));
	garrage->AddVehicle(new Ship("yamaha", "SX220", Engine("TWIN TR-1 HIGH OUTPUT", "YAMAHA MARINE ENGINES", 1.6), false));
	garrage->AddVehicle(new Airplane("Azal", "A21", Engine("Azal123", "Az", 3700), false, 2, 200));
	garrage->ShowAllVehicles();
}