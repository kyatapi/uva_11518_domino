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

TEST(DominoShow, HandleGeneralCase) {
    istringstream iss("3 2 1\n"
        "1 2\n"
        "2 3\n"
        "2");
    ASSERT_EQ(proceed_domino_show(iss), 2);
}

TEST(DominoShow, HandleChainRelationship) {
    istringstream iss("10 17 4\n"
        "1 8\n"
        "1 10\n"
        "3 5\n"
        "3 7\n"
        "3 8\n"
        "4 1\n"
        "4 8\n"
        "5 6\n"
        "6 10\n"
        "7 1\n"
        "7 5\n"
        "8 10\n"
        "9 3\n"
        "10 6\n"
        "10 7\n"
        "10 8\n"
        "10 10\n"
        "10\n"
        "10\n"
        "5\n"
        "10");
    ASSERT_EQ(proceed_domino_show(iss), 6);
}
