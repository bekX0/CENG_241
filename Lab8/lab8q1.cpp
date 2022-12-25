#include <iostream>

using namespace std;

class Calculator{
    private:
        float *numbers;
        int length;
    
    public:
        Calculator() : numbers{nullptr}, length{0} {}
        Calculator(int n) : length{n} {numbers = new float[n];}
        ~Calculator() {
            delete [] numbers;
        } 

        void setNumbers(float* array){
            for(int i{0} ; i < this->length; i++){
                this->numbers[i] = array[i];
            }
        }

        //Sum of two arrays
        Calculator operator+(const Calculator &obj){
            int minsize, i;
            if(this->length < obj.length){
                minsize = this->length;
                
            }
            else{
                minsize = obj.length;
                
            }
            Calculator temp(minsize);
            for(i = 0; i < minsize; i++ ){
                *(temp.numbers+i) = *(this->numbers+i) + *(obj.numbers+i);
            }
            
            return temp;
        }

        //Subtraction of two arrays
        Calculator operator-(const Calculator &obj){
            int size;
            if(this->length < obj.length){
                size = this->length;
            }
            else{
                size = obj.length;
            }
            Calculator temp(size);
            for(int i{0}; i < this->length; i++ ){
                *(temp.numbers+i) = *(this->numbers+i) - *(obj.numbers+i);
            }
            
            return temp;
        }

        //Multiply of two arrays
        Calculator operator*(const Calculator &obj){
            int size;
            if(this->length < obj.length){
                size = this->length;
            }
            else{
                size = obj.length;
            }
            Calculator temp(size);
            for(int i{0}; i < this->length; i++ ){
                *(temp.numbers+i) = *(this->numbers+i) * *(obj.numbers+i);
            }
            
            return temp;
        }

        //Division of two arrays
        Calculator operator/(const Calculator &obj){
            int size;
            if(this->length < obj.length){
                size = this->length;
            }
            else{
                size = obj.length;
            }
            Calculator temp(size);
            for(int i{0}; i < this->length; i++ ){
                *(temp.numbers+i) = *(this->numbers+i) / *(obj.numbers+i);
            }
            
            return temp;
        }

        Calculator& operator=(const Calculator &obj){
            delete [] this->numbers;
            this->length = obj.length;
            this->numbers = new float[obj.length];
            for(int i {0} ; i< obj.length; i++){
                *(this->numbers+i) = *(obj.numbers+i);
            }
        }

        friend ostream& operator<<(ostream &os, const Calculator &obj){
            for(int i{0}; i < obj.length; i++){
                cout << *(obj.numbers+i) << " ";
            }
        }


};

int main(){
    int n;
    string selection;

    cout << "Lenght of the first number set: "; 
    cin >> n;
    Calculator cal1(n);
    float *numbers1 = new float[n];
    for(int i{0} ; i < n; i++){
        cin >> *(numbers1+i);
    }
    cal1.setNumbers(numbers1);
    delete [] numbers1;
    

    cout << "Lenght of the second number set: "; 
    cin >> n;
    Calculator cal2(n);
    float *numbers2 = new float[n];
    for(int i{0} ; i < n; i++){
        cin >> *(numbers2+i);
    }
    cal2.setNumbers(numbers2);
    delete [] numbers2;
    

    while(true){
        cout << endl;
        cout << "Choose operation: ";
        cin >> selection;

        if(selection == "+"){
            cout << cal1 + cal2;
            continue;
        }
        else if(selection == "-"){
            cout << cal1 - cal2;
            continue;
        }
        else if(selection == "*"){
            cout << cal1 * cal2;
            continue;
        }
        else if(selection == "/"){
            cout << cal1 / cal2;
            continue;
        }
        else if(selection == "exit"){
            break;
        }
    }
    return 0;
}