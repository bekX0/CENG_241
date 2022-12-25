#include <iostream>
#include <iomanip>

using namespace std;
struct car{
    string carName;
    int total_km;
    int last_km;
};


int main()
{
    car arr1[5];
    string value;
    int i;
    
    for(i=0;i<5;i++){
        cout << "Enter car name: ";
        cin >> arr1[i].carName;
        
        cout << "Enter total distance: ";
        cin >> arr1[i].total_km;
        
        cout << "Enter last km: ";
        cin >> arr1[i].last_km;
    }
    
    cout << "Car" << setw(17) << "Total km" << setw(17) << "Last km" << setw(25) << "Needs Maintainance" << endl;
    
    for(i=0;i<5;i++){
        if(arr1[i].total_km-arr1[i].last_km > 10000){
            value = "YES";
        }
        else{
            value= "NO";
        }
        cout << arr1[i].carName << setw(17) << arr1[i].total_km << setw(17) << arr1[i].last_km << setw(25) << value << endl;
    }
    return 0;
}