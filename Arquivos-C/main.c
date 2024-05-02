#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int main() {
    int numProdutosTotal, numProdutosInseridos = 0;
    printf("Informe a quantidade de produtos a serem cadastrados: ");
    scanf("%d", &numProdutosTotal);
    
    Produto *estoque = (Produto *)malloc(numProdutosTotal * sizeof(Produto));
    
    if (estoque == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }
    
    int escolha;
    do {
        printf("\n====== Menu ======\n");
        printf("1) Inserir Produto\n");
        printf("2) Apresentar Produto\n");
        printf("3) Apresentar Todos os Produtos\n");
        printf("4) Balanco\n");
        printf("5) Busca por Nome\n");
        printf("6) Busca por Setor\n");
        printf("7) Venda\n");
        printf("8) Carregar Produtos de Arquivo\n");
        printf("9) Salvar Produtos em Arquivo\n");
        printf("0) Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (numProdutosInseridos < numProdutosTotal) {
                    inserirProduto(&estoque[numProdutosInseridos], &numProdutosInseridos);
                } else {
                    printf("Limite de produtos atingido.\n");
                }
                break;
            case 2: {
                char nomeBusca[50];
                printf("Digite o nome do produto: ");
                getchar();
                fgets(nomeBusca, sizeof(nomeBusca), stdin);
                nomeBusca[strlen(nomeBusca) - 1] = '\0';
                buscaPorNome(estoque, numProdutosInseridos, nomeBusca);
                break;
            }
            case 3:
                apresentarTodosProdutos(estoque, numProdutosInseridos);
                break;
            case 4:
                printf("Balanco total: R$ %.2f\n", calcularBalanco(estoque, numProdutosInseridos));
                break;
            case 5: {
                char nomeBusca[50];
                printf("Digite o nome do produto: ");
                getchar();
                fgets(nomeBusca, sizeof(nomeBusca), stdin);
                nomeBusca[strlen(nomeBusca) - 1] = '\0';
                buscaPorNome(estoque, numProdutosInseridos, nomeBusca);
                break;
            }
            case 6: {
                int setor;
                printf("Digite o setor (0 - Mercearia, 1 - Hortifruti, 2 - Carnes, 3 - Laticinios, 4 - Bebidas, 5 - Limpeza, 6 - Graos): ");
                scanf("%d", &setor);
                buscaPorSetor(estoque, numProdutosInseridos, setor);
                break;
            }
            case 7:
                realizarVenda(estoque, numProdutosInseridos);
                break;
            case 8:
                carregarProdutosArquivo(&estoque, &numProdutosInseridos);
                break;
            case 9:
                salvarProdutosArquivo(estoque, numProdutosInseridos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 0);

    free(estoque);

    return 0;
}
