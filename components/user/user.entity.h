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

  public:
    User (int id, string fName, string lName, string country)
      : id(id), firstName(fName), lastName(lName), country(country) {}

    int getId () const {
      return id;
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