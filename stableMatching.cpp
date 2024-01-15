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
        for (int i=0;i<N*2;++i) {
            candidate_currMatch[i] = -1;
        }

        for (int j=0;j<N;++j) {
            man_NextPropose[j] = 0;
        }

        // Run the algorithm until all man and woman are paired
        while (isManAvailable) {
            isManAvailable = false;

            purpose(nextMan);

            for (int i=0;i<N;++i) {
                if (candidate_currMatch[i] == -1) {
                    isManAvailable = true;
                    nextMan = i;
                }
            }
        }

        // Print the result to console
        for (int r=0;r<N;++r) {
            std::cout << "Man " << r+1 << " paired with woman " << candidate_currMatch[r]+1 << std::endl;
        }
    }

    stableMatching::~stableMatching() {
        delete[] candidate_currMatch;
        delete[] man_NextPropose;

        for (int i=0;i<N;++i) {
            delete[] man_pref[i];
            delete[] woman_pref[i];
        }
        delete[] man_pref;
        delete[] woman_pref;
    }

    void stableMatching::purpose(int candidate) {
        // if candidate is matched, throw an error
        if (candidate_currMatch[candidate] != -1) {
            std::cout << "The candidate have already been matched" << std::endl;
            return;
        }

        // find the next proposing woman by next preference
        int nextProposal;
        for (int i=0;i<N;++i) {
            if (man_pref[candidate][i] == man_NextPropose[candidate]) {
                nextProposal = i;
                break;
            }
        }

        // check if candidate's next purposed women have been matched or not
        if (candidate_currMatch[nextProposal + N] == -1) { // if not matched
            candidate_currMatch[nextProposal + N] = candidate;
            candidate_currMatch[candidate] = nextProposal;
        } else { // if matched, check partner's preference
            int currPartner = candidate_currMatch[nextProposal + N];

            if (woman_pref[nextProposal][currPartner] < woman_pref[nextProposal][candidate]) {
                // if current partner is more attractive, candidate got rejected
                man_NextPropose[candidate] += 1;
            } else {
                // else woman swap her partner, her ex-partner got rejected and become free
                candidate_currMatch[nextProposal + N] = candidate;
                candidate_currMatch[candidate] = nextProposal;

                candidate_currMatch[currPartner] = -1;
                man_NextPropose[currPartner] += 1;
            }
        }
    }
} // stableMatching