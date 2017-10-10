#ifndef ONLINE_JUDGE
#include "test_cases.h"
extern void run_test(int argc, char **argv);
#else
inline void run_test(int argc, char **argv) {}
#endif // !ONLINE_JUDGE

#include <sstream>
#include <set>

using namespace std;

class DominoShow {
public:
    DominoShow() {}
    ~DominoShow() {}

    void proceed();
    size_t number_of_fall() { return fallen_dominoes.size(); }

    friend istream & operator >> (istream &is, DominoShow &rhs);

private:
    set<size_t> fallen_dominoes;
    vector<set<size_t>> relationship;
};

istream & operator >> (istream &is, DominoShow &rhs) {
    int domino_count = 0, relation_count = 0, toppling_count = 0;
    is >> domino_count >> relation_count >> toppling_count;
    rhs.relationship.resize(domino_count);

    for (; relation_count > 0; --relation_count) {
        size_t the_former = 0, the_later = 0;
        is >> the_former >> the_later;
        rhs.relationship[the_former - 1].insert(the_later);
    }

    for (; toppling_count > 0; --toppling_count) {
        size_t toppled = 0;
        is >> toppled;
        rhs.fallen_dominoes.insert(toppled);
    }

    return is;
}

void DominoShow::proceed() {
    set<size_t> candidates = fallen_dominoes;
    while (!candidates.empty()) {
        set<size_t> to_proceed = candidates;
        candidates.clear();
        for (size_t toppled : to_proceed) {
            for (size_t the_later : relationship[toppled - 1]) {
                if (fallen_dominoes.insert(the_later).second) candidates.insert(the_later);
            }
        }
    }
}

size_t proceed_domino_show(istream& iss) {
    DominoShow show;
    iss >> show;
    show.proceed();
    return show.number_of_fall();
}

int main(int argc, char** argv) {
    run_test(argc, argv);

    int number_of_show = 0;
    for (cin >> number_of_show; number_of_show > 0; --number_of_show) {
        cout << proceed_domino_show(cin) << endl;
    }

    return 0;
}