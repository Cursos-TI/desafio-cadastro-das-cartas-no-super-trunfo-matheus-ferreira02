#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

void readAndShowCard(int cardNumber) {
    char tempState;
    printf("Digite o estado (A a H): ");
    scanf(" %c", &tempState);
    char state = tempState;

    char code[3];
    printf("Digite o código: ");
    scanf("%s", code);

    char cityName[20];
    printf("Digite o nome da cidade: ");
    scanf("%s", cityName);

    int population;
    printf("Digite a população: ");
    scanf("%i", &population);

    float area;
    printf("Digite a Área (em km²): ");
    scanf(" %f", &area);

    float PIB;
    printf("Digite o PIB: ");
    scanf(" %f", &PIB);

    int touristAttractions;
    printf("Digite a quantidade de pontos turisticos: ");
    scanf("%i", &touristAttractions);

    printf("=========================== \n");
    printf("Carta %i: \n", cardNumber);
    printf("Estado: %c\n", state);
    printf("Código: %s\n", code);
    printf("Nome da Cidade: %s\n", cityName);
    printf("População: %d\n", population);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", PIB);
    printf("Número de Pontos Turísticos: %d\n", touristAttractions);
    printf("=========================== \n");
}

int main() {
    printf("Digite os dados da primeira carta: \n");
    readAndShowCard(1);

    printf("\n\n\n");

    printf("Digite os dados da segunda carta: \n");
    readAndShowCard(2);

    return 0;
}
