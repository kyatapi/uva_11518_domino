#include "test_cases.h"
#include <sstream>

using namespace std;

extern size_t proceed_domino_show(istream& iss);

TEST(DominoShow, HandleNoToppling) {
    istringstream iss("3 0 0");
    ASSERT_EQ(proceed_domino_show(iss), 0);
}
