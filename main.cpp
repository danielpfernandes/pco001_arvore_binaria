#include <iostream>
#include "main.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Node *arvore = new Node(3);
    arvore->insereNode(2);
    arvore->insereNode(5);
    arvore->insereNode(4);
    arvore->insereNode(6);
    arvore->insereNode(15);
    arvore->imprimeArvore();
    arvore->prt();

    arvore->buscaValor(5);
    arvore->removeNode(5);
    arvore->prt();

    return 0;
}
