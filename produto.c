#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserirProduto(Produto *estoque, int *numProdutosInseridos) {
    printf("Nome do produto: ");
    getchar();
    fgets(estoque->nome, sizeof(estoque->nome), stdin);
    estoque->nome[strlen(estoque->nome) - 1] = '\0';
    printf("Setor (0 - Mercearia, 1 - Hortifruti, 2 - Carnes, 3 - Laticinios, 4 - Bebidas, 5 - Limpeza, 6 - Graos): ");
    scanf("%d", &(estoque->setor));
    printf("Quantidade: ");
    scanf("%d", &(estoque->quantidade));
    printf("Preco: ");
    scanf("%f", &(estoque->preco));

    (*numProdutosInseridos)++;
}

void apresentarProduto(Produto produto) {
    printf("Nome: %s\n", produto.nome);
    printf("Setor: %d\n", produto.setor);
    printf("Quantidade: %d\n", produto.quantidade);
    printf("Preco: R$ %.2f\n", produto.preco);
}

void apresentarTodosProdutos(Produto *estoque, int numProdutos) {
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        apresentarProduto(estoque[i]);
    }
}

float calcularBalanco(Produto *estoque, int numProdutos) {
    float balanco = 0.0;
    for (int i = 0; i < numProdutos; i++) {
        balanco += estoque[i].preco * estoque[i].quantidade;
    }
    return balanco;
}

void buscaPorNome(Produto *estoque, int numProdutos, char *nome) {
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
            printf("Produto encontrado:\n");
            apresentarProduto(estoque[i]);
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void buscaPorSetor(Produto *estoque, int numProdutos, Setor setor) {
    printf("Produtos no setor %d:\n", setor);
    for (int i = 0; i < numProdutos; i++) {
        if (estoque[i].setor == setor) {
            apresentarProduto(estoque[i]);
        }
    }
}

void realizarVenda(Produto *estoque, int numProdutos) {
    char nome[50];
    int quantidade;
    printf("Nome do produto: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';
    printf("Quantidade a ser vendida: ");
    scanf("%d", &quantidade);

    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
            if (estoque[i].quantidade >= quantidade) {
                estoque[i].quantidade -= quantidade;
                printf("Venda realizada com sucesso.\n");
            } else {
                printf("Quantidade insuficiente em estoque.\n");
            }
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void carregarProdutosArquivo(Produto **estoque, int *numProdutos) {
    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int i = 0;
    while (fscanf(arquivo, "Produto: %[^\n]\nSetor: %d\nQuantidade: %d\nPreco: %f\n\n", (*estoque)[i].nome, &((*estoque)[i].setor), &((*estoque)[i].quantidade), &((*estoque)[i].preco)) != EOF) {
        i++;
    }

    *numProdutos = i;

    fclose(arquivo);

    printf("Produtos carregados com sucesso.\n");
}

void salvarProdutosArquivo(Produto *estoque, int numProdutos) {
    FILE *arquivo = fopen("produtos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < numProdutos; i++) {
        fprintf(arquivo, "Produto: %s\nSetor: %d\nQuantidade: %d\nPreco: %.2f\n\n", estoque[i].nome, estoque[i].setor, estoque[i].quantidade, estoque[i].preco);
    }

    fclose(arquivo);

    printf("Produtos salvos com sucesso.\n");
}
