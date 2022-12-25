#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class Villager{
    protected:
        int health;
        int attackPower;
    
    public:
        Villager() : Villager (20,0) {}
        Villager(int h, int ap) : health{h}, attackPower{ap} {}

        int attack(Villager &V){return 0;}
        int getHealth() {return this->health;}
        void setHealth(int h) {this->health = h;}
        void isDead(string s){
            if(this->health<0){
                cout << s << " is died!"<< endl;
            }
        }
};

class Archer : public Villager{
    private:
        int nrOfArrows;
    
    public:
        Archer() : Archer(60, 40, 5) {}
        Archer(int h, int ap, int nroarr)  {
            health = h;
            attackPower = ap;
            nrOfArrows = nroarr;
        }

        int attack(Villager &V){
            if(V.getHealth() < 0){
                return -1;
            }
            else if(this->nrOfArrows == 0){
                return -2;
            }
            srand((unsigned) time(NULL));
            int damage = rand() % this->attackPower;
            V.setHealth(V.getHealth() - rand() % damage);
            this->nrOfArrows--;
            return damage;
        }

        int attack(Archer &A){
            if(A.getHealth() < 0){
                return -1;
            }
            else if(this->nrOfArrows == 0){
                return -2;
            }
            srand((unsigned) time(NULL));
            int damage = rand() % this->attackPower;
            A.setHealth(A.getHealth() - damage);
            this->nrOfArrows--;
            return damage;
        }


};



int main(){
    Archer archers[5];
    Villager villagers[6], attacker;
    int ctr {1};
    string selection, command, fixed_command[5];
    do{
        cout << "Enter command #" << ctr++ <<" ";
        getline(cin, command);

        for(int i {0}; i<5;i++){// this loops gets command line and return in an array like ["villager", "2", "attack", "archer", "3"]
            fixed_command[i] = command.substr(0, (command.find(" ")));
            command = command.substr(command.find(" ")+1, command.length()- command.find(" "));
        }
        if(fixed_command[0] == "") {continue;}
        if(fixed_command[0] == fixed_command[3] && fixed_command[1] == fixed_command[4]) {
            
            cout << "Game Over !" << endl;
            break;
        }
        if(fixed_command[0] == "Villager"){
            if(fixed_command[3] == "Archer"){
                if(villagers[stoi(fixed_command[1])-1].attack(archers[stoi(fixed_command[4])-1]) == 0){
                    cout << "Villager " << fixed_command[1] << " can't attack!" << endl;
                }
            }
            else if(fixed_command[3] == "Villager"){
                if(villagers[stoi(fixed_command[1])-1].attack(villagers[stoi(fixed_command[4])-1]) == 0){
                    cout << "Villager " << fixed_command[1] << " can't attack!" << endl;
                }
            }
            
        }
        else if(fixed_command[0] == "Archer"){
            if(fixed_command[3] == "Villager"){
                int temp = archers[stoi(fixed_command[1])-1].attack(villagers[stoi(fixed_command[4])-1]);
                if(temp == -1){
                    cout << "Villager already dead... R.I.P." << endl;
                }
                else if(temp == -2){
                    cout << "Archer is out of arrows!" << endl;
                }
                else{
                    cout << "Archer made " << temp << " damage to Villager " << fixed_command[4] << endl;
                    villagers[stoi(fixed_command[4])-1].isDead("Villager " + fixed_command[4]);
                }
            }
            else if(fixed_command[3] == "Archer"){
                int temp = archers[stoi(fixed_command[1])-1].attack(archers[stoi(fixed_command[4])-1]);
                if(temp == -1){
                    cout << "Archer already dead... R.I.P." << endl;
                }
                else if(temp == -2){
                    cout << "Archer is out of arrows!" << endl;
                }
                else{
                    cout << "Archer made " << temp << " damage to Archer " << fixed_command[4] << endl;
                    archers[stoi(fixed_command[4])-1].isDead("Archer " + fixed_command[4]);
                }
            }
            
        }
        else{
            cout << "Enter a valid command!" << endl;
            continue;
        }
    }while(true);

    
    
}