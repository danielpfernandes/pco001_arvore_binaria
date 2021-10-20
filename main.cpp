#include <iostream>
#include "main.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    // Criação de uma nova
    Node *arvore = new Node(3);

    // Inserção
    arvore->insereNode(2);
    arvore->insereNode(5);
    arvore->insereNode(4);
    arvore->insereNode(6);
    arvore->insereNode(15);

    // Impressão da árvore
    arvore->imprimeArvore();
    arvore->printBT(arvore);

    //Busca se o item está ou não presente, qual o pai e quais os filhos do mesmo
    arvore->buscaValor(5);

    // Remoção
    arvore->removeNode(5);
    arvore->printBT(arvore);

    return 0;
}
