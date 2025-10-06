#include <stdio.h>

// دالة ترجع مجموع عددين
int add(int a, int b) {
    return a + b;
}

// دالة ترجع العدد الأكبر بين عددين
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

// دالة تحسب المعدل الحسابي لمصفوفة
float average(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = add(sum, arr[i]); // نستخدم دالة add
    }
    return (float)sum / n;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // إيجاد العدد الأكبر
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        largest = max(largest, arr[i]);
    }

    // حساب المعدل
    float avg = average(arr, n);

    printf("\nLargest number = %d\n", largest);
    printf("Average = %.2f\n", avg);

    return 0;
}
