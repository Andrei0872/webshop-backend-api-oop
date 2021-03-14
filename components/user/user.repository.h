#include <iostream>

#include "../../utils/types.h"

#include <vector>

using namespace std;

class UserRepository : public Repository {
  private:
    UserTable* userTable;
  
  public:
    UserRepository(): Repository() {
      userTable = new UserTable("user");
      
      setTable("user", userTable);

      User u;

      userTable->insertOne(u);

      // auto r = userTable->selectAll().size();

      // cout << r;
    };
  
    vector<User> selectAll () {
      return userTable->selectAll();
    };
};