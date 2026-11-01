#include <iostream> 

using namespace std; 

// Junta duas partes ordenadas do vetor em uma única parte ordenada.
void merge(int v[], int inicio, int meio, int fim,
           int &comparacoes, int &copias) {

    int n1 = meio - inicio + 1; // Calcula a quantidade de elementos da parte esquerda.
    int n2 = fim - meio; // Calcula a quantidade de elementos da parte direita.

    int* esquerda = new int[n1]; // Cria um vetor auxiliar para a parte esquerda.
    int* direita = new int[n2]; // Cria um vetor auxiliar para a parte direita.

    for (int i = 0; i < n1; i++) { // Percorre os elementos da parte esquerda.
        esquerda[i] = v[inicio + i]; // Copia um elemento para o vetor auxiliar esquerdo.
        copias++; // Registra a cópia realizada.
    } 

    for (int j = 0; j < n2; j++) { // Percorre os elementos da parte direita.
        direita[j] = v[meio + 1 + j]; // Copia um elemento para o vetor auxiliar direito.
        copias++; // Registra a cópia realizada.
    } 

    int i = 0; // Define a posição inicial da parte esquerda.
    int j = 0; // Define a posição inicial da parte direita.
    int k = inicio; // Define a posição inicial de escrita no vetor original.

    while (i < n1 && j < n2) { // Continua enquanto as duas partes tiverem elementos.
        comparacoes++; // Registra uma comparação entre valores.

        if (esquerda[i] <= direita[j]) { // Verifica qual dos dois valores é menor ou igual.
            v[k] = esquerda[i]; // Copia o menor valor da parte esquerda para o vetor original.
            i++; // Avança na parte esquerda.
        } else { // Executa quando o valor da direita é menor.
            v[k] = direita[j]; // Copia o menor valor da parte direita para o vetor original.
            j++; // Avança na parte direita.
        } 

        copias++; // Registra a escrita de um elemento no vetor original.
        k++; // Avança para a próxima posição do vetor original.
    } 

    while (i < n1) { // Verifica se ainda restam elementos na parte esquerda.
        v[k] = esquerda[i]; // Copia o elemento restante para o vetor original.
        copias++; // Registra a cópia realizada.
        i++; // Avança na parte esquerda.
        k++; // Avança no vetor original.
    } 

    while (j < n2) { // Verifica se ainda restam elementos na parte direita.
        v[k] = direita[j]; // Copia o elemento restante para o vetor original.
        copias++; // Registra a cópia realizada.
        j++; // Avança na parte direita.
        k++; // Avança no vetor original.
    } 

    delete[] esquerda; // Libera a memória utilizada pelo vetor auxiliar esquerdo.
    delete[] direita; // Libera a memória utilizada pelo vetor auxiliar direito.
} 

// Divide o vetor em partes menores até que cada parte tenha um elemento.
void mergeSort(int v[], int inicio, int fim,
               int &comparacoes, int &copias) {

    if (inicio < fim) { // Verifica se a parte do vetor possui pelo menos dois elementos.
        int meio = inicio + (fim - inicio) / 2; // Calcula o ponto médio do intervalo.

        mergeSort(v, inicio, meio, comparacoes, copias); // Ordena a metade esquerda.
        mergeSort(v, meio + 1, fim, comparacoes, copias); // Ordena a metade direita.

        merge(v, inicio, meio, fim, comparacoes, copias); // Junta as duas metades ordenadas.
    } 
} 

int main() {
    int v[] = {5, 3, 8, 1, 2}; // Declara o vetor que será ordenado.
    int n = 5; // Armazena a quantidade de elementos do vetor.
    int comparacoes = 0; // Inicializa o contador de comparações entre valores.
    int copias = 0; // Inicializa o contador de cópias de elementos.

    mergeSort(v, 0, n - 1, comparacoes, copias); // Ordena o vetor completo.

    cout << "Vetor ordenado: "; // Exibe uma identificação para o resultado.

    for (int i = 0; i < n; i++) { // Percorre o vetor ordenado.
        cout << v[i] << " "; // Exibe cada elemento do vetor.
    } 

    cout << "\nComparacoes: " << comparacoes << endl; // Exibe o total de comparações entre valores.
    cout << "Copias: " << copias << endl; // Exibe o total de cópias de elementos.

} 