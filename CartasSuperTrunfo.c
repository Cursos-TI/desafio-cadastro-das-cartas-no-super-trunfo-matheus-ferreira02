#include <stdio.h>
#include <stdbool.h>

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

void printOptions() {
    printf("\n===========================\n");
    printf("1.População\n");
    printf("2.Área\n");
    printf("3.PIB\n");
    printf("4.Número de pontos turísticos\n");
    printf("5.Densidade demográfica\n");
    printf("===========================\n");
}

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

    bool isSameOption = true;
    int opcao1, opcao2;
        
    while (isSameOption) {
        printf("Escolha o primeiro atributo para comparar\n");
        printOptions();
        scanf("%d", &opcao1);

        printf("-------------------------\n");

        printf("Escolha o segundo atributo atributo para comparar\n");
        printOptions();
        scanf("%d", &opcao2);

        if (opcao1 != opcao2) {
            isSameOption = false;
        } else {
            printf("Não é possível escolher o mesmo atributo, escolha outro\n");
        }
    }

    printf("===========================\n");

    double sumFirstCard = 0, sumSecondCard = 0;

    printf("Cidade 1: %s - Cidade 2: %s\n", cityName1, cityName2);

    switch (opcao1) {
        case 1:
            printf("Atributo escolhido: População\n");
            printf("%lu da carta 1 - %lu da carta 2\n", population1, population2);
            if (population1 > population2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cityName1);
            } else if (population1 < population2){
                printf("Resultado: Carta 2 (%s) venceu!\n", cityName2);
            } else {
                printf("Empate!\n");
            }

            sumFirstCard += population1;
            sumSecondCard += population2;
            break;
        case 2:
            printf("Atributo escolhido: Área\n");
            printf("%.2f km² da carta 1 - %.2f km² da carta 2\n", area1, area2);
            if (area1 > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cityName1);
            } else if (area1 < area2){
                printf("Resultado: Carta 2 (%s) venceu!\n", cityName2);
            } else {
                printf("Empate!");
            }

            sumFirstCard += area1;
            sumSecondCard += area2;

            break;
        case 3:
            printf("Atributo escolhido: PIB\n");
            printf("%.2f da carta 1 - %.2f da carta 2\n", PIB1, PIB2);
            if (PIB1 > PIB2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cityName1);
            } else if (PIB1 < PIB2){
                printf("Resultado: Carta 2 (%s) venceu!\n", cityName2);
            } else {
                printf("Empate!");
            }
            sumFirstCard += PIB1;
            sumSecondCard += PIB2;
            break;
        case 4:
            printf("Atributo escolhido: Pontos turísticos\n");
            printf("%d da carta 1 - %d da carta 2\n", touristAttractions1, touristAttractions2);
            if (touristAttractions1 > touristAttractions2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cityName1);
            } else if (touristAttractions1 < touristAttractions2){
                printf("Resultado: Carta 2 (%s) venceu!\n", cityName2);
            } else {
                printf("Empate!");
            }
            sumFirstCard += touristAttractions1;
            sumSecondCard += touristAttractions2;
            break;
        case 5:
            printf("Atributo escolhido: Densidade demográfica\n");
            printf("%.2f hab/km² da carta 1 - %.2f hab/km² da carta 2\n", density1, density2);
            if (density1 < density2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cityName1);
            } else if (density1 > density2){
                printf("Resultado: Carta 2 (%s) venceu!\n", cityName2);
            } else {
                printf("Empate!");
            }
            sumFirstCard += density1;
            sumSecondCard += density2;
            break;
        default:
            printf("Opção inválida");
    }

    printf("-----------------------\n");

    switch (opcao2) {
        case 1:
            printf("Atributo escolhido: População\n");
            printf("%lu da carta 1 - %lu da carta 2\n", population1, population2);
            if (population1 > population2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cityName1);
            } else if (population1 < population2){
                printf("Resultado: Carta 2 (%s) venceu!\n", cityName2);
            } else {
                printf("Empate!\n");
            }

            sumFirstCard += population1;
            sumSecondCard += population2;
            break;
        case 2:
            printf("Atributo escolhido: Área\n");
            printf("%.2f km² da carta 1 - %.2f km² da carta 2\n", area1, area2);
            if (area1 > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cityName1);
            } else if (area1 < area2){
                printf("Resultado: Carta 2 (%s) venceu!\n", cityName2);
            } else {
                printf("Empate!");
            }

            sumFirstCard += area1;
            sumSecondCard += area2;

            break;
        case 3:
            printf("Atributo escolhido: PIB\n");
            printf("%.2f da carta 1 - %.2f da carta 2\n", PIB1, PIB2);
            if (PIB1 > PIB2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cityName1);
            } else if (PIB1 < PIB2){
                printf("Resultado: Carta 2 (%s) venceu!\n", cityName2);
            } else {
                printf("Empate!");
            }
            sumFirstCard += PIB1;
            sumSecondCard += PIB2;
            break;
        case 4:
            printf("Atributo escolhido: Pontos turísticos\n");
            printf("%d da carta 1 - %d da carta 2\n", touristAttractions1, touristAttractions2);
            if (touristAttractions1 > touristAttractions2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cityName1);
            } else if (touristAttractions1 < touristAttractions2){
                printf("Resultado: Carta 2 (%s) venceu!\n", cityName2);
            } else {
                printf("Empate!");
            }
            sumFirstCard += touristAttractions1;
            sumSecondCard += touristAttractions2;
            break;
        case 5:
            printf("Atributo escolhido: Densidade demográfica\n");
            printf("%.2f hab/km² da carta 1 - %.2f hab/km² da carta 2\n", density1, density2);
            if (density1 < density2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cityName1);
            } else if (density1 > density2){
                printf("Resultado: Carta 2 (%s) venceu!\n", cityName2);
            } else {
                printf("Empate!");
            }
            sumFirstCard += density1;
            sumSecondCard += density2;
            break;
        default:
            printf("Opção inválida");
    }

    printf("-----------------------\n");
    printf("Soma total da Carta 1: %.2lf\n", sumFirstCard);
    printf("Soma total da Carta 2: %.2lf\n", sumSecondCard);
    printf("-----------------------\n");

    printf(
        (sumFirstCard > sumSecondCard) ? "Carta 1 venceu com a soma dos atributos: %.2lf\n" :
        (sumFirstCard < sumSecondCard) ? "Carta 2 venceu com a soma dos atributos: %.2lf\n" :
        "Empate!\n", 
        (sumFirstCard > sumSecondCard) ? sumFirstCard : (sumFirstCard < sumSecondCard) ? sumSecondCard : 0
    );

    return 0;
}
