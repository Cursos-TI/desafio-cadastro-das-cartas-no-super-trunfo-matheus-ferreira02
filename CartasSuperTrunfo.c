#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

void readAndShowCard(int cardNumber, char *state, char *code, char *cityName, 
                     unsigned long int *population, float *area, float *PIB, 
                     int *touristAttractions, float *populationDensity, float *PIBPerCap, float *superPower) {
    
    char tempState[3];
    printf("Digite a UF do estado: ");
    scanf(" %2s", tempState);
    state[0] = tempState[0];
    state[1] = tempState[1];
    state[2] = tempState[2];

    printf("Digite o código: ");
    scanf("%s", code);

    printf("Digite o nome da cidade: ");
    scanf("%s", cityName);

    printf("Digite a população: ");
    scanf("%lu", population);

    printf("Digite a Área (em km²): ");
    scanf("%f", area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", PIB);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", touristAttractions);

    *populationDensity = (float) (*population) / (*area);
    *PIBPerCap = (*PIB * 1e9) / (*population);
    *superPower = (*population) + (*area) + (*PIB) + (*touristAttractions) + (*PIBPerCap) + (1.0 / *populationDensity);

    // Exibição dos dados da carta
    printf("===========================\n");
    printf("Carta %i:\n", cardNumber);
    printf("Estado: %s\n", state);
    printf("Código: %s\n", code);
    printf("Nome da Cidade: %s\n", cityName);
    printf("População: %lu\n", *population);
    printf("Área: %.2f km²\n", *area);
    printf("PIB: %.2f bilhões de reais\n", *PIB);
    printf("Número de Pontos Turísticos: %d\n", *touristAttractions);
    printf("Densidade Populacional: %.2f hab/km²\n", *populationDensity);
    printf("PIB per Capita: %.2f reais\n", *PIBPerCap);
    printf("Super Poder: %.2f\n", *superPower);
    printf("===========================\n");
}

// void compareCards(unsigned long int pop1, unsigned long int pop2, 
//                   float area1, float area2, float PIB1, float PIB2, 
//                   int points1, int points2, float density1, float density2, 
//                   float PIBCap1, float PIBCap2, float power1, float power2) {

//     printf("\nComparação de Cartas:\n\n");

//     printf("População: Carta %d venceu (%d)\n", pop1 > pop2 ? 1 : 2, pop1 > pop2);
//     printf("Área: Carta %d venceu (%d)\n", area1 > area2 ? 1 : 2, area1 > area2);
//     printf("PIB: Carta %d venceu (%d)\n", PIB1 > PIB2 ? 1 : 2, PIB1 > PIB2);
//     printf("Pontos Turísticos: Carta %d venceu (%d)\n", points1 > points2 ? 1 : 2, points1 > points2);
//     printf("Densidade Populacional: Carta %d venceu (%d)\n", density1 < density2 ? 1 : 2, density1 < density2);
//     printf("PIB per Capita: Carta %d venceu (%d)\n", PIBCap1 > PIBCap2 ? 1 : 2, PIBCap1 > PIBCap2);
//     printf("Super Poder: Carta %d venceu (%d)\n", power1 > power2 ? 1 : 2, power1 > power2);
// }

int main() {
    // Declaração das variáveis para as duas cartas
    char state1[3], state2[3];
    char code1[3], code2[3];
    char cityName1[20], cityName2[20];
    unsigned long int population1, population2;
    float area1, area2, PIB1, PIB2;
    int touristAttractions1, touristAttractions2;
    float density1, density2, PIBCap1, PIBCap2, superPower1, superPower2;

    // Leitura das cartas
    printf("Digite os dados da primeira carta:\n");
    readAndShowCard(1, state1, code1, cityName1, &population1, &area1, &PIB1, &touristAttractions1, &density1, &PIBCap1, &superPower1);
    
    printf("\n\n");

    printf("Digite os dados da segunda carta:\n");
    readAndShowCard(2, state2, code2, cityName2, &population2, &area2, &PIB2, &touristAttractions2, &density2, &PIBCap2, &superPower2);
    
    printf("\n\n");

    // Comparação das cartas
    // compareCards(population1, population2, area1, area2, PIB1, PIB2, 
    //              touristAttractions1, touristAttractions2, density1, density2, 
    //              PIBCap1, PIBCap2, superPower1, superPower2);

    printf("Carta 1 - %s (%s): %lu\n", cityName1, state1, population1);
    printf("Carta 2 - %s (%s): %lu\n", cityName2, state2, population2);

    if (population1 > population2) {
        printf("Resultado: Carta 1 (%s) venceu!", cityName1);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!", cityName2);
    }

    return 0;
}
