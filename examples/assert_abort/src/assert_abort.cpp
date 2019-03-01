#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_aborted) {
      assert::abort();
      assert::is_true(false);
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code produces the following output:
//
// Start 1 test from 1 test case
// Run tests:
//   ABORTED test.test_case_aborted (0 ms total)
//     Test aborted
//
// Test results:
//   ABORTED 1 test.
// End 1 test from 1 test case ran. (0 ms total)