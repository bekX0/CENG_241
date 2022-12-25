#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct COURSE{
    string code;
    float grade;
};

int main(){
    vector <struct COURSE> vctr1;
    
    char opt {'y'};
    int ctr {0};
    string temps;
    float tempf, total {0};

    do{
        vctr1.push_back(COURSE());
        cout << "Enter course code and grade: ";
        cin >> vctr1[ctr].code;
        cin >> vctr1[ctr++].grade;
        

        cout << "Add new course? ";
        cin >> opt;
    }while(opt=='y');

    cout << "List of " << vctr1.size() << "courses" << endl;

    for(size_t i {0}; i < vctr1.size();i++){
        cout << "-" << vctr1[i].code << vctr1[i].grade << endl;
    }

    
    for(size_t i {0}; i < vctr1.size();i++){
        total += vctr1[i].grade;
    }

    cout << "CGPA: " << total/vctr1.size() << endl;



    return 0;
}