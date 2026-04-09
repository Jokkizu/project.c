#include <stdio.h>

#define MAX_USER_INPUT_STRING 1000

// Prototypes
void print_logo(void);
void display_menu(void);
void read_string(char s[]);
void print_string(char s[]);
int count_consonants(char s[]);
int count_vowels(char s[]);
void to_lower(char s[]);
void to_upper(char s[]);
void read_file(char s[]);

int main() {
    char s[MAX_USER_INPUT_STRING] = "Hello World";
    char choice;
    int running = 1;

    print_logo();
    display_menu();

    while (running) {
        printf("\nGive Command: ");
        
        if (scanf(" %c", &choice) != 1) break;
        while (getchar() != '\n'); 

        switch (choice) {
            case 'A': case 'a':
                printf("String has %d vowels\n", count_vowels(s));
                break;
            case 'B': case 'b':
                printf("String has %d consonants\n", count_consonants(s));
                break;
            case 'C': case 'c':
                to_upper(s);
                break;
            case 'D': case 'd':
                to_lower(s);
                break;
            case 'E': case 'e':
                print_string(s);
                break;
            case 'F': case 'f':
                read_string(s);
                break;
            case 'G': case 'g':
                read_file(s);
                break;
            case 'H': case 'h': {
                FILE *fp = fopen("string.txt", "w");
                if (fp) {
                    fprintf(fp, "%s", s);
                    fclose(fp);
                }
                break;
            }
            case 'M': case 'm':
                display_menu();
                break;
            case 'X': case 'x':
                running = 0;
                break;
        }
    }
    return 0;
}

// --- Function Definitions ---

void display_menu(void) {
    printf("\nA) Count the number of vowels in the string\n");
    printf("B) Count the number of consonants in the string\n");
    printf("C) Convert the string to uppercase\n");
    printf("D) Convert the string to lowercase\n");
    printf("E) Display the current string\n");
    printf("F) Enter another string\n");
    printf("G) Read string from file\n");
    printf("H) Write string to file\n\n");
    printf("M) Display this menu\n");
    printf("X) Exit the program\n");
}

void print_logo(void) {
    printf("          __         .__\n");
    printf("  _______/  |________|__| ____    ____\n");
    printf(" /  ___/\\   __\\_  __ \\  |/    \\  / ___\\\n");
    printf(" \\___ \\  |  |  |  | \\/  |   |  \\/ /_/  >\n");
    printf("/____  > |__|  |__|  |__|___|  /\\___  /\n");
    printf("     \\/                       \\//_____/\n");
}

void read_string(char s[]) {
    printf("Give String: ");
    if (fgets(s, MAX_USER_INPUT_STRING, stdin) != NULL) {
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '\n') { s[i] = '\0'; break; }
        }
    }
}

void print_string(char s[]) {
    printf("%s\n", s);
}

int count_vowels(char s[]) {
    int count = 0, i = 0;
    while (s[i]) {
        char c = s[i];
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') count++;
        i++;
    }
    return count;
}

int count_consonants(char s[]) {
    int count = 0, i = 0;
    while (s[i]) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) count++;
        }
        i++;
    }
    return count;
}

void to_upper(char s[]) {
    for (int i = 0; s[i]; i++) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
}

void to_lower(char s[]) {
    for (int i = 0; s[i]; i++) if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
}

void read_file(char s[]) {
    FILE *fp = fopen("string.txt", "r");
    if (!fp) { printf("File cannot be read\n"); return; }
    if (fgets(s, MAX_USER_INPUT_STRING, fp) != NULL) {
        for (int i = 0; s[i] != '\0'; i++) if (s[i] == '\n') s[i] = '\0';
    }
    fclose(fp);
}
