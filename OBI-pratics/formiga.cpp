#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int salNum, tub, par;

struct Sal {
    int alt, id;
 };

struct Tub {
    Sal sal1, sal2;
};

vector<Sal> possibilities (vector<Sal> &salas, vector<Tub> &tubos, int par) {
    vector<Sal> result;
    Sal parSal = salas[par - 1]; // Ajustando para índice baseado em 0
    
    for (const Tub tub : tubos) {
        if (tub.sal1.id == parSal.id && tub.sal1.alt > tub.sal2.alt)//Checa se a sala 1 é a sala par e
        //  se sua altura é maior que a da sala 2 para poder escorregar
        {
            result.push_back(tub.sal2);
        } else if (tub.sal2.id == parSal.id && tub.sal2.alt > tub.sal1.alt) { //faz a mesma coisa, mas com a sala 2
            result.push_back(tub.sal1);
        }
    }

    return result;
}
int main() {
    
    cin >> salNum >> tub >> par;

    vector<Tub> tubos(tub);
    vector<Sal> salas(salNum);

    for (int i = 0; i < salNum; i++) {
        salas[i].id = i;
        cin >> salas[i].alt;
    }

    for (int i = 0; i < tub; i++) {
        Tub tubModel;
        int id1, id2;
        cin >> id1 >> id2;   // Adjusting for 0-based index
        tubModel.sal1 = salas[id1 - 1];
        tubModel.sal2 = salas[id2 - 1];
        tubos[i] = tubModel;
    }

    std::cout << "Possibilities: " << possibilities(salas, tubos, par).size() << std::endl;

    return 0;
}
