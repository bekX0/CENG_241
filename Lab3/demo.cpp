#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct course {
    string code;
    double grade;
};

int main(){

    char choice;
    int j {0};
    double sum {0};
    vector <course> cor ;
    cor.push_back(course());

    do{
        cout<<"Enter course code and grade: "<<endl;

        cin>>cor[j].code;
        cin>>cor[j].grade;

        j++;

        cor.push_back(course());

        cout<<"Add new course:";
        cin>>choice;

        cin.ignore();

    }while(choice=='y');

    cout<<"List of entered "<<(j)<<" courses:"<<endl;

    for(int k=0;k<j;k++){

        cout<<"- "<<cor[k].code<<",Grade:"<<cor[k].grade<<endl;
        sum+=cor[k].grade;
    }
    cout<<"CGPA: "<<(sum/(j))<<endl;

}