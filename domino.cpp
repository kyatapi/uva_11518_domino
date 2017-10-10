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

    void proceed() {}
    size_t number_of_fall() { return fallen_dominoes.size(); }

    friend istream & operator >> (istream &is, DominoShow &rhs);

private:
    set<size_t> fallen_dominoes;
};

istream & operator >> (istream &is, DominoShow &rhs) {
    int domino_count = 0, relation_count = 0, toppling_count = 0;
    is >> domino_count >> relation_count >> toppling_count;
    for (; relation_count > 0; --relation_count) {
        size_t the_former = 0, the_later = 0;
        is >> the_former >> the_later;
    }

    for (; toppling_count > 0; --toppling_count) {
        size_t toppled = 0;
        is >> toppled;
        rhs.fallen_dominoes.insert(toppled);
    }

    return is;
}

size_t proceed_domino_show(istream& iss) {
    DominoShow show;
    iss >> show;
    show.proceed();
    return show.number_of_fall();
}

int main(int argc, char** argv) {
    run_test(argc, argv);

    size_t number_of_show = 0;
    for (cin >> number_of_show; number_of_show >= 0; --number_of_show) {
        cout << proceed_domino_show(cin) << endl;
    }

    return 0;
}