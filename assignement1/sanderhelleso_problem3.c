#include <stdio.h>
#include <stdlib.h> // for exit warning

void run();
void runOption(int option);
int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);
char *_strcat(char* dest, const char* src);

#define MAX_STR_LEN 100

int main() {  
    run();
    
    return 0;
}

void run() {
    const char LINE[] = "---------------------------------";
    printf("\n%s\n", LINE);
    printf("1: strcmp - Compare two strings\n");
    printf("2: strlen - Check the length of a string\n");
    printf("3: strcat - Append string2 to string1\n");
    printf("4: exit   - Exits the application\n");
    printf("%s\n", LINE);
    
    while (1 < 2) {
        int option;
        printf("\n> Please select an option: ");
        scanf("%d", &option);
        
        if (option > 4 || option < 1) {
            printf("Invalid option. Please enter a option from the menu\n");
        }  else {
            runOption(option);
        }
    }
}

void runOption(int option) {
    switch (option) {
        case 1: {
            char str1[MAX_STR_LEN];
            char str2[MAX_STR_LEN];

            printf("Enter string 1: ");
            scanf("%s", str1);

            printf("Enter string 2: ");
            scanf("%s", str2);

            printf("Difference between '%s' and '%s' is %d\n", str1, str2, _strcmp(str1, str2));
            break;
        }

        case 2: {
            char input[MAX_STR_LEN];

            printf("Enter a string: ");
            scanf("%s", input);

            printf("Length of '%s' is %d\n", input, _strlen(input));
            break;
        }

        case 3: {
            char str1[MAX_STR_LEN];
            char str2[MAX_STR_LEN];

            printf("Enter string 1: ");
            scanf("%s", str1);

            printf("Enter string 2: ");
            scanf("%s", str2);

            printf("Result after concating is '%s'\n", str1, str2, _strcat(str1, str2));
            break;
        }

        case 4: {
            printf("Bye!");
            exit(0); 
        }    

        default: break;
    }
}

int _strcmp(const char *str1, const char *str2) {

    // to end of str1 AND aslong as chars are equal
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    // convert to range 0 - 255 and print diff
    const unsigned char *len1 = (const unsigned char *) str1;
    const unsigned char *len2 = (const unsigned char *)str2;

    return *len1 - *len2;
}

size_t _strlen(const char *str) {
    int i = 0;
    while (str[i] != '\0') i++;

    return i;
}

char *_strcat(char* dest, const char* src) {
	char* destPtr = dest + _strlen(dest);

	while (*src != '\0') *destPtr++ = *src++;
	*destPtr = '\0';

	return destPtr;
}
