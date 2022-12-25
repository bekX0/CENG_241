#include <iostream>
#include <string>


using namespace std;

int main(){
    string sent, key;

    cout << "Enter any string first :: ";
    getline(cin,sent);
    cout << "\nEnter Enter Substring u want to Search :: ";
    cin >> key;
    if(!(sent.find(key) < sent.length()-1)){
        cout << "\nThe substring ["  << key << "] is not present in given sentence";
    }
    else{
        cout << "\nThe substring ["  << key << "] is present in given at position [" << sent.find(key) <<"]" << endl;
    }
    
}