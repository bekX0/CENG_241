#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee{
    private:
        string name;
        int employed_years;
        double salary;
        double bonus;

    public:
        void setName(string s){
            name = s;
            
        }

        

        void setSalary(double n){
            salary = n;
            
        }

        

        void setYear(int n){
            employed_years = n;
            
        }
        

        void calculateBonus(){
            bonus = employed_years <=5 ? 0 : (employed_years<=10 && employed_years>5 ? salary * 5/100 : (employed_years<=15 && employed_years>10 ? salary * 10/100 : (employed_years<=20 && employed_years>15 ? salary * 15/100 : salary * 20/100)));  
        }

        void print(){
            cout << name << setw(9) << employed_years << setw(9) << salary << setw(9) << bonus << endl; 
        }
};

int main(){
    string temp;
    double tempd;
    int tempi;
    Employee arr[4];

    for(size_t i {0}; i<4;i++){
        cout << "Enter employee name, employed years and salary: ";
        cin >> temp;
        arr[i].setName(temp);
        cin >> tempi;
        arr[i].setYear(tempi);
        cin >> tempd;
        cin.ignore();
        arr[i].setSalary(tempd);
        cout << endl;
        arr[i].calculateBonus();
    }

    cout << "Name" << setw(9) << "Years" << setw(9) << "Salary" << setw(9) << "Bonus" << endl;
    for (size_t i {0}; i < 4; i++){
        arr[i].print();
    }
    
}