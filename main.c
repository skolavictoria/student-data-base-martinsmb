#include <stdio.h>
#include <string.h>

struct Person {
    char name[100];
    int age;
    char profession[100];
};

int main() {
    int numPeople;
    
    printf("Enter the number of people you want to enter: ");
    scanf("%d", &numPeople);

    
    struct Person people[numPeople];

    for (int i = 0; i < numPeople; i++) {
        printf("Enter details for person %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", people[i].name);
        printf("Age: ");
        scanf("%d", &people[i].age);
        printf("Profession: ");
        scanf("%s", people[i].profession);
    }

   
    FILE *file = fopen("people.txt", "a");
    if (file == NULL) {
        printf("Error opening file for appending!\n");
        return 1;
    }

    for (int i = 0; i < numPeople; i++) {
        fprintf(file, "Name: %s, Age: %d, Profession: %s\n", people[i].name, people[i].age, people[i].profession);
    }

    fclose(file);
    printf("Data appended to people.txt\n");

   
    file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("Data from file:\n");
    char line[200];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
