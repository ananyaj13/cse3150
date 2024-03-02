#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"


#include <vector>
#include "myfind.h"



TEST_CASE("myfind") {
  
  SUBCASE("Edge cases") {
    std::vector<int> x_0 = {};  
    bool answer = myfind(x_0,99);
    CHECK(false == answer);

    std::vector<int> x_1 = {-17};  
    answer = myfind(x_1, -17);
    CHECK(true == answer);
    answer = myfind(x_1, 555);
    CHECK(false == answer);

  };

  
  SUBCASE("Small cases") {
    std::vector<int> x = {1,5,8,11,25,30,32,47,78,99,101};
    bool foundIt_not = myfind(x,33);
    CHECK(false == foundIt_not);

    bool foundIt_did = myfind(x,x[4]);
    CHECK(true == foundIt_did);

  };
}

