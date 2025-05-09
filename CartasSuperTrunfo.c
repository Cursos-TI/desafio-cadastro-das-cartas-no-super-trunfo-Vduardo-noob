#include <stdio.h>

struct Carta {
    char estado;
    char codigo[4];         // 3 caracteres + terminador nulo
    char nomecidade[100];
    int populacao;
    float area;
    float pib;
    int pontosturisticos;

    // Atributos calculados
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

    // --- Cálculos para carta1 ---
    carta1.densidade = carta1.populacao / carta1.area; 
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao; 
    carta1.superPoder = carta1.populacao +
                        carta1.area +
                        (carta1.pib * 1000000000) +
                        carta1.pontosturisticos +
                        carta1.pibPerCapita +
                        (1.0 / carta1.densidade); 

    // --- Cálculos para carta2 ---
    carta2.densidade = carta2.populacao / carta2.area; 
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao; 
    carta2.superPoder = carta2.populacao +
                        carta2.area +
                        (carta2.pib * 1000000000) +
                        carta2.pontosturisticos +
                        carta2.pibPerCapita +
                        (1.0 / carta2.densidade);

    // Exibição dos dados da carta 1
    printf("\n===== Dados da Carta 1 =====\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nomecidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhão\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontosturisticos);
    printf("Densidade populacional: %.2f habitantes/km²\n", carta1.densidade);
    printf("PIB per capita: R$ %.2f\n", carta1.pibPerCapita);                  
    printf("Super Poder: %.2f\n", carta1.superPoder);                          

    // Exibição dos dados da carta 2
    printf("\n===== Dados da Carta 2 =====\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nomecidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhão\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontosturisticos);
    printf("Densidade populacional: %.2f habitantes/km²\n", carta2.densidade); 
    printf("PIB per capita: R$ %.2f\n", carta2.pibPerCapita);                  
    printf("Super Poder: %.2f\n", carta2.superPoder);                          

    // Comparações
    printf("\n===== Comparação de Cartas =====\n");
    printf("População: Carta 1 venceu (%d)\n", carta1.populacao > carta2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", carta1.area > carta2.area);
    printf("PIB: Carta 1 venceu (%d)\n", carta1.pib > carta2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", carta1.pontosturisticos > carta2.pontosturisticos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", carta1.densidade < carta2.densidade); // Menor vence
    printf("PIB per capita: Carta 1 venceu (%d)\n", carta1.pibPerCapita > carta2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", carta1.superPoder > carta2.superPoder);

    return 0;
}
