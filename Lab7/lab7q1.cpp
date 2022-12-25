#include <iostream>
#include <string>

using namespace std;
//!deneme
//? deneme
// deneme
class CoffeeMachine{
    protected:
        int coffeAmount;
    public:
        CoffeeMachine() : CoffeeMachine(0) {};
        CoffeeMachine(int n) : coffeAmount{n} {};
        void addCoffee(int n) {this->coffeAmount += n;}
        
};

class LatteMachine : public CoffeeMachine{
    private:
        int milkAmount;
    
    public:
        LatteMachine() : LatteMachine(0) {};
        LatteMachine(int m) : milkAmount{m} {};
        
        void addMilk(int m) {this->milkAmount += m;}
        int makeLatte(int n){
            if(n<=this->milkAmount && n<=this->coffeAmount){
                return 0;
            }
            else if(n>this->coffeAmount){
                return -1;
            }
            else if(n>this->milkAmount){
                return -2;
            }
        }
};

class FilterCoffeeMachine : public CoffeeMachine{
    public:
        int makeFilterCoffee(int n){
            if(n<=this->coffeAmount){
                return 0;
            }
            else if(n>coffeAmount){
                return -1;
            }
        }
};


int main(){
    string selection;
    int cups, add;
    FilterCoffeeMachine FM;
    LatteMachine LM;

    while(true){
        cout << "Filter or latte? ";
        cin >> selection;
        if(selection == "none") {
            break;
        }
        else if(selection == "latte"){
            cout << "How many cups of latte do you want? ";
            cin >> cups;
            if(LM.makeLatte(cups) == 0){
                cout << "Enjoy!";
                continue;
            }
            else if(LM.makeLatte(cups) == -1){
                while(LM.makeLatte(cups) == -1){
                    cout << "Not enough coffee!" << " Add: ";
                    cin >> add;
                    LM.addCoffee(add);
                }
                cout << "Enjoy!" << endl;
            }
            else if(LM.makeLatte(cups) == -2){
                while(LM.makeLatte(cups) == -2){
                    cout << "Not enough milk!" << " Add: ";
                    cin >> add;
                    LM.addMilk(add);
                }
            }
        }
        else if(selection == "filter"){
            cout << "How many cups of coffee do you want? ";
            cin >> cups;
            if(FM.makeFilterCoffee(cups) == 0){
                cout << "Enjoy!";
                continue;
            }
            else if(FM.makeFilterCoffee(cups) == -1){
                while(FM.makeFilterCoffee(cups) == -1){
                    cout << "Not enough coffee!" << " Add: ";
                    cin >> add;
                    FM.addCoffee(add);
                }
                cout << "Enjoy!" << endl;
            }
        }
        else{
            cout << "Enter a valid type!" << endl;
        }
    }
    cout << "Goodbye!" << endl;
    
    return 0;
}