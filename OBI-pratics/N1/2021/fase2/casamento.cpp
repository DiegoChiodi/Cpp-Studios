#include <iostream>
using namespace std;

int main() {
    char A[15], B[15];
    cin >> A >> B;

    // Calcular tamanhos
    int lenA = 0, lenB = 0;     
    while (A[lenA] != '\0') lenA++;
    while (B[lenB] != '\0') lenB++; 

    // Criar vetores alinhados
    int n = (lenA > lenB ? lenA : lenB);
    char AA[15], BB[15];

    for (int i = 0; i < n; i++) {
        AA[i] = (i < n - lenA) ? '0' : A[i - (n - lenA)];
        BB[i] = (i < n - lenB) ? '0' : B[i - (n - lenB)];
    }

    // Resultados
    char RA[15], RB[15];
    int ta = 0, tb = 0;

    // Comparar do menos significativo
    for (int i = n - 1; i >= 0; i--) {
        if (AA[i] > BB[i]) {
            RA[ta++] = AA[i];
        } else if (AA[i] < BB[i]) {
            RB[tb++] = BB[i];
        } else {
            RA[ta++] = AA[i];
            RB[tb++] = BB[i];
        }
    }

    // Inverter resultadosa
    for (int i = 0; i < ta / 2; i++) {
        char tmp = RA[i];
        RA[i] = RA[ta - 1 - i];
        RA[ta - 1 - i] = tmp;
    }
    for (int i = 0; i < tb / 2; i++) {
        char tmp = RB[i];
        RB[i] = RB[tb - 1 - i];
        RB[tb - 1 - i] = tmp;
    }

    // Remover zeros à esquerda
    int ia = 0;
    while (ia + 1 < ta && RA[ia] == '0') ia++;
    int ib = 0;
    while (ib + 1 < tb && RB[ib] == '0') ib++;

    // Impressão em ordem não decrescente
    if (ta == 0 && tb == 0) {
        cout << "-1 -1\n";
    } else if (ta == 0) {
        cout << "-1 ";
        for (int i = ib; i < tb; i++) cout << RB[i];
        cout << "\n";
    } else if (tb == 0) {
        cout << "-1 ";
        for (int i = ia; i < ta; i++) cout << RA[i];
        cout << "\n";
    } else {
        // comparar RA e RB
        int pa = ia, pb = ib;
        bool A_menor = false, B_menor = false;

        while (pa < ta && pb < tb && RA[pa] == RB[pb]) {
            pa++; pb++;
        }
        if (pa == ta) A_menor = true;
        else if (pb == tb) B_menor = true;
        else if (RA[pa] < RB[pb]) A_menor = true;
        else B_menor = true;

        if (A_menor) {
            for (int i = ia; i < ta; i++) cout << RA[i];
            cout << " ";
            for (int i = ib; i < tb; i++) cout << RB[i];
        } else {
            for (int i = ib; i < tb; i++) cout << RB[i];
            cout << " ";
            for (int i = ia; i < ta; i++) cout << RA[i];
        }
        cout << "\n";
    }

    return 0;
}
