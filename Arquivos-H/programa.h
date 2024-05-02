#ifndef PRODUTO_H
#define PRODUTO_H

typedef enum {
    MERCEARIA,
    HORTIFRUTI,
    CARNES,
    LATICINIOS,
    BEBIDAS,
    LIMPEZA,
    GRAOS
} Setor;

typedef struct {
    char nome[50];
    Setor setor;
    int quantidade;
    float preco;
} Produto;

void inserirProduto(Produto *estoque, int *numProdutosInseridos);
void apresentarProduto(Produto produto);
void apresentarTodosProdutos(Produto *estoque, int numProdutos);
float calcularBalanco(Produto *estoque, int numProdutos);
void buscaPorNome(Produto *estoque, int numProdutos, char *nome);
void buscaPorSetor(Produto *estoque, int numProdutos, Setor setor);
void realizarVenda(Produto *estoque, int numProdutos);
void carregarProdutosArquivo(Produto **estoque, int *numProdutos);
void salvarProdutosArquivo(Produto *estoque, int numProdutos);

#endif /* PRODUTO_H */
