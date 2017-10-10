#include "test_cases.h"
#include <sstream>

using namespace std;

extern size_t proceed_domino_show(istream& iss);

TEST(DominoShow, HandleEmpty) {
    istringstream iss("0 0 0");
    ASSERT_EQ(proceed_domino_show(iss), 0);
}

TEST(DominoShow, HandleNoRelation) {
    istringstream iss("3 0 1\n"
                               "1");
    ASSERT_EQ(proceed_domino_show(iss), 1);

    iss.clear();
    iss.str("10 0 3\n"
              "1\n"
              "4\n"
              "7");
    ASSERT_EQ(proceed_domino_show(iss), 3);
}
