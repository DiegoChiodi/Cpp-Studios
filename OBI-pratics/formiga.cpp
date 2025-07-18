#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int salNum, tub, par;

struct Tub {
    int id1, id2;
};

struct Sal {
    int alt, id;
    vector<Tub> tubs; // List of tubs connected to this sal
};

int nearDown(vector<Sal>& salas, int par) {
    for (const Sal& sal : salas) {
        if (sal.id == par) {
            if (sal.tubs.empty()) return 0; // No tubs, cannot go down
            int id;
            int nearDown = sal.alt;
            for (const Tub& tub : sal.tubs) {
                if (tub.id2 < nearDown) {
                    nearDown = tub.id1; // Find the nearest tub that goes down
                    id = tub.id2; // Store the ID of the tub
                } else if (tub.id1 < nearDown) {
                    nearDown = tub.id1; // Find the nearest tub that goes down
                    id = tub.id1; // Store the ID of the tub
                }
            }
            return 0; // No valid tub found to go down
        }
        
    }
    return 0; // If no matching sal found
}

int main() {
    cin >> salNum >> tub >> par;

    Sal salas[salNum];

    for (int i = 0; i < salNum; i++) {
        cin >> salas[i].alt;
        salas[i].id = i + 1; // Assigning ID starting from 1
    }

    for (int i = 0; i < tub; i++) {
        Tub tub;
        cin >> tub.id1 >> tub.id2;
        salas[i].tubs.push_back(tub);
        cout << "Tub " << i + 1 << ": " << tub.id1 << " " << tub.id2 << endl;
    }

    for (int i = 0; i < salNum; i++) {

    }

    return 0;
}
