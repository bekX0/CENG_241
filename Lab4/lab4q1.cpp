#include <iostream>
#include <string>


using namespace std;

class Calculator{
    public:
        int operand1;
        int operand2;
        string oprtr;
        double result;
        void run(){
            if(oprtr == "add"){ // Ex: add num1 to num2 => num1 + num2
                result= operand1 + operand2;
            }
            else if(oprtr == "subtract"){
                result = operand2 - operand1; // Ex: subtract num1 from num2 => num2 - num1
            }
            else if(oprtr == "divide"){//Ex: divide num1 to num2 => num1 / num2
                if(operand2 == 0){
                    cout << "You can not divide any number to 0 !";
                    return;
                } 
                result = (1.0 * operand1) / operand2;
            }
            else if(oprtr == "multiply"){ // Ex: multiply num1 with num2 => num1 * num2
                result = operand1 * operand2 * 1.0;
            }
            cout << "Result is: " << result;
        }
};




int main(){
    string temp;
    Calculator calc;
    
    cout << "Enter  your  operation: ";
    cin >> calc.oprtr;
    cin >> calc.operand1;
    cin >> temp;
    cin >> calc.operand2;

    calc.run();

    return 0;
}