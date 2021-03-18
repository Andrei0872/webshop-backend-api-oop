#include "user.repository.h"

#include <algorithm>

using namespace std;

class UserService {
  private:
    UserRepository userRepo;
  
  public:
    UserService() : userRepo() {
      cout << "USER SERVICE INIT\n";
    };

    vector<User> getAll () {
      return userRepo.selectAll();
    }

    int getLength () {
      return userRepo.selectAll().size();
    }

    User getById (int userId) {
      auto users = userRepo.selectAll();

      return *find_if(
          users.begin(), users.end(),
          [&userId](const User &u) { return u.getId() == userId; });
    }
};