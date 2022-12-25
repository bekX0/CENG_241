#include <iostream>

using namespace std;

int main()
{
    int size1, size2, i, j, temp;
    
    
    cout << "Enter lenght of first array: ";
    cin >> size1;
    int* arr1 = (int*) malloc(size1 * sizeof(int));
    cout<< "Enter numbers: ";
    for(i=0;i<size1;i++){
        cin >> arr1[i];
    }
    
    cout << "Enter lenght of second array: ";
    cin >> size2;
    int* arr2 = (int*) malloc(size2 * sizeof(int));
    cout<< "Enter numbers: ";
    for(i=0;i<size2;i++){
        cin >> arr2[i];
    }
    
    int* arr3 = (int*) malloc(size1+size2 * sizeof(int));
    for(i=0;i<size1;i++){
        arr3[i]= arr1[i];
    }
    for(i=size1, j=0;i<size1+size2;i++){
        arr3[i]= arr2[j++];
    }
    free(arr1);
    free(arr2);
    
    for(i=0;i<size1+size2-1;i++){
        for(j=0; j<size1+size2-1;j++){
            if(arr3[j]>arr3[j+1]){
                swap(arr3[j], arr3[j+1]);
            }
        }
    }
    
    cout << "Merged array: ";
    for (i = 0; i < size1+size2; i++) {
        cout << *(arr3 + i) << " ";
    }
    free(arr3);

    return 0;
}