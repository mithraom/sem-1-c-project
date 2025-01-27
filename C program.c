#include <stdio.h>
#include <string.h>

#define NUM_COUNTRIES 5
#define NUM_YEARS 5

// Define the structure
struct Country {
    char name[50];
    char importer[50];
    double avg_qty;
    double prices[NUM_YEARS];
};

// Function to accept input for the structure array
void acceptInput(struct Country *countries) {
    for (int i = 0; i < NUM_COUNTRIES; i++) {
        printf("Enter details for country %d:\n", i + 1);
        printf("Name of country: ");
        scanf("%s", &(countries + i)->name);

        printf("Name of importer: ");
        scanf("%s", &(countries + i)->importer);

        printf("Average quantity of import per year: ");
        scanf("%lf", &(countries + i)->avg_qty);

        printf("Enter prices for the last %d years: ", NUM_YEARS);
        for (int j = 0; j < NUM_YEARS; j++) {
            printf("\nYear %d: ", j + 1);
            scanf("%lf", &(countries + i)->prices[j]);
        }
    }
}

// Function to compute the average price per country
void computeAverage(struct Country *countries, double *averages) {
    for (int i = 0; i < NUM_COUNTRIES; i++) {
        double sum = 0;
        for (int j = 0; j < NUM_YEARS; j++) {
            sum += (countries + i)->prices[j];
        }
        *(averages + i) = sum / NUM_YEARS;
    }
}

// Function to print the average price per country
void printAverages(struct Country *countries, double *averages) {
    printf("\nAverage prices of apples per country:\n");
    for (int i = 0; i < NUM_COUNTRIES; i++) {
        printf("Country: %s, Average Price: %.2lf\n", (countries + i)->name, *(averages + i));
    }
}

// Function to find the maximum price offered, the year, and the country
void findMaximumRate(struct Country *countries) {
    double max_price = 0;
    int max_year = 0;
    char max_country[50];

    for (int i = 0; i < NUM_COUNTRIES; i++) {
        for (int j = 0; j < NUM_YEARS; j++) {
            if ((countries + i)->prices[j] > max_price) {
                max_price = (countries + i)->prices[j];
                max_year = j + 1;
                strcpy(max_country, (countries + i)->name);
            }
        }
    }

    printf("\nMaximum Price: %.2lf\n", max_price);
    printf("Offered by Country: %s in Year: %d\n", max_country, max_year);
}

int main() {
    struct Country countries[NUM_COUNTRIES];
    double averages[NUM_COUNTRIES];

    // Step 1: Accept input
    acceptInput(countries);

    // Step 2: Compute average prices
    computeAverage(countries, averages);

    // Step 3: Print average prices
    printAverages(countries, averages);

    // Step 4: Find and print maximum rate details
    findMaximumRate(countries);

    return 0;
}
