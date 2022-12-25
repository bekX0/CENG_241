#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct COURSE{
    string code;
    float grade;
};

int main(){
    int ctr;
    string result {""};

    cout << "How many numbers letters are you going to enter? ";
    cin >> ctr;
    char* arr1 = new char(ctr);
    int* arr2 = new int(ctr);
    
    for(size_t i {0}; i<ctr;i++){
        cout << "Enter letter and how many times it will be repeated: ";
        cin >> *(arr1+i);
        cin >> *(arr2+i);
    }

    for(size_t i {0}; i<ctr;i++){
        for(size_t j {0} ; j<*(arr2+i); j++){
            result += *(arr1+i);
        }
    }
    cout << result << endl;
    delete [] arr1;
    delete [] arr2;


    return 0;
}