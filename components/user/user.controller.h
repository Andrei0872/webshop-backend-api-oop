#include "user.service.h"
#include <map>
#include <algorithm>

using namespace std;

class UserController {
  private:
    UserService userService;

  public:
    UserController(): userService() {
      cout << "USER CONTROLLER INIT \n";
    };

    void operator<< (const vector<string>& serializedUsers) {
      for_each(serializedUsers.begin(), serializedUsers.end(), [](string u) { cout << u << "\n\n"; });
      
      return;
    }

    void getAll () {
      auto users = userService.getAll(true);

      *this << users;
    }

    User getById (int userId) {
      return userService.getById(userId);
    }

    void insertUser (CliInput rawUser) {
        // TODO: throw & catch error
      bool ok = userService.insertUser(rawUser);

      if (!ok) {
        return;
      }

      cout << "The user has been successfully added. \n";
    }
};