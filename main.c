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
    printf("这个程序模拟两个选手 A 和 B 的某种竞技比赛\n");
    printf("程序运行需要 A 和 B 的能力值（以 0 和 1 之间的小数表示）\n");
    double ability[2];
    int n;
    input(ability, &n);
    int win1 = simulate(ability, n);
    int win2 = n - win1;
    printf("选手 A 获胜 %d 场比赛，占比 %.2lf\n", win1, win1 * 1.0 / n);
    printf("选手 A 获胜 %d 场比赛，占比 %.2lf\n", win2, win2 * 1.0 / n);
    getchar();
    getchar();
}

void input(double ability[], int *n) {
    printf("请输入选手 A 的能力值 (0-1): ");
    scanf("%lf", &ability[0]);
    printf("请输入选手 B 的能力值 (0-1): ");
    scanf("%lf", &ability[1]);
    printf("模拟比赛的场次: ");
    scanf("%d", n);
}
