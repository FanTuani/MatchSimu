#include <stdio.h>
#include "utils.h"
#include "simulation.h"

void process();

void input(double ability[], int *n);

int main() {
    while (1) {
        process();
    }
}

void process() {
    clear_screen();
    printf("�������ģ������ѡ�� A �� B ��ĳ�־�������\n");
    printf("����������Ҫ A �� B ������ֵ���� 0 �� 1 ֮���С����ʾ��\n");
    double ability[2];
    int n;
    input(ability, &n);
    int win1 = simulate(ability, n);
    int win2 = n - win1;
    printf("ѡ�� A ��ʤ %d ��������ռ�� %.2lf\n", win1, win1 * 1.0 / n);
    printf("ѡ�� A ��ʤ %d ��������ռ�� %.2lf\n", win2, win2 * 1.0 / n);
    getchar();
    getchar();
}

void input(double ability[], int *n) {
    printf("������ѡ�� A ������ֵ (0-1): ");
    scanf("%lf", &ability[0]);
    printf("������ѡ�� B ������ֵ (0-1): ");
    scanf("%lf", &ability[1]);
    printf("ģ������ĳ���: ");
    scanf("%d", n);
}
