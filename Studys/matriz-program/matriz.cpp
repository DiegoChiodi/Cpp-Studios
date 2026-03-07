#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix_main;

vector<vector<int>> fill_matrix(int lines, int columns)
{
    vector<vector<int>> matrix(lines,vector<int>(columns));
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Digite um valor para o elemento localizado em i = " << i << " x j = " << j << '.' << endl;
            cin >> matrix[i][j];
        }
    }
    return matrix;
}


vector<vector<int>> create_matrix()
{
    cout << "Digite o número de linhas e depois o de colunas da matriz: ";

    int lines, columns;
    cin >> lines >> columns;

    vector<vector<int>> matrix_result = fill_matrix(lines, columns);
    return matrix_result;
}



void print_matriz(vector<vector<int>> _matrix)
{
    for (int i = 0; i < _matrix.size(); i++)
    {
        for (int j = 0; j < _matrix[i].size(); j++)
        {
            cout << _matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

void addition_matrix()
{
    vector<vector<int>> matrix = fill_matrix(matrix_main.size(), matrix_main[0].size());
    for (int i = 0; i < matrix_main.size(); i++)
    {
        for (int j = 0; j < matrix_main[i].size(); j++)
        {
            matrix_main[i][j] += matrix[i][j];
        }
    }
}


void manager()
{
    int opcao = -1;
    while(opcao != 9)
    {
        if (matrix_main.empty())
        {
            matrix_main = create_matrix();
        } else {
            cout << "Escolha uma opcao:" << endl;
            cout << "1 - Substituir matriz atual." << endl;
            cout << "2 - Visualizar matriz atual." << endl;
            cout << "3 - Adicao + de matrizes" << endl;
            cout << "4 - Multiplicacao * de matrizes." << endl;
            cout << "5 - Transpor matriz atual." << endl;
            cout << "6 - Verificar se a matriz atual e simetrica." << endl;
            cout << "7 - Sair X." << endl;

            cin >> opcao;   

            switch(opcao)
            {
                case 1:
                    matrix_main = create_matrix();
                case 2:
                    print_matriz(matrix_main);
                case 3:
                    addition_matrix();
            }
        }
    }
}



int main(void)
{
    manager();
    return 0;
}