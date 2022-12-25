#include <iostream>


using namespace std;

int value(int num);

class UpDownNumbers{
    private:
        int start;
        int length;
        int *numbers;
    public:
        UpDownNumbers() : UpDownNumbers(0, 0) {}
        UpDownNumbers(int s, int l) : start{s}, length{l} {
            if(s != 0){
                numbers = new int[length];
                this->generate();
            }
            else{
                numbers = nullptr;
            }
        }
        UpDownNumbers(UpDownNumbers &udn){
            this->start = udn.start;
            this->length = udn.length;
            this->numbers = new int[udn.length];
            for(int i{0}; i<udn.length;i++){
                this->numbers[i] = *(udn.numbers+i);
            }
        } 
        ~UpDownNumbers() {delete [] numbers;}

        void setStart(int s){this->start=s; this->generate();}
        void print(){
            for(int i{0}; i<this->length;i++){
                cout << *(this->numbers+i) << " "; 
            }
            cout << endl;
        }
        void generate(){
            *(this->numbers)=this->start;
            for(int i{1}; i<this->length;i++){
                *(this->numbers+i)= value(*(this->numbers+i-1));
            }
        }
        int getStart(){return this->start;}
        int getLength(){return this->length;}
        
};

//A function to write other element of array
int value(int num){
    if(num%2 == 0){
        return (num/2)+5;
    }
    else{
        return (3*num)-1;
    }
}

int main(){
    int num1, num2;
    cout << "Enter lengtg and start for Obhect A: ";
    cin >> num1;
    cin >> num2;
    UpDownNumbers A(num2, num1);
    UpDownNumbers B(A);
    cout << "Object A (start " << A.getStart() <<", length: " << A.getLength() << ") : ";
    A.print();
    cout << "Object B (a=b): ";
    B.print();

    cout << "Enter new start for Object B: ";
    cin >> num1;
    B.setStart(num1);
    cout << "Object B (start " << B.getStart() <<", length: " << B.getLength() << ") : ";
    cout << "Object A (start " << A.getStart() <<", length: " << A.getLength() << ") : ";
    A.print();
    cout << "Object B (a=b): ";
    B.print();


}
