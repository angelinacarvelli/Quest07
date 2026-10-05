#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

char* inter(char* param_1, char* param_2) {
    if (param_1 == ((void*)0)) param_1 = "";
    if (param_2 == ((void*)0)) param_2 = "";

    int len1 = 0;
    while (param_1[len1] != '\0') {
        len1++;
    }

    char* result = (char*)malloc(len1 + 1);
    if (result == ((void*)0)) {
        return ((void*)0);
    }

    int in_param2[256] = {0};
    int added[256] = {0};

    int i = 0;
    while (param_2[i] != '\0') {
        in_param2[(unsigned char)param_2[i]] = 1;
        i++;
    }

    int res_index = 0;
    i = 0;
    while (param_1[i] != '\0') {
        unsigned char c = (unsigned char)param_1[i];
        if (in_param2[c] && !added[c]) {
            added[c] = 1;
            result[res_index++] = param_1[i];
        }
        i++;
    }

    result[res_index] = '\0';

    return result;
}

int main() {
    char* res1 = inter("padinton", "paqefwtdjetyiytjneytjoeyjnejeyj");
    printf("Test 1 => \"%s\")\n", res1);
    free(res1);

    char* res2 = inter("abc", "xyz");
    printf("Test 2 => \"%s\"\n", res2);
    free(res2);

    char* res3 = inter("nothing", "This sentence hides nothing");
    printf("Test 3 => \"%s\"\n", res3);
    free(res3);

    return 0;
}