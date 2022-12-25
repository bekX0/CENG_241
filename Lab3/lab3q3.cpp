#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct NUMBERLIST{
    int arr[10];
    string choice;
};

void funtion_pointer(struct NUMBERLIST *p);
void funtion_ref(NUMBERLIST &p);

int main(){
    struct NUMBERLIST op1, op2;
    int total {0};

    cout << "Enter 10 integers and order of summation: ";
    for(size_t i{0}; i<10;i++){
        cin >> op1.arr[i];
    }
    cin >> op1.choice;
    funtion_pointer(&op1);

    cout << "Result: ";
    for(size_t i{0}; i<10;i++){
        cout << op1.arr[i] << " ";
    }
    cout << endl;



    cout << "Enter 10 integers and order of summation: ";
    for(size_t i{0}; i<10;i++){
        cin >> op2.arr[i];
    }
    cin >> op2.choice;
    funtion_ref(op2);

    cout << "Result: ";
    for(size_t i{0}; i<10;i++){
        cout << op2.arr[i] << " ";
    }
    cout << endl;


    return 0;
}

void funtion_pointer(NUMBERLIST *p){
    if((*p).choice=="left-to-right"){
        for(int i {1}; i<10; i++){
            (*p).arr[i]+=(*p).arr[i-1];
        }
    }
    else if((*p).choice=="right-to-left"){
        for(int i {8}; 0<=i; i--){
            (*p).arr[i]+=(*p).arr[i+1];
        }
    }
    return;
}

void funtion_ref(NUMBERLIST &p){
    if((p).choice=="left-to-right"){
        for(int i {1}; i<10; i++){
            (p).arr[i]+=(p).arr[i-1];
        }
    }
    else if((p).choice=="right-to-left"){
        for(int i {8}; 0<=i; i--){
            (p).arr[i]+=(p).arr[i+1];
        }
    }
    return;
}