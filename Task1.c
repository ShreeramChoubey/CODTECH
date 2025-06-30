#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to create file.\n");
        exit(1);
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(file);
}

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        exit(1);
    }
    fprintf(file, "This is the initial content written to the file.\n");
    printf("Data written successfully to '%s'.\n", filename);
    fclose(file);
}

void appendFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Unable to open file for appending.\n");
        exit(1);
    }
    fprintf(file, "This is the appended content.\n");
    printf("Data appended successfully to '%s'.\n", filename);
    fclose(file);
}

void readFile(const char *filename) {
    char ch;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file for reading.\n");
        exit(1);
    }
    printf("Reading contents of '%s':\n", filename);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

int main() {
    const char *filename = "codtech_task1.txt";

    createFile(filename);
    writeFile(filename);
    appendFile(filename);
    readFile(filename);

    return 0;
}
