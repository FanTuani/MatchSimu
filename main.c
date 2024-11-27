#include <stdio.h>
#include "simulation.h"

#define N 114514
double hisAbility[N][2];
int hisN[N], hisWin1[N], hisCnt = 1;

void process();

void input(double ability[], int *n);

void printHistory();

void printUI();

int main() {
    while (1) {
        printUI();
    }
}

void printUI() {
    system("cls");
    printf("1. ���о���ģ��\n");
    printf("2. �鿴��ʷģ��\n");
    char op;
    scanf("%c", &op);
    getchar();
    if (op == '1') {
        process();
    } else if (op == '2') {
        printHistory();
    } else {
        return;
    }
}

void process() {
    system("cls");
    printf("�������ģ������ѡ�� A �� B ��ĳ�־�������\n");
    printf("����������Ҫ A �� B ������ֵ���� 0 �� 1 ֮���С����ʾ��\n");
    double ability[2];
    int n;
    input(ability, &n);
    int win1 = simulate(ability, n);
    int win2 = n - win1;
    printf("ѡ�� A ��ʤ %d ��������ռ�� %.2lf\n", win1, win1 * 1.0 / n);
    printf("ѡ�� B ��ʤ %d ��������ռ�� %.2lf\n", win2, win2 * 1.0 / n);
    hisN[hisCnt] = n, hisAbility[hisCnt][0] = ability[0], hisAbility[hisCnt][1] = ability[1];
    hisWin1[hisCnt++] = win1;
    getchar();
    getchar();
}

void printHistory() {
    system("cls");
    printf("���� %d ����ʷģ������\n\n", hisCnt - 1);
    for (int i = 1; i < hisCnt; i++) {
        printf("�� %d ��ģ�����:\n", i);
        printf("-------------------\n");
        printf("ѡ�� A ����ֵ: %.2lf\nѡ�� B ����ֵ: %.2lf\nģ�����: %d\n\n", hisAbility[i][0],
               hisAbility[i][1], hisN[i]);
        printf("ģ����Ϊ:\nѡ�� A ��ʤ %d ������, ռ�� %.2lf\nѡ�� B ��ʤ %d ��������ռ�� %.2lf\n", hisWin1[i],
               hisWin1[0] * 1.0 / hisN[i], hisN[i] - hisWin1[i], (hisN[i] - hisWin1[i]) * 1.0 / hisN[i]);
        printf("-------------------\n\n");
    }
    getchar();
}

void input(double ability[], int *n) {
    printf("������ѡ�� A ������ֵ (0-1): ");
    scanf("%lf", &ability[0]);
    printf("������ѡ�� B ������ֵ (0-1): ");
    scanf("%lf", &ability[1]);
    printf("ģ������ĳ���: ");
    scanf("%d", n);
    if (ability[0] + ability[1] <= 0 || n <= 0) {
        printf("INVALID INPUT");
        getchar();
        getchar();
        exit(0);
    }
}
