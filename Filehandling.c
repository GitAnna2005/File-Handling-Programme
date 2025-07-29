#include <stdio.h>
#include <stdlib.h>

void create_and_write_file(const char *filename);
void read_file(const char *filename);
void append_to_file(const char *filename);

int main() {
    const char *filename = "example.txt";
    int choice;

    do {
        printf("\nFile Operations Menu:\n");
        printf("1. Create and Write to File\n");
        printf("2. Read File\n");
        printf("3. Append to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline left by scanf

        switch (choice) {
            case 1:
                create_and_write_file(filename);
                break;
            case 2:
                read_file(filename);
                break;
            case 3:
                append_to_file(filename);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

void create_and_write_file(const char *filename) {
    FILE *fp = fopen(filename, "w"); // "w" mode creates a file or overwrites if it exists
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }

    char data[1000];
    printf("Enter data to write to file:\n");
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    fclose(fp);
    printf("Data written to file successfully.\n");
}

void read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return;
    }

    char ch;
    printf("\nContents of the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}

void append_to_file(const char *filename) {
    FILE *fp = fopen(filename, "a"); // "a" mode opens file for appending
    if (fp == NULL) {
        perror("Error opening file for appending");
        return;
    }

    char data[1000];
    printf("Enter data to append to file:\n");
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    fclose(fp);
    printf("Data appended to file successfully.\n");
}
