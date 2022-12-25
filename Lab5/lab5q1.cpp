#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Course{
    private:
        int mtG;
        int hwG;
        int finG;
        double mtW;
        double hwW; 
        double finW;
        string name;
        string letterGrade;
    public:
        Course() : Course(0.30, 0.20, 0.50){ cout << "Used no args constructor";}
        Course(double mt, double hw, double fin) : mtW{mt}, hwW{hw}, finW{fin} {cout << "Used three args constructor";}
        void set_mtG(int mt){
            this->mtG = mt;
        }
        int get_mtG(){return this->mtG;}
        void set_hwG(int hw){
            this->hwG = hw;
        }
        int get_hwG(){return this->hwG;}
        void set_finG(int fin){
            this->finG = fin;
        }
        int get_finG(){return this->finG;}
        void set_Name(string name){
            this->name=name;
        }
        string getName(){return this->name;}
        string get_letter(){return this->letterGrade;}
        void calculate(){
            double avg { ((this->finG * this->finW) + (this->hwG * this->hwW) + (this->mtG * this->mtW))};
            if(avg>=90){
                this->letterGrade="AA";
            }
            else if(avg >= 85){
                this->letterGrade="BA";
            }
            else if(avg >= 80){
                this->letterGrade="BB";
            }
            else if(avg >= 70){
                this->letterGrade="CB";
            }
            else if(avg >=60){
                this->letterGrade="CC";
            }
            else if(avg >= 50){
                this->letterGrade="DC";
            }
            else if(avg >= 45){
                this->letterGrade="DD";
            }
            else if(avg >= 35){
                this->letterGrade="FD";
            }
            else if(avg >= 0){
                this->letterGrade="FF";
            }
        }
};


int main(){
    float wg1, wg2, wg3;
    string courseName;
    int var1, var2, var3;
    Course cr1;// with no args but uses overloaded with default values.
    cout << "Enter weights for second course: ";
    cin >> wg1;
    cin >> wg2;
    cin >> wg3;
    Course cr2(wg1, wg2, wg3);

    cout << "Enter first course name: ";
    cin >> courseName;
    cr1.set_Name(courseName);
    cout << "Enter first course grades: ";
    cin >> var1;
    cin >> var2;
    cin >> var3;
    cr1.set_mtG(var1);
    cr1.set_hwG(var2);
    cr1.set_finG(var3); 
    
    cout << "Enter first course name: ";
    cin >> courseName;
    cr2.set_Name(courseName);
    cout << "Enter first course grades: ";
    cin >> var1;
    cin >> var2;
    cin >> var3;
    cr2.set_mtG(var1);
    cr2.set_hwG(var2);
    cr2.set_finG(var3);

    cr1.calculate();
    cr2.calculate();

    cout << "Course" << setw(9) << "Midterm" << setw(9) << "Homework" << setw(9) << "Final" << setw(9) << "Letter" << endl;
    cout << cr1.getName() << setw(9) <<cr1.get_mtG() << setw(9) << cr1.get_hwG() << setw(9) << cr1.get_finG() << setw(9) << cr1.get_letter() << endl;
    cout << cr2.getName() << setw(9) <<cr2.get_mtG() << setw(9) << cr2.get_hwG() << setw(9) << cr2.get_finG() << setw(9) << cr2.get_letter() << endl;
}