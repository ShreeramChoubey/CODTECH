#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char keywords[32][10] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","int","long",
    "register","return","short","signed","sizeof","static","struct",
    "switch","typedef","union","unsigned","void","volatile","while"
};

// Function to check if the word is a keyword
int isKeyword(char *word) {
    for(int i = 0; i < 32; i++) {
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>';
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        printf("Unable to open file.\n");
        return 1;
    }

    char ch, buffer[50];
    int i = 0;

    printf("Lexical Analysis Output:\n");
    while((ch = fgetc(file)) != EOF) {
        if (isalnum(ch)) {
            buffer[i++] = ch;
        } else if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (i != 0) {
                buffer[i] = '\0';
                if (isKeyword(buffer))
                    printf("[Keyword]    -> %s\n", buffer);
                else
                    printf("[Identifier] -> %s\n", buffer);
                i = 0;
            }
        } else if (isOperator(ch)) {
            if (i != 0) {
                buffer[i] = '\0';
                if (isKeyword(buffer))
                    printf("[Keyword]    -> %s\n", buffer);
                else
                    printf("[Identifier] -> %s\n", buffer);
                i = 0;
            }
            printf("[Operator]   -> %c\n", ch);
        }
    }

    fclose(file);
    return 0;
}
