#include <stdio.h>
#include <string.h>

// Funções de comparação
float escolherValor(int opcao, unsigned long int pop, float area, float pib, int pontos, float densidade, float perCapita) {
    switch (opcao) {
        case 1: return pop;
        case 2: return area;
        case 3: return pib;
        case 4: return pontos;
        case 5: return densidade;
        case 6: return perCapita;
        default: return 0;
    }
}

// Nome do atributo
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        case 6: return "PIB per Capita";
        default: return "Inválido";
    }
}

void adicionarCartas() {
    // Variáveis das cartas
    char estado[3], cod[100], cidade[100];
    unsigned long int populacao;
    float areaKm, pib;
    int pontosTuristicos;

    char estado2[3], cod2[100], cidade2[100];
    unsigned long int populacao2;
    float areaKm2, pib2;
    int pontosTuristicos2;

    float densidade, densidade2, perCapita, perCapita2;

    // Cadastro da carta 1
    printf("Cadastro da Carta 1\n");
    printf("Estado: "); scanf("%2s", estado); getchar();
    printf("Código: "); scanf("%s", cod); getchar();
    printf("Cidade: "); fgets(cidade, 100, stdin); cidade[strcspn(cidade, "\n")] = 0;
    printf("População: "); scanf("%lu", &populacao);
    printf("Área (km²): "); scanf("%f", &areaKm);
    printf("PIB (bilhões): "); scanf("%f", &pib);
    printf("Pontos Turísticos: "); scanf("%d", &pontosTuristicos);

    // Cadastro da carta 2
    printf("\nCadastro da Carta 2\n");
    printf("Estado: "); scanf("%2s", estado2); getchar();
    printf("Código: "); scanf("%s", cod2); getchar();
    printf("Cidade: "); fgets(cidade2, 100, stdin); cidade2[strcspn(cidade2, "\n")] = 0;
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área (km²): "); scanf("%f", &areaKm2);
    printf("PIB (bilhões): "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontosTuristicos2);

    // Cálculos
    densidade = populacao / areaKm;
    densidade2 = populacao2 / areaKm2;
    perCapita = pib / populacao;
    perCapita2 = pib2 / populacao2;

    // Menu de atributos
    int atributo1, atributo2;
    printf("\nEscolha o primeiro atributo:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica (menor vence)\n6. PIB per Capita\n");
    scanf("%d", &atributo1);

    while (atributo1 < 1 || atributo1 > 6) {
        printf("Opção inválida. Escolha entre 1 a 6: ");
        scanf("%d", &atributo1);
    }

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != atributo1)
            printf("%d. %s\n", i, nomeAtributo(i));
    }

    scanf("%d", &atributo2);
    while (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1) {
        printf("Opção inválida ou repetida. Escolha outro atributo: ");
        scanf("%d", &atributo2);
    }

    // Valores dos atributos
    float valor1_carta1 = escolherValor(atributo1, populacao, areaKm, pib, pontosTuristicos, densidade, perCapita);
    float valor1_carta2 = escolherValor(atributo1, populacao2, areaKm2, pib2, pontosTuristicos2, densidade2, perCapita2);
    float valor2_carta1 = escolherValor(atributo2, populacao, areaKm, pib, pontosTuristicos, densidade, perCapita);
    float valor2_carta2 = escolherValor(atributo2, populacao2, areaKm2, pib2, pontosTuristicos2, densidade2, perCapita2);

    // Comparações
    int pontos_carta1 = 0, pontos_carta2 = 0;

    // Atributo 1
    if (atributo1 == 5) {
        // Densidade (menor vence)
        (valor1_carta1 < valor1_carta2) ? pontos_carta1++ : (valor1_carta2 < valor1_carta1) ? pontos_carta2++ : 0;
    } else {
        (valor1_carta1 > valor1_carta2) ? pontos_carta1++ : (valor1_carta2 > valor1_carta1) ? pontos_carta2++ : 0;
    }

    // Atributo 2
    if (atributo2 == 5) {
        (valor2_carta1 < valor2_carta2) ? pontos_carta1++ : (valor2_carta2 < valor2_carta1) ? pontos_carta2++ : 0;
    } else {
        (valor2_carta1 > valor2_carta2) ? pontos_carta1++ : (valor2_carta2 > valor2_carta1) ? pontos_carta2++ : 0;
    }

    float soma1 = valor1_carta1 + valor2_carta1;
    float soma2 = valor1_carta2 + valor2_carta2;

    printf("\n===== RESULTADO =====\n");
    printf("Carta 1: %s (%s)\n", cidade, estado);
    printf("Carta 2: %s (%s)\n\n", cidade2, estado2);

    printf("Atributo 1 - %s\n", nomeAtributo(atributo1));
    printf("Carta 1: %.2f | Carta 2: %.2f\n", valor1_carta1, valor1_carta2);

    printf("\nAtributo 2 - %s\n", nomeAtributo(atributo2));
    printf("Carta 1: %.2f | Carta 2: %.2f\n", valor2_carta1, valor2_carta2);

    printf("\nSoma dos atributos:\n");
    printf("Carta 1: %.2f\n", soma1);
    printf("Carta 2: %.2f\n", soma2);

    printf("\nResultado Final: ");
    if (soma1 > soma2) {
        printf("Carta 1 (%s) venceu!\n", cidade);
    } else if (soma2 > soma1) {
        printf("Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    adicionarCartas();
    return 0;
}
