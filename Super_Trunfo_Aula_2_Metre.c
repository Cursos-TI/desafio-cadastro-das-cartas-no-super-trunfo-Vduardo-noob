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
};

// Função para exibir o menu de atributos
void exibirMenu(int ignorar) {
    printf("\nEscolha um atributo para comparação:\n");
    if (ignorar != 1) printf("1 - População\n");
    if (ignorar != 2) printf("2 - Área\n");
    if (ignorar != 3) printf("3 - PIB\n");
    if (ignorar != 4) printf("4 - Pontos Turísticos\n");
    if (ignorar != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
}

// Função para obter valor do atributo
float obterValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosturisticos;
        case 5: return c.densidade;
        default: return 0;
    }
}

int main() {
    struct Carta carta1, carta2;

    // Entrada da Carta 1
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
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontosturisticos);

    // Entrada da Carta 2
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
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontosturisticos);

    // Cálculo da densidade
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    // Escolha dos atributos
    int atributo1 = 0, atributo2 = 0;

    while (atributo1 < 1 || atributo1 > 5) {
        exibirMenu(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5) printf("Opção inválida!\n");
    }

    while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        exibirMenu(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 == atributo1) {
            printf("Você já escolheu esse atributo! Escolha outro.\n");
        } else if (atributo2 < 1 || atributo2 > 5) {
            printf("Opção inválida!\n");
        }
    }

    // Comparação dos atributos
    float valor1_attr1 = obterValor(carta1, atributo1);
    float valor2_attr1 = obterValor(carta2, atributo1);
    float valor1_attr2 = obterValor(carta1, atributo2);
    float valor2_attr2 = obterValor(carta2, atributo2);

    int pontos_carta1 = 0;
    int pontos_carta2 = 0;

    // Comparar primeiro atributo
    if (atributo1 == 5) {
        if (valor1_attr1 < valor2_attr1) pontos_carta1++;
        else if (valor2_attr1 < valor1_attr1) pontos_carta2++;
    } else {
        if (valor1_attr1 > valor2_attr1) pontos_carta1++;
        else if (valor2_attr1 > valor1_attr1) pontos_carta2++;
    }

    // Comparar segundo atributo
    if (atributo2 == 5) {
        if (valor1_attr2 < valor2_attr2) pontos_carta1++;
        else if (valor2_attr2 < valor1_attr2) pontos_carta2++;
    } else {
        if (valor1_attr2 > valor2_attr2) pontos_carta1++;
        else if (valor2_attr2 > valor1_attr2) pontos_carta2++;
    }

    // Soma dos valores
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    // Exibir resultado
    printf("\n===== Resultado da Rodada =====\n");
    printf("Carta 1 - %s\n", carta1.nomecidade);
    printf("Carta 2 - %s\n\n", carta2.nomecidade);

    printf("Atributo 1: ");
    switch (atributo1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("  %s: %.2f\n", carta1.nomecidade, valor1_attr1);
    printf("  %s: %.2f\n\n", carta2.nomecidade, valor2_attr1);

    printf("Atributo 2: ");
    switch (atributo2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("  %s: %.2f\n", carta1.nomecidade, valor1_attr2);
    printf("  %s: %.2f\n\n", carta2.nomecidade, valor2_attr2);

    printf("Soma dos atributos:\n");
    printf("  %s: %.2f\n", carta1.nomecidade, soma1);
    printf("  %s: %.2f\n", carta2.nomecidade, soma2);

    // Resultado final
    if (soma1 > soma2) {
        printf("\nResultado: %s venceu!\n", carta1.nomecidade);
    } else if (soma2 > soma1) {
        printf("\nResultado: %s venceu!\n", carta2.nomecidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
