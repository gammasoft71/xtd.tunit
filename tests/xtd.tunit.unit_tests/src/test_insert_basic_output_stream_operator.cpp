#include "assert_unit_tests.hpp"
#include <xtd/tunit>
#include <array>
#include <deque>
#include <exception>
#include <forward_list>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#if !__APPLE__ || __MAC_OS_X_VERSION_MAX_ALLOWED >= 101401
#include <optional>
#endif
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace unit_tests {
  void test_(test_insert_basic_output_stream_operator, test_bool) {
    bool b = true;
    std::stringstream ss;
    ss << std::boolalpha << b;
    assert_value_("true", ss.str());
    ss.str("");
    ss << std::noboolalpha << b;
    assert_value_("1", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_int) {
    int i = 42;
    std::stringstream ss;
    ss << i;
    assert_value_("42", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_pointer_int) {
    int i = 42;
    int* p = &i;
    std::stringstream ss;
    ss << p;
    assert_value_(0, ss.str().find("0x"));
  }
  
  void test_(test_insert_basic_output_stream_operator, test_const_pointer_int) {
    int i = 42;
    const int* p = &i;
    std::stringstream ss;
    ss << p;
    assert_value_(0, ss.str().find("0x"));
  }
  
  void test_(test_insert_basic_output_stream_operator, test_unique_ptr) {
    auto p = std::make_unique<int>(42);
    std::stringstream ss;
    ss << p;
    assert_value_(0, ss.str().find("0x"));
  }
  
  void test_(test_insert_basic_output_stream_operator, test_shared_ptr) {
    auto p = std::make_shared<int>(42);
    std::stringstream ss;
    ss << p;
    assert_value_(0, ss.str().find("0x"));
  }

  void test_(test_insert_basic_output_stream_operator, test_const_char_pointer) {
    const char* s = "42";
    std::stringstream ss;
    ss << s;
    assert_value_("42", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_string) {
    std::string s = "42";
    std::stringstream ss;
    ss << s;
    assert_value_("42", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_exception) {
    std::exception e;
    std::stringstream ss;
    ss << e;
    assert_value_("exception: std::exception", ss.str());
  }
  
#if !__APPLE__ || __MAC_OS_X_VERSION_MAX_ALLOWED >= 101401
  void test_(test_insert_basic_output_stream_operator, test_optional_without_value) {
    std::optional<int> o;
    std::stringstream ss;
    ss << o;
    assert_value_("(null)", ss.str());
  }
#endif
  
  void test_(test_insert_basic_output_stream_operator, test_optional_with_value) {
    std::optional<int> o = 42;
    std::stringstream ss;
    ss << o;
    assert_value_("(42)", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_pair) {
    auto p = std::make_pair("string", 42);
    std::stringstream ss;
    ss << p;
    assert_value_("(\"string\", 42)", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_tuple_empty) {
    auto t = std::make_tuple();
    std::stringstream ss;
    ss << t;
    assert_value_("()", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_tuple) {
    auto t = std::make_tuple("string", 42);
    std::stringstream ss;
    ss << t;
    assert_value_("(\"string\", 42)", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_array) {
    std::array<int, 4> a = {1, 2, 3, 4};
    std::stringstream ss;
    ss << a;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_array_with_const_char_pointer) {
    std::array<const char*, 4> a = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << a;
    assert_value_("[\"1\", \"2\", \"3\", \"4\"]", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_array_with_string) {
    std::array<std::string, 4> a = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << a;
    assert_value_("[\"1\", \"2\", \"3\", \"4\"]", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_deque) {
    std::deque d = {1, 2, 3, 4};
    std::stringstream ss;
    ss << d;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_deque_with_const_char_pointer) {
    std::deque d = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << d;
    assert_value_("[\"1\", \"2\", \"3\", \"4\"]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_deque_with_string) {
    std::deque<std::string> d = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << d;
    assert_value_("[\"1\", \"2\", \"3\", \"4\"]", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_forward_list) {
    std::forward_list fl = {1, 2, 3, 4};
    std::stringstream ss;
    ss << fl;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_forward_list_with_const_char_pointer) {
    std::forward_list fl = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << fl;
    assert_value_("[\"1\", \"2\", \"3\", \"4\"]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_forward_list_with_string) {
    std::forward_list<std::string> fl = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << fl;
    assert_value_("[\"1\", \"2\", \"3\", \"4\"]", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_List) {
    std::list l = {1, 2, 3, 4};
    std::stringstream ss;
    ss << l;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_list_with_const_char_pointer) {
    std::list l = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << l;
    assert_value_("[\"1\", \"2\", \"3\", \"4\"]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_list_with_string) {
    std::list<std::string> l = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << l;
    assert_value_("[\"1\", \"2\", \"3\", \"4\"]", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_vector) {
    std::vector v = {1, 2, 3, 4};
    std::stringstream ss;
    ss << v;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_vector_with_const_char_pointer) {
    std::vector v = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << v;
    assert_value_("[\"1\", \"2\", \"3\", \"4\"]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_vector_with_string) {
    std::vector<std::string> v = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << v;
    assert_value_("[\"1\", \"2\", \"3\", \"4\"]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_map) {
    std::map<int, int> m = {{1, 10}, {2, 20}, {3, 30}, {4, 40}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, 10), (2, 20), (3, 30), (4, 40)}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_map_with_const_char_pointer) {
    std::map<int, const char*> m = {{1, "10"}, {2, "20"}, {3, "30"}, {4, "40"}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, \"10\"), (2, \"20\"), (3, \"30\"), (4, \"40\")}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_map_with_string) {
    std::map<int, std::string> m = {{1, "10"}, {2, "20"}, {3, "30"}, {4, "40"}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, \"10\"), (2, \"20\"), (3, \"30\"), (4, \"40\")}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_multimap) {
    std::multimap<int, int> m = {{1, 10}, {2, 20}, {3, 30}, {4, 40}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, 10), (2, 20), (3, 30), (4, 40)}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_multimap_with_const_char_pointer) {
    std::multimap<int, const char*> m = {{1, "10"}, {2, "20"}, {3, "30"}, {4, "40"}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, \"10\"), (2, \"20\"), (3, \"30\"), (4, \"40\")}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_multimap_with_string) {
    std::multimap<int, std::string> m = {{1, "10"}, {2, "20"}, {3, "30"}, {4, "40"}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, \"10\"), (2, \"20\"), (3, \"30\"), (4, \"40\")}", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_multiset) {
    std::multiset s = {1, 2, 3, 4};
    std::stringstream ss;
    ss << s;
    assert_value_("{1, 2, 3, 4}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_multiset_with_const_char_pointer) {
    std::multiset s = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << s;
    assert_value_("{\"1\", \"2\", \"3\", \"4\"}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_multiset_with_string) {
    std::multiset<std::string> s = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << s;
    assert_value_("{\"1\", \"2\", \"3\", \"4\"}", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_set) {
    std::set s = {1, 2, 3, 4};
    std::stringstream ss;
    ss << s;
    assert_value_("{1, 2, 3, 4}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_set_with_const_char_pointer) {
    std::set s = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << s;
    assert_value_("{\"1\", \"2\", \"3\", \"4\"}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_set_with_string) {
    std::set<std::string> s = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << s;
    assert_value_("{\"1\", \"2\", \"3\", \"4\"}", ss.str());
  }
}