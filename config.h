#pragma once

#include <iostream>
#include <string>

using namespace std;

class Config {
  private:
    string DB_HOST;
    string DB_NAME;
    string DB_USER;
    string DB_PASSWORD;

  public:
    Config () {
      DB_HOST = getenv("DB_HOST");
      DB_NAME = getenv("DB_NAME");
      DB_USER = getenv("DB_USER");
      DB_PASSWORD = getenv("DB_PASSWORD");
    }
  
    string getDBHost () {
      return DB_HOST;
    }

    string getDBName () {
      return DB_NAME;
    }

    string getDBUser () {
      return DB_USER;
    }
};