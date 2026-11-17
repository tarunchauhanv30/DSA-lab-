#include <stdio.h>
int a[20], s[20], n, t;
void f(int i, int sum, int sz) {
    if (i == n) {
        if (sum == t) {
            printf("{");
            for (int j = 0; j < sz; j++)
                printf("%d%s", s[j], j + 1 < sz ? ", " : "");
            printf("}\n");
        }
        return;
    }
    s[sz] = a[i];
    f(i + 1, sum + a[i], sz + 1);
    f(i + 1, sum, sz);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &t);
    f(0, 0, 0);
    return 0;
}
v