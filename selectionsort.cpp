
#include <iostream> 

using namespace std; 

int main() { 

    int v[] = {5, 3, 8, 1, 2}; // Cria o vetor com os valores iniciais.
    int n = 5; // Guarda a quantidade de elementos do vetor.

    int comparacoes = 0; // Conta as comparações 
    int trocas = 0; // Conta as trocas 

    for (int i = 0; i < n - 1; i++) {
        // Escolhe a posição que receberá o menor elemento encontrado.

        int menor = i; // Considera o elemento atual como o menor inicialmente.

        for (int j = i + 1; j < n; j++) {
            // Percorre os elementos que ainda não estão ordenados.

            comparacoes++; // Registra uma comparação

            if (v[j] < v[menor]) {
                // Verifica se encontrou um valor menor que o candidato atual.

                menor = j; // Guarda o índice do novo menor elemento.
            }
        }

        if (menor != i) {
            // Só realiza a troca se o menor estiver em outra posição.

            int temp = v[i]; // Guarda temporariamente o valor atual.
            v[i] = v[menor]; // Coloca o menor valor na posição correta.
            v[menor] = temp; // Coloca o valor guardado na outra posição.

            trocas++; // Registra a troca efetivamente realizada.
        }
    }

    cout << "Vetor ordenado: "; // Exibe uma mensagem antes do resultado.

    for (int i = 0; i < n; i++) {
        // Percorre todas as posições do vetor.

        cout << v[i] << " "; // Exibe o elemento da posição atual.
    }

    cout << "\nComparacoes: " << comparacoes << endl;
    // Exibe a quantidade total de comparações.

    cout << "Trocas: " << trocas << endl;
    // Exibe a quantidade total de trocas efetivas.
}
