#include <stdio.h>
#include <stdlib.h>

char* LoadString(int N) {
    char *str = (char*) malloc((N + 1) * sizeof(char));
    if (str == NULL) {
        printf("Error: Memory allocation failed.
");
        exit(1);
    }
    printf("Enter a string (max %d characters): ", N);
    fgets(str, N + 1, stdin);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '
') {
            str[i] = '';
            break;
        }
    }
    return str;
}

int StringLength(char *str) {
    int len = 0;
    while (str[len] != '') len++;
    return len;
}

void LoadArray(char *p, char arr[]) {
    int i = 0;
    while (p[i] != '') {
        arr[i] = p[i];
        i++;
    }
    arr[i] = '';
}

void ReverseArray(char arr[], char rev[], int n) {
    for (int i = 0; i < n; i++) {
        rev[i] = arr[n - 1 - i];
    }
    rev[n] = '';
}

void DisplayArray(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", arr[i]);
    }
    printf("
");
}

int SumStringASCII(char *p) {
    if (*p == '')
        return 0;
    return (int)(*p) + SumStringASCII(p + 1);
}

void ReverseString(char *start, char *end) {
    if (start >= end)
        return;
    char temp = *start;
    *start = *end;
    *end = temp;
    ReverseString(start + 1, end - 1);
}

int main() {
    char *str;
    int n;
    printf("Please enter the maximum size of the string:
");
    scanf("%d", &n);
    getchar();
    str = LoadString(n);
    int len = StringLength(str);
    char arr[len + 1], rev[len + 1];
    LoadArray(str, arr);
    printf("
Original array: ");
    DisplayArray(arr, len);
    ReverseArray(arr, rev, len);
    printf("Reversed array: ");
    DisplayArray(rev, len);
    int sum = SumStringASCII(str);
    printf("Sum of ASCII values (recursive): %d
", sum);
    ReverseString(str, str + len - 1);
    printf("String reversed recursively: %s
", str);
    free(str);
    return 0;
}