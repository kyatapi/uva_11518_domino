#ifndef ONLINE_JUDGE
#include "test_cases.h"
extern void run_test(int argc, char **argv);
#else
inline void run_test(int argc, char **argv) {}
#endif // !ONLINE_JUDGE

#include <sstream>

using namespace std;

class DominoShow {
public:
    DominoShow() {}
    ~DominoShow() {}

    void proceed() {}
    size_t number_of_fall() { return 0; }

    friend istream & operator >> (istream &is, DominoShow &rhs);
};

istream & operator >> (istream &is, DominoShow &rhs) {
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