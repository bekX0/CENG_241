#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Contact
{
private:
    string name;
    string number;
    

public:
    Contact() : Contact("Unknown", "0") {}
    Contact(string name, string num) : name{name}, number{num} {}
    void print(string opt)
    {
        if(opt=="light"){
            cout << this->getName() << setw(10) << this->getNumber()<< endl;
        }
        else{
            cout << "Name: " << this->getName()<< endl;
            cout << "Number: " << this->getNumber() << endl;
        }
    }
    void setName(string name) { this->name = name; }
    void setNumber(string number) { this->number =number; }
    string getName() { return this->name; }
    string getNumber() { return this->number; }
};

class AdressBook
{
    private:
        int nrofcontacts;
        Contact contacts[10];
        int search(string name){
            for (size_t i{0}; i < this->nrofcontacts; i++){
                if(this->contacts[i].getName() == name){
                    return i;
                }
            }
            return -1;
        }
    public:
        AdressBook(){this->nrofcontacts=0;}
        int getCount(){return this->nrofcontacts;}
        bool add(Contact c){
            if(this->search(c.getName()) != -1){
                return false;
            }
            this->nrofcontacts++;
            this->contacts[nrofcontacts-1] = c;
            return true;
        }

        bool remove(string s){
            if(this->search(s) == -1){
                return false;
            }
            for(int i{this->search(s)}; i<this->nrofcontacts-1; i++){
                this->contacts[i] = this->contacts[i+1];
            }
            this->nrofcontacts--;
            return true;
        }
        void print(){
            string opt;
            if(this->nrofcontacts <1){
                cout << "No contacts available" << endl;
            }
            else{
                cout << "Enter your printing option (light/headers)";
                cin >> opt;
                if(opt == "light"){
                    cout << "Name" << setw(10) << "Number" << endl;
                }
                for(int i{0} ; i< this->nrofcontacts;i++){
                    contacts->print(opt);
                }
            }
        }
        
};


int main(){
    int opt{0};
    string temp;
    AdressBook book;
    Contact tmpc;


    do{
        cout << endl;
        cout << "1. Display Adress Book" << endl << "2. Add New Contact" << endl << "3. Remove Contact" << endl << "4. Exit" << endl;
        cout << "Enter your choise: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            book.print();
            break;
        
        case 2:
            cout <<"Enter name: ";
            cin >> temp;
            tmpc.setName(temp);
            cout <<"Enter number: ";
            cin >> temp;
            tmpc.setNumber(temp);
            if(book.add(tmpc)){
                cout << "Contact added." << endl;
            }
            else{
                cout << "Contact already exists." << endl;
            }
            break;
        
        case 3:
            cout << "Enter name: ";
            cin >> temp;
            if(book.remove(temp)){
                cout << "Contact removed." << endl;
            }
            else{
                cout << "Contact is not available."<< endl;
            }
            break;
        
        case 4:
            break;
        default:
            break;
        }
    }while(opt!=4);
    cout << "Bye!" << endl;
    return 0;
}