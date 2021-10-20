//
// Created by danie on 19/10/2021.
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
    int dado;
    struct Node* esquerdo, * direito;

    // Cria nova árvore pelo construtor
    Node(int valor)
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

    void imprimeArvore() {
        /*string spaces = "";
        Node* aux = this->esquerdo;
        while(aux != nullptr)
        {
            spaces += " ";
            aux = aux->esquerdo;
        }
        aux = this->direito;
        while(aux != nullptr)
        {
            spaces += " ";
            aux = aux->direito;
        }
        if (this != nullptr) cout << spaces << std::to_string(this->dado);
        if (this->esquerdo || this ->direito) { cout << endl; }
        if (this->esquerdo != nullptr) { this->esquerdo->imprimeArvore(); cout << " "; }
        if (this->direito != nullptr) { cout << " "; this->direito->imprimeArvore(); }*/
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

    int max_depth(Node* n)
    {
        if (!n) return 0;
        return 1 + std::max(max_depth(n->esquerdo), max_depth(n->direito));
    }

    void prt()
    {
        struct node_depth
        {
            Node* n;
            int lvl;
            node_depth(Node* n_, int lvl_) : n(n_), lvl(lvl_) {}
        };

        int depth = max_depth(this);

        char buf[1024];
        int last_lvl = 0;
        int offset = (1 << depth) - 1;

        // using a queue means we perform a breadth first iteration through the tree
        list<node_depth> q;

        q.push_back(node_depth(this, last_lvl));
        while (q.size())
        {
            const node_depth& nd = *q.begin();

            // moving to a new level in the tree, output a new line and calculate new offset
            if (last_lvl != nd.lvl)
            {
                std::cout << "\n";

                last_lvl = nd.lvl;
                offset = (1 << (depth - nd.lvl)) - 1;
            }

            // output <offset><data><offset>
            if (nd.n)
                sprintf(buf, " %*s%d%*s", offset, " ", nd.n->dado, offset, " ");
            else
                sprintf(buf, " %*s", offset << 1, " ");
            std::cout << buf;

            if (nd.n)
            {
                q.push_back(node_depth(nd.n->esquerdo, last_lvl + 1));
                q.push_back(node_depth(nd.n->direito, last_lvl + 1));
            }

            q.pop_front();
        }
        std::cout << "\n";
    }

};

#endif //PCO001_ARVORE_BINARIA_MAIN_H


