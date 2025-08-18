#include <iostream>

int main (int argc, char* argv[])
{
    std::cout << "digite o tamanho do vetor: " << std::endl;
    int vetorSize;
    std::cin >> vetorSize;

    int vetor[vetorSize];
    
    for (int i = 0; i < vetorSize; i++)
    {
        std::cout << "digite o valor do vetor[" << i << "]: ";
        std::cin >> vetor[i];
    }

    for (int i = 0; i < vetorSize; i++)
    {
        bool trade = false;
        for (int j = 0; j < vetorSize - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int tempMaior = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = tempMaior;
                trade = true;
            }
        }

        if (!trade)
        {
            break;
        }
    }
    
    std::cout << "Os valores do vetor sao:" << std::endl;

    for (int i =0; i < vetorSize; i++)
    {
        std::cout << vetor[i] << " ";
    }

    return 0;
}