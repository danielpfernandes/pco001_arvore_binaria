//
// Created by Daniel Paiva Fernandes on 19/10/2021.
//
/**
 * Criação de uma nova
 * Busca se o item está ou não presente, qual o pai e quais os filhos do mesmo
 * Inserção
 * Remoção
 * Impressão da árvore
 **/


#ifndef PCO001_ARVORE_BINARIA_MAIN_H
#define PCO001_ARVORE_BINARIA_MAIN_H
#include "list"
using namespace std;

struct Node {
    int dado{};
    struct Node* esquerdo, * direito;

    // Cria árvore pelo construtor
    explicit Node(int valor)
    {
        dado = valor;
        esquerdo = nullptr;
        direito = nullptr;
    }
    Node()
    {
        esquerdo = nullptr;
        direito = nullptr;
    }
    void insereNode(int valor) {
        if (this->dado == valor) {
            cout << "Valor duplicado. Tente com outro valor" << endl;
            return;
        }

        if (valor < this->dado) {
            if(this->esquerdo == nullptr) { this->esquerdo = new Node(valor); }
            else { this->esquerdo->insereNode(valor); }
        } else {
            if(this->direito == nullptr) { this->direito = new Node(valor); }
            else { this->direito->insereNode(valor); }
        }
    }

    void removeNode(int valor) {
        if(this->dado == valor) {
            Node* aux = new Node();
            cout << "Valor a ser removido encontrado" << endl;
            imprimeNode(this);
            if (this->esquerdo != nullptr) {
                aux = this->esquerdo;
                if (this->direito != nullptr) {
                    aux->direito = this->direito;
                }
                this->dado = aux->dado;
                this->esquerdo = aux->esquerdo;
                this->direito = aux->direito;
                free(aux);
            } else if (this->direito != nullptr) {
                aux = this->direito;
                this->dado = aux->dado;
                this->esquerdo = aux->esquerdo;
                this->direito = aux->direito;
                free(aux);
            }
            return;
        }
        if (this->dado > valor) {
            if (this->esquerdo == nullptr) { cout << "Valor não encontrado" << endl; return; }
            this->esquerdo->removeNode(valor);
        }
        else if (this->dado < valor) {
            if (this->direito == nullptr) { cout << "Valor não encontrado" << endl; return; }
            this->direito->removeNode(valor);
        }
        else {
            cout << "Valor não encontrado" << endl;
        }
    }

    void imprimeArvore() const {
        cout << "Nó: " << std::to_string(this->dado) << endl;
        if (this->esquerdo != nullptr) cout << "Nó esquerdo: " << std::to_string(this->esquerdo->dado) << endl;
        else cout << "Nó esquerdo: NULL"<< endl;
        if (this->direito != nullptr)cout << "Nó direito: " << std::to_string(this->direito->dado) << endl;
        else cout << "Nó direito: NULL"<< endl;
        cout << endl;
        if (this->esquerdo != nullptr) { this->esquerdo->imprimeArvore();}
        if (this->direito != nullptr) { this->direito->imprimeArvore(); }
    }

    void imprimeNode(Node* node)
    {
        cout << "Nó: " << std::to_string(node->dado) << endl;
        if (node->esquerdo != nullptr) cout << "Nó esquerdo: " << std::to_string(node->esquerdo->dado) << endl;
        else cout << "Nó esquerdo: NULL"<< endl;
        if (node->direito != nullptr)cout << "Nó direito: " << std::to_string(node->direito->dado) << endl;
        else cout << "Nó direito: NULL"<< endl;
        cout << endl;
    }

    void buscaValor(int valor)
    {
        if(this->dado == valor) {
            cout << "Valor encontrado" << endl;
            imprimeNode(this);
            return;
        }
        if (this->dado > valor) {
            if (this->esquerdo == nullptr) { cout << "Valor não encontrado" << endl; return; }
            this->esquerdo->buscaValor(valor);
        }
        else if (this->dado < valor) {
            if (this->direito == nullptr) { cout << "Valor não encontrado" << endl; return; }
            this->direito->buscaValor(valor);
        }
        else {
            cout << "Valor não encontrado" << endl;
        }
    }

    static void printBT(const string& prefix, const Node* node, bool isLeft)
    {
        if( node != nullptr )
        {
            cout << prefix;

            cout << (isLeft ? "├──" : "└──" );

            // Valor do node
            cout << node->dado << std::endl;

            // Próximo nível da árvore - troncos da esquerda e da direita
            printBT( prefix + (isLeft ? "│   " : "    "), node->esquerdo, true);
            printBT( prefix + (isLeft ? "│   " : "    "), node->direito, false);
        }
    }

    void printBT(const Node* node)
    {
        cout << "Legenda: ├── esquerdo     └── direito ou raiz" <<endl;
        printBT("", node, false);
    }

};

#endif //PCO001_ARVORE_BINARIA_MAIN_H


