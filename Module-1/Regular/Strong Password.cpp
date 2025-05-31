#include <stdio.h>
#include <string.h>

int minimumNumber(int n, char *password) {
    int required_chars = 0;
    int has_digit = 0, has_lower = 0, has_upper = 0, has_special = 0;
    const char *special_characters = "!@#$%^&*()-+";
int i;
    for ( i = 0; i < n; i++) {
        if (password[i] >= '0' && password[i] <= '9') has_digit = 1;
        else if (password[i] >= 'a' && password[i] <= 'z') has_lower = 1;
        else if (password[i] >= 'A' && password[i] <= 'Z') has_upper = 1;
        else if (strchr(special_characters, password[i])) has_special = 1;
    }

    if (!has_digit) required_chars++;
    if (!has_lower) required_chars++;
    if (!has_upper) required_chars++;
    if (!has_special) required_chars++;

    if (n + required_chars < 6) {
        required_chars += (6 - (n + required_chars));
    }

    return required_chars;
}

int main() {
    int n;
    char password[101];
    scanf("%d", &n);
    scanf("%s", password);
    int result = minimumNumber(n, password);
    printf("%d\n", result);
    return 0;
}
