#pragma once

#include <string>
#include "../../utils/types.h"

using namespace std;

class User : public Entity {
  private:
    int id;
    string firstName;
    string lastName;
    string country;
    string registered_at;

  public:
    User () {
      firstName = "Andrei";
    }

    string serialize() {
      return firstName;
    }
};

class UserTable : public DBTable {
  private:
    vector<User> users;
  public:
    UserTable(string name): DBTable(name) {};

    vector<User> selectAll () {
      return users;
    }

    void insertOne (User user) {
      users.push_back(user);
    }
};