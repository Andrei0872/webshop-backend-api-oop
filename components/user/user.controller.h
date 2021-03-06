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
      try { 
        auto users = userService.getAll(true);

        *this << users;
      } catch (char const* e) {
        cout << e << '\n';
      }

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

    void updateUser (int userId, CliInput newUser) {
      auto updatedUser = userService.updateUser(userId, newUser);

      cout << "\nUPDATED USER:";
      cout << updatedUser;
    }

    void deleteUser (int userId) {
      bool successfullyDeleted = userService.deleteUser(userId);

      string message;

      if (successfullyDeleted) {
        message = "Successfully deleted ";
      } else {
        message = "There was a problem deleting the ";
      }

      message += "user with id=" + to_string(userId);

      cout << message << '\n';
    }

    UserService& getUserService () {
      return userService;
    }
};