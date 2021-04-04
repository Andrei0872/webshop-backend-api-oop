#include <iostream>

#include "../../utils/types.h"
#include "user.entity.h"

#include <vector>

using namespace std;

class UserRepository : public Repository {
  private:
    UserTable* userTable;
  
  public:
    UserRepository(): Repository() {
      cout << "USER REPO \n";
      
      userTable = new UserTable("user");
      
      setTable("user", userTable);
    };
  
    vector<User> selectAll () {
      return userTable->selectAll();
    };

    bool insertUser (User u) {
      userTable->insertOne(u);

      return true;
    }

    bool updateUser (User u) {
      userTable->updateOne(u);

      return true;
    }

    bool deleteUser (int userId) {
      try {
        userTable->deleteOne(userId);
      } catch (string msg) {
        cout << msg << '\n';
        return false;
      }

      return true;
    }
};