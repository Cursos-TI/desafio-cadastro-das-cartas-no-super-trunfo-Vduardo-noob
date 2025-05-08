#include <stdio.h>

struct Carta {
    char estado;
    char codigo[4];         // 3 caracteres + terminador nulo
    char nomecidade[100];
    int populacao;
    float area;
    float pib;
    int pontosturisticos;
};

int main(void) {
    struct Carta carta1, carta2;

    // Cadastro da Carta 1
    printf("Informe os dados da Carta 1:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    fflush(stdin);   // Limpa o buffer de entrada

    printf("Código da Carta (ex: A01): ");
    scanf("%3s", carta1.codigo);
    fflush(stdin);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomecidade);
    fflush(stdin);

    printf("População: ");
    scanf("%d", &carta1.populacao);
    fflush(stdin);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    fflush(stdin);

    printf("PIB (em bilhão): ");
    scanf("%f", &carta1.pib);
    fflush(stdin);

    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontosturisticos);
    fflush(stdin);

    // Cadastro da Carta 2
    printf("\nInforme os dados da Carta 2:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    fflush(stdin);

    printf("Código da Carta (ex: A01): ");
    scanf("%3s", carta2.codigo);
    fflush(stdin);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomecidade);
    fflush(stdin);

    printf("População: ");
    scanf("%d", &carta2.populacao);
    fflush(stdin);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    fflush(stdin);

    printf("PIB (em bilhão): ");
    scanf("%f", &carta2.pib);
    fflush(stdin);

    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontosturisticos);
    fflush(stdin);

    // Exibição dos dados cadastrados
    printf("\n===== Dados da Carta 1 =====\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nomecidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhão\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontosturisticos);

    printf("\n===== Dados da Carta 2 =====\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nomecidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhão\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontosturisticos);

    return 0;
}
