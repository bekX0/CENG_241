#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Car{
    protected:
        string brandname;
        int modelyear;
        int price;
        int totalCost;
    
    public:
        //No-args Const
        Car() {}
        //Three args Const
        Car(string s, int year, int p) : brandname{s}, modelyear{year}, price{p} {}
        // Copy Constructor
        Car(Car &c){
            this->brandname = c.brandname;
            this->modelyear = c.modelyear;
            this->price = c.price;
            this->totalCost = c.totalCost;
        }

        //Getter-Setter
        string getBrandName() {return this->brandname;}
        void setBrandName(string s) {this->brandname = s;}

        int getModelYear() {return this->modelyear;}
        void setModelYear(int my) {this->modelyear = my;}

        int getPrice() {return this->price;}
        void setPrice(int p) {this->price = p;}

        int getTotalCost() {return this->totalCost;}
        void setTotalCost(int tc) {this->totalCost = tc;}
};

class ElectricCar : public Car{
    protected:
        int NumberOfBatteries;
        int electricCost;

    public:
        //No-args Constuctor
        ElectricCar() {}
        
        //Five args Constructor
        ElectricCar(string s, int year, int p, int nob, int ec){
            this->brandname = s;
            this->modelyear = year;
            this->price = p;
            this->electricCost = ec;
            this->totalCost = ec;
            this->NumberOfBatteries = nob;
            
        }

        //Copy Constructor
        ElectricCar(const ElectricCar &car){
            this->brandname = car.brandname;
            this->modelyear = car.modelyear;
            this->price = car.price;
            this->totalCost = car.totalCost;
            this->NumberOfBatteries = car.NumberOfBatteries;
            this->electricCost = car.electricCost;
        }

        friend ostream& operator<<(ostream &os, const ElectricCar &obj){
            cout << obj.brandname << "price: " << obj.price << " Number Of Batteries: " << obj.NumberOfBatteries << " Electric Cost: " << obj.electricCost << " Total Cost: " << obj.totalCost << endl;
        }

        //Getter-Setter
        int getNumberOfBatteries() {return this->NumberOfBatteries;}
        void setNumberOfBatteries(int nob) {this->NumberOfBatteries = nob;}

        int getElectricCost() {return this->electricCost;}
        void setElectricCost(int ec) {this->electricCost = ec;}
};

class GasolineCar : public Car{
    protected:
        int engineVolume;
        int fuelCost;
    
    public:
        //No-args Const.
        GasolineCar() {}

        //Five args COnst.
        GasolineCar(string s, int year, int p, int ev, int fc){
            this->brandname = s;
            this->modelyear = year;
            this->price = p;
            this->fuelCost = fc;
            this->totalCost = fc;
            this->engineVolume = ev;
            
        }

        //Copy Const.
        GasolineCar(const GasolineCar &car){
            this->brandname = car.brandname;
            this->modelyear = car.modelyear;
            this->price = car.price;
            this->totalCost = car.totalCost;
            this->engineVolume = car.engineVolume;
            this->fuelCost = car.fuelCost;
        }

        //Overloaded operator << 
        friend ostream& operator<<(ostream &os, const GasolineCar &obj){
            cout << obj.brandname << "price: " << obj.price << " Engine Volume: " << obj.engineVolume << " Fuel Cost" << obj.fuelCost << " Total Cost: " << obj.totalCost << endl;
        }

        //Getter-Setter
        int getEngineVolume() {return this->engineVolume;}
        void setEngineVolume(int ev) {this->engineVolume = ev;}

        int getFuelCost() {return this->fuelCost;}
        void setFuelCost(int fc) {this->fuelCost = fc;}
};

class HybridCar : public ElectricCar, public GasolineCar{
    protected:
        string brandname;
        int modelyear;
        int price;
        int totalCost;

    public:
        //No-args Const.
        HybridCar() {}
        
        //Copy Const.
        HybridCar(const HybridCar &car){
            this->brandname = car.brandname;
            this->modelyear = car.modelyear;
            this->price = car.price;
            this->totalCost = car.totalCost;
            this->engineVolume = car.engineVolume;
            this->fuelCost = car.fuelCost;
            this->NumberOfBatteries = car.NumberOfBatteries;
            this->electricCost = car.electricCost;
        }

        HybridCar(ElectricCar &car){
            this->brandname = car.getBrandName();
            this->modelyear = car.getModelYear();
            this->price = car.getPrice();
            this->totalCost = car.getTotalCost();
            this->NumberOfBatteries = car.getNumberOfBatteries();
            this->electricCost = car.getElectricCost();
        }

        friend ostream& operator<<(ostream &os, const HybridCar &obj){
            cout << obj.brandname << "price: " << obj.price << " Number Of Batteries: " << obj.NumberOfBatteries << " Electric Cost: " << obj.electricCost << " Engine Volume: " << " Total Cost: " << obj.totalCost << endl;
        }
    
        //Getter-Setter
        string getBrandName() {return brandname;}
        void setBrandName(string s) {this->brandname = s;}

        int getModelYear() {return this->modelyear;}
        void setModelYear(int my) {this->modelyear = my;}

        int getPrice() {return price;}
        void setPrice(int p) {this->price = p;}

        int getTotalCost() {return this->totalCost;}
        void setTotalCost(int tc) {this->totalCost = tc;}
};

int main(){
    int selection, year, price, nob, ec, ev, fc, min;
    string brand;
    vector <ElectricCar> vElectric;
    vector <GasolineCar> vGasoline;
    vector <HybridCar> vHybrid;

    while(true){
        cout << "1-Electric Car 2-Gasoline Car 3-Hybrid Car 4-Exit :";
        cin >> selection;
        if(selection == 4) {break;}
        switch (selection)
        {
        case 1:
            cout << "Enter brand name: ";
            cin >> brand;

            cout << "Enter model year: ";
            cin >> year;

            cout << "Price: ";
            cin >> price;

            cout << "Number of batteries: ";
            cin >> nob;

            cout << "Electric Cost: ";
            cin >> ec;
            {
                ElectricCar car(brand, year, price, nob, ec);
                vElectric.push_back(car);
            }
            break;

        case 2:
            cout << "Enter brand name: ";
            cin >> brand;

            cout << "Enter model year: ";
            cin >> year;

            cout << "Price: ";
            cin >> price;

            cout << "Encgine Volume(CC): ";
            cin >> ev;

            cout << "Fuel Cost: ";
            cin >> fc;
            {
                GasolineCar car(brand, year, price, ev, fc);
                vGasoline.push_back(car);
            }
            break;

        case 3:
            cout << "Enter brand name: ";
            cin >> brand;

            cout << "Enter model year: ";
            cin >> year;

            cout << "Price: ";
            cin >> price;

            cout << "Number of batteries: ";
            cin >> nob;

            cout << "Electric Cost: ";
            cin >> ec;

            cout << "Encgine Volume(CC): ";
            cin >> ev;

            cout << "Fuel Cost: ";
            cin >> fc;
            {
                ElectricCar ecar(brand, year, price, nob, ec);
                HybridCar hCar(ecar);
                
                hCar.setEngineVolume(ev);
                hCar.setFuelCost(fc);
                hCar.setFuelCost(hCar.getElectricCost() + fc);

                vHybrid.push_back(hCar);
            }
            break;

        
        default:
            break;
        }
        
        
    }
    if(vElectric.at(0).getBrandName() != " "){
        min = vElectric.at(0).getTotalCost();
        brand = vElectric.at(0).getBrandName();
    }
    else if(vHybrid.at(0).getBrandName() != " "){
        min = vHybrid.at(0).getTotalCost();
        brand = vHybrid.at(0).getBrandName();
    }
    else if(vGasoline.at(0).getBrandName() != " "){
        min = vGasoline.at(0).getTotalCost();
        brand = vGasoline.at(0).getBrandName();
    }
    else{
        brand= " ";
    }

        cout << "Electric Cars: " << endl;

        for(int i{0} ; i < vElectric.size() ; i++){
            cout << vElectric.at(i) << endl;
            if(min > vElectric.at(i).getTotalCost()){
                min = vElectric.at(i).getTotalCost();
                brand = vElectric.at(i).getBrandName();
            }
        }


        cout << "Gasoline Cars: " << endl;

        for(int i{0} ; i < vGasoline.size() ; i++){
            cout << vGasoline.at(i) << endl;
            if(min > vGasoline.at(i).getTotalCost()){
                min = vGasoline.at(i).getTotalCost();
                brand = vGasoline.at(i).getBrandName();
            }
        }

        cout << "Hybrid Cars: " << endl;

        for(int i{0} ; i < vHybrid.size() ; i++){
            cout << vHybrid.at(i) << endl;
            if(min > vHybrid.at(i).getTotalCost()){
                min = vHybrid.at(i).getTotalCost();
                brand = vHybrid.at(i).getBrandName();
            }
        }

        cout << brand << " has the minimum cost of all cars.";
}