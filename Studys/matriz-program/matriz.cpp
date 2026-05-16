#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept> // Necessário para exceções padrão

using namespace std;

vector<vector<double>> matrix_main;

bool is_square(const vector<vector<double>> &_matrix)
{
    return (_matrix.size() == _matrix[0].size());
}

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
    if (a[0].size() != b.size())
    {
        cout << "Multiplicação de matrizes impossivel, pois as colunas de A são diferentes das linhas de B";
    }

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

vector<vector<double>> escalonet_matrix(const vector<vector<double>>& _matrix)
{
    return _matrix;
}

vector<vector<double>> chio(const vector<vector<double>>& _matrix)
{
    //Requisitos
    string permit = "Chio só pode ser aplicado";
    if (_matrix[0][0] != 1)
    {
       cout << permit + " se a 1 1 sendo diferente de 1";
       return _matrix;
    }
    if (is_square(_matrix))
    {
        cout << permit + " em matrizes quadradas. número de linhas = número de colunas.";
        return _matrix;
    }
    if (_matrix[0].size() <= 2)
    {
        cout << permit + " em matrizes de ordem maior ou igual a 2";
        return _matrix;
    }
    return _matrix;
}

double calculate_determinante_global(const vector<vector<double>> &_matrix)
{
    return 0;   
}

double calculate_determinante_3x3(const vector<vector<double>> &_m)
{
    double result = (_m[0][0] * _m[1][1] * _m[2][2]
        + _m[0][1] * _m[1][2] * _m[2][0]
        + _m[0][2] * _m[1][0] * _m[2][1])
        - (_m[2][0] * _m[1][1] * _m[0][2]
        + _m[2][1] * _m[1][2] * _m[0][0]
        + _m[2][2] * _m[1][0] * _m[0][1]);
    return result;
}

double calculate_determinante_2x2(const vector<vector<double>> &_m)
{
    double result = (_m[0][0] * _m[1][1]) - (_m[1][0] * _m[0][1]);
    return result;
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
    if (matrix_main.size() != 2 ||  matrix_main[0].size() != 2)
    {
        cout << "O programa só aceita matrizes de ordem 2x2 para rotacionar, aguarde futuras implementações";
        return;
    }
    cout << "Digite o ângulo que deseja rotacionar a matriz: ";

    double graus = 0.0;
    cin >> graus;

    double rad = -graus * M_PI / 180.0;

    vector<vector<double>> matrix_rotation = {
        {cos(rad), -sin(rad)},
        {sin(rad),  cos(rad)}
    };

    print_matrix(mult_matrix(matrix_main, matrix_rotation));

    matrix_main = mult_matrix(matrix_main, matrix_rotation);
}


void run_invert_matrix()
{
    if (matrix_main.size() != matrix_main[0].size()){

        cout << "Uma matrix precisa ser quadrada para ter uma inversa!";
        return;
    }
    if (calculate_determinante_global(matrix_main) == 0) {
        
        cout << "O determinante da matrix não pode ser igual a 0!";
    }

    vector<vector<double>> matrix_res(
        matrix_main.size(),
        vector<double>(matrix_main[0].size())
    );
}

void option() {
    cout << "0 - Tabela de opções" << endl;
    cout << "1 - Substituir matriz atual." << endl;
    cout << "2 - Visualizar matriz atual." << endl;
    cout << "3 - Adição + de matrizes" << endl;
    cout << "4 - Multiplicação * de matrizes." << endl;
    cout << "5 - Transpor matriz atual." << endl;
    cout << "6 - Verificar se a matriz atual é simétrica." << endl;
    cout << "7 - Rotacionar matrix." << endl;
    cout << "8 - Inverter matrix." << endl;    cout << "0 - Tabela de opções" << endl;

    cout << "9 - Calcular determinante" << endl;
    cout << "10 - Aplicar Chio" << endl;
    
    cout << "30 - Sair X." << endl;
}

void manager()
{
    int opcao = 0;
    bool start = false;
    try {
        while (opcao != 12) {
            if (!start) {
                matrix_main = create_matrix();
                start = true;
                option();
            } else {
                cout << "-----------------------------" << endl;
                cout << "0 - Tabela de opções" << endl;
                cout << "Escolha: ";
                cin >> opcao;
                cout << "=============================" << endl;

                switch (opcao) {
                    case 0:
                        option();
                        break;
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
                    case 9:
                        if (matrix_main.size() == 2)
                        {
                            cout << calculate_determinante_2x2(matrix_main) << endl;
                        } else 
                        {
                            cout << calculate_determinante_3x3(matrix_main) << endl;
                        }
                    case 10:
                        break;
                }
            }
        }
    }
    catch (const std::exception& e) {
        // Tratamento da exceção
        cerr << "Erro: " << e.what() << std::endl;
        manager();
    }
}

int main()
{
    manager();
    return 0;
}