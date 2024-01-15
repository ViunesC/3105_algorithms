//
// Created by Re_Innocence on 2024/1/15.
//

#include "stableMatching.h"

namespace stableMatching {
    stableMatching::stableMatching(int n, int **mp, int **wp) {
        this->N = n;
        this->man_pref = mp;
        this->woman_pref = wp;

        candidate_currMatch = new int[N*2];
        man_NextPropose = new int[N];
    }

    void stableMatching::gale_shapley() {
        // Initialization, at beginning all men and women are available
        bool isManAvailable = true;
        int nextMan = 0;

        while (isManAvailable) {
            isManAvailable = false;

            purpose(nextMan);

        }

    }

    stableMatching::~stableMatching() {
        // TODO: delete each 2D dynamic array row by row
        /* delete man_pref;
        delete woman_pref;*/
        delete candidate_currMatch;
        delete man_NextPropose;
    }

    void stableMatching::purpose(int candidate) {
        // if candidate is matched, throw an error
        if (candidate_currMatch[candidate] != -1) {
            std::cout << "The candidate have already been matched" << std::endl;
            return;
        }

        // check if candidate's next purposed women have been matched or not
        if (candidate_currMatch[man_NextPropose[candidate] + N] == -1) { // if not matched
            candidate_currMatch[man_NextPropose[candidate] + N] = candidate;
            candidate_currMatch[candidate] = man_NextPropose[candidate];
        } else { // if matched, check partner's preference
            int currPartner = candidate_currMatch[man_NextPropose[candidate] + N];

            if (woman_pref[man_NextPropose[candidate]][currPartner] > woman_pref[man_NextPropose[candidate]][candidate]) {
                // if current partner is more attractive, candidate got rejected
                man_NextPropose[candidate] += 1;
            } else {
                // else woman swap her partner, her ex-partner got rejected and become free
                candidate_currMatch[man_NextPropose[candidate] + N] = candidate;
                candidate_currMatch[candidate] = man_NextPropose[candidate];

                candidate_currMatch[currPartner] = -1;
                man_NextPropose[currPartner] += 1;
            }
        }
    }
} // stableMatching