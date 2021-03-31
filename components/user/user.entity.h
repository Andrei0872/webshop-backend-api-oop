#pragma once

#include <string>
#include "../../utils/types.h"

using namespace std;

class User : virtual public Entity {
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

    // Used when asking for values in CLI
    virtual vector<string> getProperties () {
      vector<string> properties;

      properties.push_back("firstName");
      properties.push_back("lastName");
      properties.push_back("country");

      return properties;
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