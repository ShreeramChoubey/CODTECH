#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Compress input.txt to compressed.txt
void compressFile() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("compressed.txt", "w");

    if (!in || !out) {
        printf("Error opening file.\n");
        return;
    }

    char ch, prev = fgetc(in);
    int count = 1;

    while ((ch = fgetc(in)) != EOF) {
        if (ch == prev) {
            count++;
        } else {
            fprintf(out, "%d%c", count, prev);
            count = 1;
        }
        prev = ch;
    }
    fprintf(out, "%d%c", count, prev);

    fclose(in);
    fclose(out);
    printf("Compression complete. Output: compressed.txt\n");
}

// Decompress compressed.txt to decompressed.txt
void decompressFile() {
    FILE *in = fopen("compressed.txt", "r");
    FILE *out = fopen("decompressed.txt", "w");

    if (!in || !out) {
        printf("Error opening file.\n");
        return;
    }

    int count;
    char ch;

    while (fscanf(in, "%d%c", &count, &ch) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
    printf("Decompression complete. Output: decompressed.txt\n");
}

int main() {
    int choice;

    printf("RLE Compression Tool\n");
    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        compressFile();
    else if (choice == 2)
        decompressFile();
    else
        printf("Invalid choice!\n");

    return 0;
}
