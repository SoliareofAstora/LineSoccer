#include <string>
#include <iostream>

static void out(std::string message) {
  std::cerr << message;
}

static void out(int number) {
  std::cerr << std::to_string(number);
}

static void outln() {
  std::cerr << std::endl;
}

static void outln(std::string message) {
  std::cerr << message << std::endl;
}

static void outtab(std::string message) {
  std::cerr << "\t" << message << std::endl;
}

