#include "user.repository.h"

using namespace std;

class UserService {
  private:
    UserRepository userRepo;
  
  public:
    UserService() : userRepo() {
      cout << "USER SERVICE INIT\n";
    };

    void getAll () {}
};