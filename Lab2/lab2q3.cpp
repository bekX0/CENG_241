#include <iostream>
#include <string>


using namespace std;

int main(){
    string sent;
    char Vowels[]={'a', 'e', 'i', 'o', 'u' }, Digits[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }, Consonants[]= {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'y', 'z'};
    int vowel {0}, consonant {0}, digit {0}, space {0};

    cout << "Enter a line of string: ";
    getline(cin,sent);


    for(size_t i=0;i<sent.length();i++){
        for(size_t k=0;k<5;k++){
            if(sent[i]==Vowels[k]){
                vowel++;
                break;
            }
        }
    }
    for(size_t i=0;i<sent.length();i++){
        for(size_t k=0;k<10;k++){
            if(sent[i]==Digits[k]){
                digit++;
                break;
            }
        }
    }

    for(size_t i=0;i<sent.length();i++){
        for(size_t k=0;k<21;k++){
            if(sent[i]==Consonants[k]){
                consonant++;
                break;
            }
        }
    }

    for(size_t i=0;i<sent.size();i++){
        for(size_t k=0;k<21;k++){
            if(sent[i]==' '){
                space++;
                break;
            }
        }
    }
    
    cout << "Vowels: " << vowel << endl;
    cout << "Consonants: " << consonant << endl;
    cout << "Digits: " << digit << endl;
    cout << "White Spaces: " << space << endl;
    
    
}