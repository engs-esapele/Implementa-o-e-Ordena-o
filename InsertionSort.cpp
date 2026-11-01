#include <iostream> 
using namespace std; 

int main() { 
    int v[] = {5, 3, 8, 1, 2}; // Declara o vetor que será ordenado.
    int n = 5; // Armazena a quantidade de elementos do vetor.
    int comparacoes = 0; // Contabiliza as comparações entre valores.
    int deslocamentos = 0; // Contabiliza os deslocamentos de elementos.

    for (int i = 1; i < n; i++) { // Percorre o vetor a partir do segundo elemento.
        int chave = v[i]; // Guarda o elemento que será inserido na posição correta.
        int j = i - 1; // Define a posição anterior à chave.

        while (j >= 0 && v[j] > chave) { // Verifica se há elementos anteriores maiores que a chave.
            comparacoes++; // Registra a comparação entre os valores do vetor.
            v[j + 1] = v[j]; // Desloca o elemento maior uma posição para a direita.
            deslocamentos++; // Registra o deslocamento realizado.
            j--; // Retrocede uma posição para continuar procurando.
        } 

        if (j >= 0) { // Verifica se existe um elemento anterior para comparar com a chave.
            comparacoes++; // Registra a comparação final que não exigiu deslocamento.
        } 

        v[j + 1] = chave; // Insere a chave na posição correta.
    } 

    cout << "Vetor ordenado: "; // Exibe uma identificação para o resultado.

    for (int i = 0; i < n; i++) { // Percorre o vetor ordenado.
        cout << v[i] << " "; // Exibe cada elemento do vetor.
    } 

    cout << "\nComparacoes: " << comparacoes << endl; // Exibe o total de comparações entre valores.
    cout << "Deslocamentos: " << deslocamentos << endl; // Exibe o total de deslocamentos.


} 