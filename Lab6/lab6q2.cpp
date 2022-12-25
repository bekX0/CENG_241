#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;


class NumbersClass{
    private:
        int *numbers;
        int length;
        bool isPrime(int num){
            for(int i{2}; i< num/2 ; i++){
                if(num%i==0){
                    return false;
                }
            }
            return true;
        }
    
    public:
        NumbersClass() : NumbersClass(0) {}
        NumbersClass(int l) : length{l} {
            if(l != 0){
                numbers = new int[l];
                this->generate();
            }
            else{
                numbers =nullptr;
            }
        }
        NumbersClass(NumbersClass &nc){
            this->length= nc.length;
            this->numbers = new int[nc.length];
            for(int i{0}; i<nc.length;i++){
                this->numbers[i] = *(nc.numbers+i);
            }
        }
        ~NumbersClass(){delete [] numbers;}

        void setLength(int l) {this->length = l;}

        void generate(){
            srand((unsigned) time(NULL));
            

            for(int i{0}; i<this->length; i++){
                *(this->numbers+i) = rand() % 10000;
            }
        }
        void filter(string s){
            if(s =="prime"){
                for(int i{0} ; i< this->length;i++){
                    if(!this->isPrime(*(this->numbers+i))){
                        *(this->numbers+i) = -1;
                    }
                }
            }
            else if(s == "nonprime"){
                for(int i{0} ; i< this->length;i++){
                    if(this->isPrime(*(this->numbers+i))){
                        *(this->numbers+i) = -1;
                    }
                }
            }
            
        }

        void print(){
            for(int i{0}; i<this->length;i++){
                if(*(this->numbers+i)==-1){
                    continue;
                }
                cout << *(this->numbers+i) << " "; 
            }
            cout << endl;
        }
};

int main(){
    srand((unsigned) time(NULL));
    NumbersClass A(15);
    int temp;
    cout << "Enter length: ";
    cin >> temp;
    A.setLength(temp);
    A.generate();
    NumbersClass B(A);
    B.filter("prime");
    NumbersClass C(A);
    C.filter("nonprime");
    cout << "A: ";
    A.print();
    cout << "B: ";
    B.print();
    cout << "C: ";
    C.print();

}