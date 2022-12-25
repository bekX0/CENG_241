#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    char opt;
    string filename, info, temp;
    fstream File;

    cout << "Enter file name: ";
    cin >> filename;
    cin.ignore();
    filename = filename +".txt";
    File.open(filename, ios::out);
    cout << "Enter information to store.."<< endl;
    getline(cin,info);
    

    do{
        cout << "Want to enter more ? (y/n)..";
        cin >> opt;
        cin.ignore();
        if(opt =='n'){
            break;
        }
        
        getline(cin,temp);
        
        info=info+ "\n" +temp;
    }while(opt=='y');

    
    
    File << info;
    File.close();
    cout << endl << "The information succcessfully stored in the file..!!" << endl;
    cout << endl << "Want to see ? (y/n)..";
    cin >> opt;

    if(opt == 'y'){
        File.open(filename, ios::in);
        cout <<"This file contains: " << endl;
        cout << File.rdbuf();
    }
    File.close();
}