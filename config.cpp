#include <iostream>
#include <string>

using namespace std;

struct Config {
  string DB_HOST = getenv("DB_HOST");
  string DB_NAME = getenv("DB_NAME");
  string DB_USER = getenv("DB_USER");
  string DB_PASSWORD = getenv("DB_PASSWORD");
} config;
