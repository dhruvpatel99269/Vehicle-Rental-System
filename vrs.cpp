#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Vehicle 
{
protected:
    string make;
    string model;
    double dailyRate;
    bool rented;
    string vehicletype;

public:
    Vehicle(const string& make, const string& model, double dailyRate, const string& type)
        : make(make), model(model), dailyRate(dailyRate), rented(false), vehicletype(type) {}

    const string& getMake() const
    {
        return make;
    }

    const string& getModel() const 
    {
        return model;    
    }

    double getRate() const
    {
        return dailyRate;
    }

    bool isRented() const 
    {
        return rented;
    }

    void rent() 
    {
        rented = true;
    }

    void returnVehicle() 
    {
        rented = false;
    }

    string getVehicleType() const
    {
        return vehicletype;
    }

    virtual double calculateRentalFee(int days) const 
    {
        return dailyRate * days;
    }
};

class Car : public Vehicle 
{
public:
    Car(const string& make, const string& model, double dailyRate)
        : Vehicle(make, model, dailyRate,"Car") {}

    double calculateRentalFee(int days) const override 
    {
        return dailyRate * days;
    }
};

class Motorcycle : public Vehicle 
{
public:
    Motorcycle(const string& make, const string& model, double dailyRate)
        : Vehicle(make, model, dailyRate,"Motorcycle") {}

    double calculateRentalFee(int days) const override 
    {
        return dailyRate * days;
    }
};

class Truck : public Vehicle 
{
public:
    Truck(const string& make, const string& model, double dailyRate)
        : Vehicle(make, model, dailyRate,"Pickup Truck") {}

    double calculateRentalFee(int days) const override 
    {
        return dailyRate * days;
    }
};

int main() 
{
    vector<Vehicle*> vehicles;

    vehicles.push_back(new Car("Toyota", "Corolla", 2000.0));
    vehicles.push_back(new Car("Toyota", "Fortuner", 6000.0));
    vehicles.push_back(new Car("Ford", "Endeavour", 5500.0));
    vehicles.push_back(new Car("Skoda", "Superb", 5000.0));
    vehicles.push_back(new Car("Volkswagon", "Polo", 2500.0));
    vehicles.push_back(new Car("Ferrari", "911 GT3 RS", 20500.0));
    vehicles.push_back(new Motorcycle("Harley Davidson", "Sportster", 3750.0));
    vehicles.push_back(new Motorcycle("Royal Enfield", "Classic 350", 1500.0));
    vehicles.push_back(new Motorcycle("JAWA", "42 Robber", 3150.0));
    vehicles.push_back(new Motorcycle("Yamaha", "R15 V4", 2200.0));
    vehicles.push_back(new Motorcycle("Royal Enfield", "Hunter 350", 1750.0));
    vehicles.push_back(new Truck("Ford", "F 150", 6500.0));
    vehicles.push_back(new Truck("Ford", "F 250", 7000.0));
    vehicles.push_back(new Truck("Ford", "F 350", 7500.0));

    cout << "Available Vehicles:" << endl;
    cout << left << setw(20) << "Choice" << left << setw(20) << "Vehicle Type" << left << setw(20) << "Make: " << left << setw(20) << "Model " << left << setw(20) << "Daily Rate: (in Rs.)" << endl;
    for (int i = 0; i < vehicles.size(); i++) 
    {
        cout << left << setw(20) << i+1 << left << setw(20) << vehicles[i]->getVehicleType() << left << setw(20) << vehicles[i]->getMake() << left << setw(20) << vehicles[i]->getModel() << left << setw(20) << vehicles[i]->getRate() << endl;
    }

    vector<int> quantities(vehicles.size(), 0);
    vector<int> rentalDays(vehicles.size(), 0);
    int vehicleChoice;
    int quantity;
    char continueRenting = 'y';

    while (continueRenting == 'y' || continueRenting == 'Y') 
    {
        cout << endl << "Enter your choice for the vehicle to be rented: ";
        cin >> vehicleChoice;

        if (vehicleChoice >= 1 && vehicleChoice <= vehicles.size()) 
        {
            cout << "Enter the quantity you want to rent: ";
            cin >> quantity;
            quantities[vehicleChoice - 1] += quantity;

            cout << "Enter the number of days for which you want to rent this vehicle: ";
            cin >> rentalDays[vehicleChoice - 1];

            cout << "Do you want to continue renting vehicles (y/n)? ";
            cin >> continueRenting;
        } 
        else 
        {
            cout << "Invalid choice. Please enter a valid vehicle number." << endl;
        }
    }

    double totalRentalFee = 0.0;

    cout << endl << left << setw(20) << "Vehicle Type" <<left<< setw(20) << "Car Manufacturer" <<left<< setw(20) << "Car Model" <<left<< setw(20) << "No of Cars" <<left<< setw(20) <<left<<setw(20) << "No of Days" << "Rate" <<left<< setw(20) << "Rental Fee" << endl;

    for (int i = 0; i < vehicles.size(); ++i) 
    {
        if (quantities[i] > 0) 
        {
            double rentalFee = vehicles[i]->calculateRentalFee(quantities[i] * rentalDays[i]); // Rent for specified days
            cout <<left<< setw(20) << vehicles[i]->getVehicleType() <<left<< setw(20) << vehicles[i]->getMake() <<left<< setw(20) << vehicles[i]->getModel() <<left<< setw(20) << quantities[i] <<left<<setw(20) << rentalDays[i] <<left<< setw(20) << vehicles[i]->getRate() <<left<< setw(20) << endl;
            totalRentalFee += rentalFee;
        }
    }

    cout << setfill('-') << setw(120) << endl;
    cout <<right<< setw(65) << "Total Payable Amount: Rs." <<left<< setw(55) << totalRentalFee << endl;

    for (auto& vehicle : vehicles)
    {
        delete vehicle;
    }
    
    return 0;
}