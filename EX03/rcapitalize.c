#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

char* rcapitalize(char* param_1) {
    if (param_1 == ((void*)0)) {
        return ((void*)0);
    }

    int len = 0;
    while (param_1[len] != '\0') {
        len++;
    }

    char* result = (char*)malloc(len + 1);
    if (result == ((void*)0)) {
        return ((void*)0);
    }

    for (int i = 0; i <= len; i++) {
        result[i] = param_1[i];
    }

    int i = 0;
    while (result[i] != '\0') {
        while (result[i] == ' ' || result[i] == '\t') {
            i++;
        }
        if (result[i] == '\0') {
            break;
        }

        int start = i;
        while (result[i] != '\0' && result[i] != ' ' && result[i] != '\t') {
            i++;
        }
        int end = i - 1;

        int last_letter_idx = -1;
        for (int j = end; j >= start; j--) {
            if ((result[j] >= 'a' && result[j] <= 'z') || (result[j] >= 'A' && result[j] <= 'Z')) {
                last_letter_idx = j;
                break;
            }
        }

        for (int j = start; j <= end; j++) {
            if ((result[j] >= 'a' && result[j] <= 'z') || (result[j] >= 'A' && result[j] <= 'Z')) {
                if (j == last_letter_idx) {
                    if (result[j] >= 'a' && result[j] <= 'z') {
                        result[j] = result[j] - 32;
                    }
                } else {
                    if (result[j] >= 'A' && result[j] <= 'Z') {
                        result[j] = result[j] + 32;
                    }
                }
            }
        }
    }

    return result;
}

int main() {
    char* res1 = rcapitalize("a FiRSt LiTTlE TESt");
    printf("Test 1 => \"%s\"\n", res1);
    free(res1);

    char* res2 = rcapitalize("a");
    printf("Test 2 => \"%s\"\n", res2);
    free(res2);

    char* res3 = rcapitalize("hello\tworld");
    printf("Test 3 => \"%s\"\n", res3);
    free(res3);

    return 0;
}