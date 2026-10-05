#include <stdio.h>

int is_anagram(char* param_1, char* param_2) {
    if (param_1 == ((void*)0) || param_2 == ((void*)0)) {
        return 0;
    }

    int count[256] = {0};
    int len1 = 0;
    int len2 = 0;

    while (param_1[len1] != '\0') {
        count[(unsigned char)param_1[len1]]++;
        len1++;
    }

    while (param_2[len2] != '\0') {
        count[(unsigned char)param_2[len2]]--;
        len2++;
    }

    if (len1 != len2) {
        return 0;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    printf("Test 1 (\"abcdef\", \"fabcde\") => %d\n", is_anagram("abcdef", "fabcde"));
    printf("Test 2 (\"ad\", \"bc\") => %d\n", is_anagram("ad", "bc"));
    printf("Test 3 (\"\", \"\") => %d\n", is_anagram("", ""));
    printf("Test 4 (\"a\", \"aa\") => %d\n", is_anagram("a", "aa"));
    printf("Test 5 (\"aabbcc\", \"abcabc\") => %d\n", is_anagram("aabbcc", "abcabc"));
    return 0;
}