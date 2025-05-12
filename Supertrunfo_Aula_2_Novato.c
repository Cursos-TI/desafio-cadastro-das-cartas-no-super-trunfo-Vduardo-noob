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

    // Cálculo dos atributos derivados
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;
    carta1.superPoder = carta1.populacao +
                        carta1.area +
                        (carta1.pib * 1000000000) +
                        carta1.pontosturisticos +
                        carta1.pibPerCapita +
                        (1.0 / carta1.densidade);

    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;
    carta2.superPoder = carta2.populacao +
                        carta2.area +
                        (carta2.pib * 1000000000) +
                        carta2.pontosturisticos +
                        carta2.pibPerCapita +
                        (1.0 / carta2.densidade);

    // --- Escolha do atributo a ser comparado ---
    // Altere o valor abaixo para comparar outro atributo:
    char atributoEscolhido[] = "populacao";
    // valores possíveis: "populacao", "area", "pib", "densidade", "pibpercapita"

    printf("\n===== Comparação de Cartas (Atributo: %s) =====\n", atributoEscolhido);

    // Comparação com if e if-else
    if (strcmp(atributoEscolhido, "populacao") == 0) {
        printf("Carta 1 - %s: %d\n", carta1.nomecidade, carta1.populacao);
        printf("Carta 2 - %s: %d\n", carta2.nomecidade, carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomecidade);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomecidade);
        }
    }

    return 0;
}
