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
    printf("1. 进行竞赛模拟\n");
    printf("2. 查看历史模拟\n");
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
    printf("这个程序模拟两个选手 A 和 B 的某种竞技比赛\n");
    printf("程序运行需要 A 和 B 的能力值（以 0 和 1 之间的小数表示）\n");
    double ability[2];
    int n;
    input(ability, &n);
    int win1 = simulate(ability, n);
    int win2 = n - win1;
    printf("选手 A 获胜 %d 场比赛，占比 %.2lf\n", win1, win1 * 1.0 / n);
    printf("选手 B 获胜 %d 场比赛，占比 %.2lf\n", win2, win2 * 1.0 / n);
    hisN[hisCnt] = n, hisAbility[hisCnt][0] = ability[0], hisAbility[hisCnt][1] = ability[1];
    hisWin1[hisCnt++] = win1;
    getchar();
    getchar();
}

void printHistory() {
    system("cls");
    printf("共有 %d 次历史模拟数据\n\n", hisCnt - 1);
    for (int i = 1; i < hisCnt; i++) {
        printf("第 %d 次模拟情况:\n", i);
        printf("-------------------\n");
        printf("选手 A 能力值: %.2lf\n选手 B 能力值: %.2lf\n模拟次数: %d\n\n", hisAbility[i][0],
               hisAbility[i][1], hisN[i]);
        printf("模拟结果为:\n选手 A 获胜 %d 场比赛, 占比 %.2lf\n选手 B 获胜 %d 场比赛，占比 %.2lf\n", hisWin1[i],
               hisWin1[0] * 1.0 / hisN[i], hisN[i] - hisWin1[i], (hisN[i] - hisWin1[i]) * 1.0 / hisN[i]);
        printf("-------------------\n\n");
    }
    getchar();
}

void input(double ability[], int *n) {
    printf("请输入选手 A 的能力值 (0-1): ");
    scanf("%lf", &ability[0]);
    printf("请输入选手 B 的能力值 (0-1): ");
    scanf("%lf", &ability[1]);
    printf("模拟比赛的场次: ");
    scanf("%d", n);
    if (ability[0] + ability[1] <= 0 || n <= 0) {
        printf("INVALID INPUT");
        getchar();
        getchar();
        exit(0);
    }
}
