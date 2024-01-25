//
// Created by Re_Innocence on 2024/1/15.
//

#ifndef INC_3105_ALGORITHMS_STABLEMATCHING_H
#define INC_3105_ALGORITHMS_STABLEMATCHING_H

#include <iostream>

namespace stableMatching {

    class stableMatching {
    private:
        int N;
        int **man_pref;
        int **woman_pref;
        int *candidate_currMatch;
        int *man_NextPropose;
        void purpose(int candidate);
    public:
        stableMatching(int n, int **mp, int **wp);
        ~stableMatching();
        void gale_shapley();
    };

} // stableMatching

#endif //INC_3105_ALGORITHMS_STABLEMATCHING_H
