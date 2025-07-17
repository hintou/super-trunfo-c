#include <stdio.h>
#include <string.h>

const char* verificarInt(int a, int b){
    if(a > b){
        return "Carta 1 venceu (1)";
    }else if(a == b){
        return "Empate";
    }else{
        return "Carta 2 venceu (0)";
    }
}

const char* verificarFloat(float a, float b){
    if(a > b){
        return "Carta 1 venceu (1)";
    }else if(a == b){
        return "Empate";
    }else{
        return "Carta 2 venceu (0)";
    }
}

const char* verificarUnsignedLongInt(unsigned int a, unsigned int b){
    if(a > b){
        return "Carta 1 venceu (1)";
    }else if(a == b){
        return "Empate";
    }else{
        return "Carta 2 venceu (0)";
    }
}

const char* poderInversoFloat(float a, float b){
    if(a > b){
        return "Carta 2 venceu (0)";
    }else if(a == b){
        return "Empate";
    }else{
        return "Carta 1 venceu (1)";
    }
}

void adicionarCartas(){
    // Variáveis =======================

    char estado[3];
    char cod[100];
    char cidade[100];
    unsigned long int populacao;
    float areaKm;
    float pib;
    int numeroPontosTuristicos;

    float densidadePopulacional;
    float pibCapita;

    char estado2[3];
    char cod2[100];
    char cidade2[100];
    unsigned long int populacao2;
    float areaKm2;
    float pib2;
    int numeroPontosTuristicos2;

    float densidadePopulacional2;
    float pibCapita2;

    //Cadastro de Cartas ============================
    //getchar() utilizado para não causar bugs na digitação

    printf("Cadastro da Primeira Carta =========== \n"); //Primeira Carta

    printf("Digite o Estado (A - H): ");
    scanf("%2s", &estado);
    getchar();

    printf("Digite o Codigo (exemplo: S09): ");
    scanf("%s", cod);
    getchar();

    printf("Digite o nome da cidade: ");
    fgets(cidade, 100, stdin);
    cidade[strcspn(cidade, "\n")] = 0;

    printf("Digite a populacao: ");
    scanf("%lu", &populacao);
    getchar();

    printf("Digite a Area em Km²: ");
    scanf("%f", &areaKm);
    getchar();

    printf("Digite o PIB: ");
    scanf("%f", &pib);
    getchar();

    
    printf("Digite a quantidade de pontos turisticos: ");
    scanf("%d", &numeroPontosTuristicos);
    getchar();

    
    printf("\nCadastro da Segunda Carta =========== \n"); //Segunda Carta

    printf("Digite o Estado (A - H): ");
    scanf("%2s", &estado2);
    getchar();

    printf("Digite o Codigo (exemplo: S09): ");
    scanf("%s", cod2);
    getchar();

    printf("Digite o nome da cidade: ");
    fgets(cidade2, 100, stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("Digite a populacao: ");
    scanf("%lu", &populacao2);
    getchar();

    printf("Digite a Area em Km²: ");
    scanf("%f", &areaKm2);
    getchar();

    printf("Digite o PIB: ");
    scanf("%f", &pib2);
    getchar();

    printf("Digite a quantidade de pontos turisticos: ");
    scanf("%d", &numeroPontosTuristicos2);
    getchar();

    densidadePopulacional = populacao / areaKm;
    densidadePopulacional2 = populacao2 / areaKm2;

    pibCapita = (float)pib / populacao;
    pibCapita2 = (float)pib2 / populacao2;

    //super poder
    float poderCarta1 = populacao + areaKm + pib + numeroPontosTuristicos + pibCapita + (1.0/densidadePopulacional);
    float poderCarta2 = populacao2 + areaKm2 + pib2 + numeroPontosTuristicos2 + pibCapita2 + (1.0/densidadePopulacional2);

    //Exibir Dados ==================

    printf("\n======================\n\nCarta 01:\nEstado: %c\nCodigo: %s\nNome da Cidade: %s\nPopulacao: %lu\nArea: %.2f Km²\nPIB: %.2f Bilhoes de reais\nNumeros de Pontos Turisticos: %d\nDensidade Populacional: %.2f hab/Km²\nPIB per Capita: %.2f Reais", estado, cod, cidade, populacao, areaKm, pib, numeroPontosTuristicos, densidadePopulacional, pibCapita);
    printf("\n======================\n\nCarta 02:\nEstado: %c\nCodigo: %s\nNome da Cidade: %s\nPopulacao: %lu\nArea: %.2f Km²\nPIB: %.2f Bilhoes de reais\nNumeros de Pontos Turisticos: %d\nDensidade Populacional: %.2f hab/Km²\nPIB per Capita: %.2f Reais", estado2, cod2, cidade2, populacao2, areaKm2, pib2, numeroPontosTuristicos2, densidadePopulacional2, pibCapita2);

    //printf("\nComparação de Cartas:\n");
    //printf("População: %s\n", verificarUnsignedLongInt(populacao, populacao2));
    //printf("Área: %s\n", verificarFloat(areaKm, areaKm2));
    //printf("PIB: %s\n", verificarFloat(pib, pib2));
    //printf("Pontos Turísticos: %s\n", verificarInt(numeroPontosTuristicos, numeroPontosTuristicos2));
    //printf("Densidade Populacional: %s\n", poderInversoFloat(densidadePopulacional, densidadePopulacional2));
    //printf("PIB per Capita: %s\n", verificarFloat(pibCapita, pibCapita2));
    //printf("Super Poder: %s\n", verificarFloat(poderCarta1, poderCarta2));

    int escolha;
    printf("\nExibição do Resultado:\n");
    printf("1. Comparação por Nome do País\n");
    printf("2. Comparação por População\n");
    printf("3. Comparação por Área\n");
    printf("4. Comparação por PIB\n");
    printf("5. Comparação por Pontos Turísticos\n");
    printf("6. Densidade demográfica\n\n");

    printf("Digite a opção que deseja: ");
    scanf("%d", &escolha);

    switch(escolha){
        case 1:
            printf("Nome dos Países:\n");
            printf("Carta 1: %s (%s)\n", cidade, estado);
            printf("Carta 2: %s (%s)\n", cidade2, estado2);
            break;
        case 2:
            printf("Comparação de Cartas (Atributo: População):\n");
            printf("Carta 1 - %s (%s): %lu\n", cidade, estado, populacao);
            printf("Carta 2 - %s (%s): %lu\n", cidade2, estado2, populacao2);

            if (populacao > populacao2){
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            }else if(populacao < populacao2){
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            }else{
                printf("Resultado: Empate\n");
            }
            break;  
        case 3:
            printf("Comparação de Cartas (Atributo: Área):\n");
            printf("Carta 1 - %s: %.2f km²\n", cidade, areaKm);
            printf("Carta 2 - %s: %.2f km²\n", cidade2, areaKm2);

            if (areaKm > areaKm2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (areaKm < areaKm2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 4:
            printf("Comparação de Cartas (Atributo: PIB):\n");
            printf("Carta 1 - %s: %.2f bilhões\n", cidade, pib);
            printf("Carta 2 - %s: %.2f bilhões\n", cidade2, pib2);

            if (pib > pib2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (pib < pib2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 5:
            printf("Comparação de Cartas (Atributo: Pontos Turísticos):\n");
            printf("Carta 1 - %s: %d pontos\n", cidade, numeroPontosTuristicos);
            printf("Carta 2 - %s: %d pontos\n", cidade2, numeroPontosTuristicos2);

            if (numeroPontosTuristicos > numeroPontosTuristicos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (numeroPontosTuristicos < numeroPontosTuristicos2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 6:
            printf("Comparação de Cartas (Atributo: Densidade Demográfica - menor vence):\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", cidade, densidadePopulacional);
            printf("Carta 2 - %s: %.2f hab/km²\n", cidade2, densidadePopulacional2);

            if (densidadePopulacional < densidadePopulacional2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (densidadePopulacional > densidadePopulacional2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;  
    }

}


int main(){
    adicionarCartas();
    return 0;
}