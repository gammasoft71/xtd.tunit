/// @file
/// @brief Contains xtd::console_unit_test class.
#pragma once
#include "unit_test.hpp"
#include <iostream>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The TUnit namespace contains a unit test framework.
  namespace tunit {
    /// @brief The console_unit_test class.
    class console_unit_test : public unit_test {
    public:
      console_unit_test() = default;
      
      console_unit_test(char* argv[], int argc) : unit_test(argv, argc) {}
      
      void on_unit_test_end(const xtd::event_args& e) override {
        this->unit_test::on_unit_test_end(e);
        std::cout << "End " << this->test_count() << " tests from " << this->test_cases_count() << " test case ran. (" << std::chrono::duration_cast<std::chrono::milliseconds>(this->elapsed_time()).count() << " ms total)" << std::endl;
      }
      
      void on_unit_test_start(const xtd::event_args& e) override {
        std::cout << "Start " << this->test_count() << " tests from " << this->test_cases_count() << " test cases" << std::endl;
        this->unit_test::on_unit_test_start(e);
      }
    };
  }
}