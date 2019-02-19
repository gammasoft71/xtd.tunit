#include <xtd/tunit>
#include <vector>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      vector v = {1, 2, 3, 4};
      assert::throws_(std::out_of_range, [&] {v.at(5);});
    }
    
    void test_method_(test_case_failed) {
      vector v = {1, 2, 3, 4};
      assert::throws_(std::out_of_range, [&] {v.at(2);});
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
//   Start 2 tests from test
//     PASSED test_case_succeed (0 ms total)
//     FAILED test_case_failed (4 ms total)
//
// Expected: <std::out_of_range>
// But was:  <nothing>
// error: !---OMITTED---!/xtd/xtd.tunit/examples/assert_does_not_throw/src/assert_throws.cpp:17
//
//   End 2 tests from test (4 ms total)
//
//   Summary :
//     PASSED 1 test.
// *** FAILED 1 test, listed below:
// *** FAILED test.test_case_failed
//
//     FAILED 1 test.
// End 2 tests from 1 test case ran. (4 ms total)