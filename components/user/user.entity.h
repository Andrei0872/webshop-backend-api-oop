#pragma once

#include <string>
#include <functional>
#include <algorithm>
#include "../../utils/types.h"

using namespace std;

class User : virtual public Entity {
  private:
    int id;
    string firstName;
    string lastName;
    string country;

    vector<string> properties{"firstName", "lastName", "country"};

  protected:
    virtual vector<reference_wrapper<string>> getPropsAsRefs () {
      vector<reference_wrapper<string>> propsRefs{firstName, lastName, country};
      return propsRefs;
    }

  public:
    User (int id, string fName, string lName, string country)
      : id(id), firstName(fName), lastName(lName), country(country) {}

    friend ostream& operator << (ostream& os, User u) {
      os << u.serialize();

      return os;
    }

    virtual int getId () {
      return id;
    }

    // Used when asking for values in CLI
    virtual vector<string> getProperties () {
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

    void updateOne (User newUser) {
      for (size_t i = 0; i < users.size(); i++) {
        auto crtUser = users[i];
        users[i] = crtUser.getId() == newUser.getId() ? newUser : crtUser;
      }
    }

    void deleteOne (int userId) {
      if (!users.size()) {
        throw string("There are no more users - nothing to delete");
      }
      
      auto it = remove_if(
        users.begin(),
        users.end(),
        [&, userId](User u) {
          return u.getId() == userId;
        }
      );

      if (it == users.end()) {
        string errorMsg = "The user with id=";
        errorMsg += to_string(userId) + "does not exist!";

        throw errorMsg;
      }

      users.erase(it, users.end());
    }
};