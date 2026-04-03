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
            cout << "Digite um valor para o elemento localizado em i = " << i + 1 << " x j = " << j + 1 << '.' << endl;
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
    cout << "Matriz:" << endl;
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
    cout << "Operação realizada com sucesso" << endl;
}

void mult_matrix()
{
    //O n de colunas da primeira tem que ser igual ao n de l da segunda
    int lines_r =  matrix_main.size();
    int columns_r;
    cout << "Digite o número de colunas da matrix que vai multiplicar: " << endl;
    std::cin >> columns_r;
    vector<vector<int>> matrix_mult = fill_matrix(matrix_main[0].size(), columns_r);
    vector<vector<int>> matrix_res(lines_r, vector<int>(columns_r, 0));
    
    for (int i = 0; i < lines_r; i++)
    {
        for (int j = 0; j < columns_r; j++)
        {
            for (int k = 0; k < lines_r; k++)
            {
                matrix_res[i][j] += matrix_main[i][k] * matrix_mult[k][j];
            }
        }
    }
    matrix_main = matrix_res;
    cout << "Operação realizada com sucesso" << endl;
}


void manager()
{
    int opcao = -1;
    bool start = false;
    while(opcao != 9)
    {
        if (!start)
        {
            matrix_main = create_matrix();
            start = true;
        } else {
            cout << "Escolha uma opção:" << endl;
            cout << "1 - Substituir matriz atual." << endl;
            cout << "2 - Visualizar matriz atual." << endl;
            cout << "3 - Adição + de matrizes" << endl;
            cout << "4 - Multiplicação * de matrizes." << endl;
            cout << "5 - Transpor matriz atual." << endl;
            cout << "6 - Verificar se a matriz atual é simétrica." << endl;
            cout << "7 - Sair X." << endl;

            cin >> opcao;   
            switch(opcao)
            {
                case 1:
                    matrix_main = create_matrix();
                    break;
                case 2:
                    print_matriz(matrix_main);
                    break;
                case 3:
                    addition_matrix();
                    break;
                case 4:
                    mult_matrix();
                    break;
            }
        }
    }
}



int main(void)
{
    manager();
    return 0;
}