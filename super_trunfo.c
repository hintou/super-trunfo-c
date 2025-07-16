#include <stdio.h>
#include <string.h>

void adicionarCartas(){
    // Variáveis =======================

    char estado;
    char cod[100];
    char cidade[100];
    int populacao;
    float areaKm;
    float pib;
    int numeroPontosTuristicos;

    char estado2;
    char cod2[100];
    char cidade2[100];
    int populacao2;
    float areaKm2;
    float pib2;
    int numeroPontosTuristicos2;

    //Cadastro de Cartas ============================

    printf("Cadastro da Primeira Carta =========== \n"); //Primeira Carta

    printf("Digite o Estado (A - H): ");
    scanf(" %c", &estado);

    printf("Digite o Codigo (exemplo: S09): ");
    scanf("%s", cod);

    printf("Digite o nome da cidade: ");
    getchar();
    fgets(cidade, 100, stdin);
    cidade[strcspn(cidade, "\n")] = 0;

    printf("Digite a populacao: ");
    scanf("%d", &populacao);

    printf("Digite a Area em Km²: ");
    scanf("%f", &areaKm);

    printf("Digite o PIB: ");
    scanf("%f", &pib);

    printf("Digite a quantidade de pontos turisticos: ");
    scanf("%d", &numeroPontosTuristicos);


    printf("\nCadastro da Segunda Carta =========== \n"); //Segunda Carta

    printf("Digite o Estado (A - H): ");
    scanf(" %c", &estado2);

    printf("Digite o Codigo (exemplo: S09): ");
    scanf("%s", cod2);

    printf("Digite o nome da cidade: ");
    getchar();
    fgets(cidade2, 100, stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("Digite a populacao: ");
    scanf("%d", &populacao2);

    printf("Digite a Area em Km²: ");
    scanf("%f", &areaKm2);

    printf("Digite o PIB: ");
    scanf("%f", &pib2);

    printf("Digite a quantidade de pontos turisticos: ");
    scanf("%d", &numeroPontosTuristicos2);

    

    //Exibir Dados ==================

    printf("\n======================\n\nCarta 01:\nEstado: %c\nCodigo: %s\nNome da Cidade: %s\nPopulacao: %d\nArea: %.2f Km²\nPIB: %.2f Bilhoes de reais\nNumeros de Pontos Turisticos: %d\n", estado, cod, cidade, populacao, areaKm, pib, numeroPontosTuristicos);
    printf("\n======================\n\nCarta 02:\nEstado: %c\nCodigo: %s\nNome da Cidade: %s\nPopulacao: %d\nArea: %.2f Km²\nPIB: %.2f Bilhoes de reais\nNumeros de Pontos Turisticos: %d\n", estado2, cod2, cidade2, populacao2, areaKm2, pib2, numeroPontosTuristicos2);

}

int main(){
    adicionarCartas();
    return 0;
}

