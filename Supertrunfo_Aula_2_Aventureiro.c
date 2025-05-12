#include <stdio.h>
#include <string.h>

struct Carta {
    char estado;
    char codigo[4];
    char nomecidade[100];
    int populacao;
    float area;
    float pib;
    int pontosturisticos;

    float densidade;
    float pibPerCapita;
    float superPoder;
};

int main() {
    struct Carta carta1, carta2;

    // Cadastro da Carta 1
    printf("Informe os dados da Carta 1:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%3s", carta1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomecidade);

    printf("População: ");
    scanf("%d", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhão): ");
    scanf("%f", &carta1.pib);

    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontosturisticos);

    // Cadastro da Carta 2
    printf("\nInforme os dados da Carta 2:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%3s", carta2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomecidade);

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhão): ");
    scanf("%f", &carta2.pib);

    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontosturisticos);

    // Cálculos automáticos
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1e9) / carta1.populacao;

    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1e9) / carta2.populacao;

    int opcao;
    printf("\n===== MENU DE COMPARAÇÃO =====\n");
    printf("Escolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);

    printf("\n===== Comparação de Cartas =====\n");
    printf("Carta 1 - %s\n", carta1.nomecidade);
    printf("Carta 2 - %s\n\n", carta2.nomecidade);

    switch(opcao) {
        case 1:
            printf("Comparando População:\n");
            printf("%s: %d habitantes\n", carta1.nomecidade, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nomecidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.nomecidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.nomecidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("Comparando Área:\n");
            printf("%s: %.2f km²\n", carta1.nomecidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomecidade, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.nomecidade);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.nomecidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("Comparando PIB:\n");
            printf("%s: R$ %.2f bilhões\n", carta1.nomecidade, carta1.pib);
            printf("%s: R$ %.2f bilhões\n", carta2.nomecidade, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.nomecidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.nomecidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("Comparando Pontos Turísticos:\n");
            printf("%s: %d pontos\n", carta1.nomecidade, carta1.pontosturisticos);
            printf("%s: %d pontos\n", carta2.nomecidade, carta2.pontosturisticos);
            if (carta1.pontosturisticos > carta2.pontosturisticos) {
                printf("Resultado: %s venceu!\n", carta1.nomecidade);
            } else if (carta2.pontosturisticos > carta1.pontosturisticos) {
                printf("Resultado: %s venceu!\n", carta2.nomecidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("Comparando Densidade Demográfica:\n");
            printf("%s: %.2f hab/km²\n", carta1.nomecidade, carta1.densidade);
            printf("%s: %.2f hab/km²\n", carta2.nomecidade, carta2.densidade);
            if (carta1.densidade < carta2.densidade) {
                printf("Resultado: %s venceu!\n", carta1.nomecidade);
            } else if (carta2.densidade < carta1.densidade) {
                printf("Resultado: %s venceu!\n", carta2.nomecidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    return 0;
}
