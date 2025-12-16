#include <iostream>
#include <vector>

std::vector<int> bubbleSort(std::vector<int>& vetor)
{
    for (int i = 0; i < vetor.size(); i++)
    {
        bool trade = false;
        for (int j = 0; j < vetor.size() - 1; j++)
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
    return vetor;
}

std::vector<int> insertSort(std::vector<int>& vetor)
{
    for (int i = 1; i < vetor.size(); i ++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (vetor[j + 1] < vetor[j])
            {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            } else {
                break;
            }
        }
    }
    return vetor;
}

std::vector<int> selectionSort(std::vector<int>& vetor)
{
    for (int i = 0; i < vetor.size(); i++)
    {
        int menor = i;
        for (int j = i; j < vetor.size(); j++)
        {
            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }
        int temp = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = temp;   
    }
    
    return vetor;
}

int main (int argc, char* argv[])
{   
    int escolha = 0;

    while (true)
    { 
        std::cout << "Escolha a função para ordenar:" << std::endl;
        std::cout << "1 - bubbleSort" << std::endl;
        std::cout << "2 - insertSort" << std::endl;
        std::cout << "3 - selectionSort" << std::endl;
        std::cout << "4 - Exit" << std::endl;

        std::cin >> escolha;
        
        if (escolha == 4)
        {
            break;
        }
        
        std::cout << "digite o tamanho do vetor: " << std::endl;
        int vetorSize;
        std::cin >> vetorSize;

        std::vector<int> vetor(vetorSize);
        for (int i = 0; i < vetor.size(); i++)
        {
            std::cout << "digite o valor do vetor[" << i << "]: ";
            std::cin >> vetor[i];
        }

        switch(escolha){
            case (1):
                vetor = bubbleSort(vetor);
                break;
            case 2:
                vetor = insertSort(vetor);
                break;
            case 3:
                vetor = selectionSort(vetor);
                break;
        }

        std::cout << "Os valores do vetor sao:" << std::endl;

        for (int i =0; i < vetor.size(); i++)
        {
            std::cout << vetor[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}