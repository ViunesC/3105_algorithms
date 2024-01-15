#include <iostream>
#include "stableMatching.h"

int main() {
    // Gale-shapley algorithm
    int N = 3;
    int **mp = new int*[N];
    for (int i=0;i<N;++i) {
        mp[i] = new int[N];
    }

    int **wp = new int*[N];
    for (int r=0;r<N;++r) {
        wp[r] = new int[N];
    }

    mp[0][0] = 2;
    mp[0][1] = 1;
    mp[0][2] = 0;
    mp[1][0] = 2;
    mp[1][1] = 0;
    mp[1][2] = 1;
    mp[2][0] = 2;
    mp[2][1] = 0;
    mp[2][2] = 1;

    wp[0][0] = 2;
    wp[0][1] = 0;
    wp[0][2] = 1;
    wp[1][0] = 1;
    wp[1][1] = 0;
    wp[1][2] = 2;
    wp[2][0] = 2;
    wp[2][1] = 1;
    wp[2][2] = 0;

    stableMatching::stableMatching matching(N, mp, wp);
    matching.gale_shapley();

    for (int i=0;i<N;++i) {
        delete[] mp[i];
        delete[] wp[i];
    }
    delete[] mp;
    delete[] wp;

    return 0;
}
