#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<double>> matrix_main;

vector<vector<double>> fill_matrix(int lines, int columns)
{
    vector<vector<double>> matrix(lines, vector<double>(columns));

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Digite um valor para o elemento localizado em i = "
                 << i + 1 << " x j = " << j + 1 << '.' << endl;

            cin >> matrix[i][j];
        }
    }

    return matrix;
}

vector<vector<double>> create_matrix()
{
    cout << "Digite o número de linhas e depois o de colunas da matriz: ";

    int lines, columns;
    cin >> lines >> columns;

    vector<vector<double>> matrix_result = fill_matrix(lines, columns);
    return matrix_result;
}

void print_matrix(const vector<vector<double>>& _matrix)
{
    cout << "Matriz:" << endl;

    for (int i = 0; i < _matrix.size(); i++) {
        for (int j = 0; j < _matrix[i].size(); j++) {
            if (abs(_matrix[i][j]) < 0.01) {
                cout << 0.0 << "   ";
            } else {
                cout << _matrix[i][j] << "   ";
            }
        }
        cout << endl;
    }
}

void run_add_matrix()
{
    vector<vector<double>> matrix =
        fill_matrix(matrix_main.size(), matrix_main[0].size());

    for (int i = 0; i < matrix_main.size(); i++) {
        for (int j = 0; j < matrix_main[i].size(); j++) {
            matrix_main[i][j] += matrix[i][j];
        }
    }

    cout << "Operação realizada com sucesso" << endl;
}

vector<vector<double>> mult_matrix(const vector<vector<double>>& a,
                                   const vector<vector<double>>& b)
{
    const int lines_r = a.size();
    const int columns_r = b[0].size();

    vector<vector<double>> matrix_res(
        lines_r, vector<double>(columns_r, 0)
    );

    for (int i = 0; i < lines_r; i++) {
        for (int j = 0; j < columns_r; j++) {
            for (int k = 0; k < a[0].size(); k++) {
                matrix_res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return matrix_res;
}

void run_mult_matrix() // O(n * n * n)
{
    const int lines_r = matrix_main.size();

    int columns_r;
    cout << "Digite o número de colunas da matrix que vai multiplicar: " << endl;
    cin >> columns_r;

    vector<vector<double>> matrix_mult =
        fill_matrix(matrix_main[0].size(), columns_r);

    matrix_main = mult_matrix(matrix_main, matrix_mult);

    cout << "Operação realizada com sucesso" << endl;
}

vector<vector<double>> get_transp(const vector<vector<double>>& matrix_target)
{
    vector<vector<double>> matrix_res(
        matrix_target[0].size(),
        vector<double>(matrix_target.size())
    );

    for (int i = 0; i < matrix_target.size(); i++) {
        for (int j = 0; j < matrix_target[0].size(); j++) {
            matrix_res[j][i] = matrix_target[i][j];
        }
    }

    return matrix_res;
}

void run_tranp_matrix()
{
    matrix_main = get_transp(matrix_main);
    cout << "Operação realizada com sucesso!" << endl;
}

void run_matrix_is_simet()
{
    vector<vector<double>> matrix_transp = get_transp(matrix_main);

    if (matrix_transp == matrix_main) {
        cout << "A matrix é simétrica!" << endl;
    } else if (matrix_main.size() != matrix_main[0].size()) {
        cout << "A matrix não é simétrica! Detalhe: toda matrix simétrica é quadrada" << endl;
    } else {
        cout << "A matrix não é simétrica!" << endl;
    }
}

void run_rotated_matrix() // debug 1 2 1 0 7 90 2
{
    cout << "Digite o ângulo que deseja rotacionar a matriz: ";

    double graus = 0.0;
    cin >> graus;

    double rad = -graus * 3.141592653589793 / 180.0;

    vector<vector<double>> matrix_rotation = {
        {cos(rad), -sin(rad)},
        {sin(rad),  cos(rad)}
    };

    print_matrix(mult_matrix(matrix_main, matrix_rotation));

    matrix_main = mult_matrix(matrix_main, matrix_rotation);
}

double calculate_determinante(const vector<vector<double>>& _matrix)
{
    return 0;
}
void run_invert_matrix()
{
    if (matrix_main.size() != matrix_main[0].size()){

        cout << "Uma matrix precisa ser quadrada para ter uma inversa!";
        return;
    }
    if (calculate_determinante(matrix_main) == 0) {
        
        cout << "O determinante da matrix não pode ser igual a 0!";
    }

}

void manager()
{
    int opcao = -1;
    bool start = false;

    while (opcao != 9) {
        if (!start) {
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
            cout << "7 - Rotacionar matrix." << endl;
            cout << "8 - Inverter matrix." << endl;
            cout << "9 - Sair X." << endl;

            cin >> opcao;

            switch (opcao) {
                case 1:
                    matrix_main = create_matrix();
                    break;
                case 2:
                    print_matrix(matrix_main);
                    break;
                case 3:
                    run_add_matrix();
                    break;
                case 4:
                    run_mult_matrix();
                    break;
                case 5:
                    run_tranp_matrix();
                    break;
                case 6:
                    run_matrix_is_simet();
                    break;
                case 7:
                    run_rotated_matrix();
                    break;
                case 8:
                    run_invert_matrix();
            }
        }
    }
}

int main()
{
    manager();
    return 0;
}