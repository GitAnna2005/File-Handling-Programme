#include <stdio.h>
#include <string.h>

void runLengthEncode(char *input) {
    int len = strlen(input);
    int count;

    for (int i = 0; i < len; i++) {
        count = 1;

        // Count occurrences of the same character
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Output the character and count
        printf("%c%d", input[i], count);
    }
    printf("\n");
}

int main() {
    char input[100];

    printf("Enter a string to compress (no spaces): ");
    scanf("%s", input);

    printf("Compressed output: ");
    runLengthEncode(input);

    return 0;
}
