
#include <iostream> 
using namespace std; 

int main() { 

    int v[] = {5, 3, 8, 1, 2}; // Cria o vetor
    int n = 5; // Armazena a quantidade de elementos do vetor.

    int comparacoes = 0; // Conta as comparações
    int trocas = 0; // Conta as trocas

    for (int i = 0; i < n - 1; i++) { // Controla as passagens pelo vetor.

        for (int j = 0; j < n - 1 - i; j++) {
            // Percorre os elementos que ainda precisam ser ordenados.

            comparacoes++; // Registra uma comparação

            if (v[j] > v[j + 1]) {
                // Verifica se o elemento atual é maior que o próximo.

                int temp = v[j]; // Guarda temporariamente o valor atual.
                v[j] = v[j + 1]; // Coloca o próximo valor na posição atual.
                v[j + 1] = temp; // Coloca o valor guardado na posição seguinte.

                trocas++; // Registra a troca
            }
        }
    }

    cout << "Vetor ordenado: "; 

    for (int i = 0; i < n; i++) {
        // Percorre todas as posições do vetor ordenado.

        cout << v[i] << " "; 
    }

    cout << "\nComparacoes: " << comparacoes << endl;
    // Exibe a quantidade total de comparações.

    cout << "Trocas: " << trocas << endl;
    // Exibe a quantidade total de trocas.

}
