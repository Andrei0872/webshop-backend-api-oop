#include "user.service.h"
#include <map>

using namespace std;

class UserController {
  private:
    UserService userService;

  public:
    UserController(): userService() {
      cout << "USER CONTROLLER INIT \n";
    };

    vector<User> getAll () {
      return userService.getAll();
    }

    User getById (int userId) {
      return userService.getById(userId);
    }

    void insertUser (CliInput rawUser) {
      // TODO: insert data from terminal
      bool ok = userService.insertUser(rawUser);
    }
};