#include "user.service.h"

using namespace std;

class UserController {
  private:
    UserService userService;

  public:
    UserController(): userService() {
      cout << "USER CONTROLLER INIT \n";
    };

    void getAll () {};
};