
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

char* my_union(char* param_1, char* param_2) {
    if (param_1 == ((void*)0)) param_1 = "";
    if (param_2 == ((void*)0)) param_2 = "";

    int len1 = 0, len2 = 0;
    while (param_1[len1] != '\0') len1++;
    while (param_2[len2] != '\0') len2++;

    char* result = (char*)malloc(len1 + len2 + 1);
    if (result == ((void*)0)) {
        return ((void*)0);
    }

    int seen[256] = {0};
    int res_index = 0;

    for (int i = 0; i < len1; i++) {
        unsigned char c = (unsigned char)param_1[i];
        if (!seen[c]) {
            seen[c] = 1;
            result[res_index++] = param_1[i];
        }
    }

    for (int i = 0; i < len2; i++) {
        unsigned char c = (unsigned char)param_2[i];
        if (!seen[c]) {
            seen[c] = 1;
            result[res_index++] = param_2[i];
        }
    }

    result[res_index] = '\0';

    return result;
}

int main() {
    char* res1 = my_union("zpadinton", "paqefwtdjetyiytjneytjoeyjnejeyj");
    printf("Test 1 => \"%s\"\n", res1);
    free(res1);

    char* res2 = my_union("abc", "abc");
    printf("Test 2 => \"%s\"\n", res2);
    free(res2);

    char* res3 = my_union("a", "a");
    printf("Test 3 => \"%s\"\n", res3);
    free(res3);

    return 0;
}