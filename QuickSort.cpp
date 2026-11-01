#include <iostream>
using namespace std;

// Organiza os elementos ao redor do pivô e retorna sua posição final.
int particionar(int v[], int inicio, int fim,
                int &comparacoes, int &trocas) {

    int pivo = v[fim]; // Escolhe o último elemento como pivô.
    int i = inicio - 1; // Marca a posição anterior à região dos menores elementos.

    for (int j = inicio; j < fim; j++) { // Percorre os elementos anteriores ao pivô.
        comparacoes++; // Registra a comparação entre o elemento atual e o pivô.

        if (v[j] <= pivo) { // Verifica se o elemento deve ficar na região esquerda.
            i++; // Avança a fronteira da região dos menores elementos.

            if (i != j) { // Verifica se os elementos estão em posições diferentes.
                int temp = v[i]; // Guarda temporariamente o primeiro elemento.
                v[i] = v[j]; // Coloca o elemento atual na região esquerda.
                v[j] = temp; // Coloca o elemento guardado na posição anterior.
                trocas++; // Registra a troca efetiva.
            } 
        } 
    } 

    if (i + 1 != fim) { // Verifica se o pivô precisa mudar de posição.
        int temp = v[i + 1]; // Guarda o elemento da posição final do pivô.
        v[i + 1] = v[fim]; // Coloca o pivô em sua posição definitiva.
        v[fim] = temp; // Coloca o elemento guardado na posição anterior do pivô.
        trocas++; // Registra a troca efetiva com o pivô.
    } 

    return i + 1; // Retorna a posição definitiva do pivô.
} 

// Ordena recursivamente as partes à esquerda e à direita do pivô.
void quickSort(int v[], int inicio, int fim,
               int &comparacoes, int &trocas) {

    if (inicio < fim) { // Verifica se a parte possui pelo menos dois elementos.
        int posicaoPivo = particionar(v, inicio, fim, comparacoes, trocas); // Posiciona o pivô.

        quickSort(v, inicio, posicaoPivo - 1, comparacoes, trocas); // Ordena a parte esquerda.
        quickSort(v, posicaoPivo + 1, fim, comparacoes, trocas); // Ordena a parte direita.
    } 
} 

int main() { // Inicia a função principal do programa.
    int v[] = {5, 3, 8, 1, 2}; // Declara o vetor que será ordenado.
    int n = 5; // Armazena a quantidade de elementos do vetor.
    int comparacoes = 0; // Inicializa o contador de comparações entre valores.
    int trocas = 0; // Inicializa o contador de trocas efetivas.

    quickSort(v, 0, n - 1, comparacoes, trocas); // Ordena o vetor completo.

    cout << "Vetor ordenado: "; // Exibe uma identificação para o resultado.

    for (int i = 0; i < n; i++) { // Percorre o vetor ordenado.
        cout << v[i] << " "; // Exibe cada elemento do vetor.
    } 

    cout << "\nComparacoes: " << comparacoes << endl; // Exibe o total de comparações entre valores.
    cout << "Trocas: " << trocas << endl; // Exibe o total de trocas efetivas.
} 