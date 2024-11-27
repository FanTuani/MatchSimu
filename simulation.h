#ifndef MATCHSIMU_SIMULATION_H
#define MATCHSIMU_SIMULATION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int simulateOnce(const double ability[]) {
    int score1 = 0, score2 = 0;
    int first = 0;
    while (score1 < 15 && score2 < 15) {
        if ((rand() / (double)RAND_MAX) < ability[first]) {
            if (first == 0) {
                score1++;
            } else {
                score2++;
            }
        } else {
            first ^= 1;
        }
    }
    return (score1 == 15) ? 1 : 0;
}

int simulate(const double ability[], int n) {
    printf("simulating...\n");
    int win1 = 0;
    while(n--) {
        win1 += simulateOnce(ability);
    }
    return win1;
}

#endif //MATCHSIMU_SIMULATION_H
