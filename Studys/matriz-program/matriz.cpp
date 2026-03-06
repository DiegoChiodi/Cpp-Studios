#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;

void create_matrix()
{
    cout << "Digite o número de linhas e depois o de colunas: ";

    int lines, columns;
    cin >> lines >> columns;
    matrix.clear();
    matrix.resize(lines, vector<int>(columns));
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Digite um valor para o elemento localizado em i = " << i << " x j = " << j << '.';
            cin >> matrix[i][j];
        }
    }
}

void print_matriz()
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

void manager()
{
    int opcao = -1;
    while(opcao != 9)
    {
        if (matrix.empty())
        {
            create_matrix();
        } else {
            print_matriz();
            break;
        }
    }
}

int main(void)
{
    manager();
    return 0;
}