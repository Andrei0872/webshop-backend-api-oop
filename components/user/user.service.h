#include "user.repository.h"

#include <algorithm>

using namespace std;

// TODO: keep track of user ids

class UserService {
  private:
    UserRepository userRepo;
    int crtUserId = 0;
  
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

    bool insertUser (CliInput rawUser) {
      User newUser(
        // stoi(rawUser.at("id")),
        crtUserId++,
        rawUser.at("fName"),
        rawUser.at("lName"),
        rawUser.at("country")
      );
      
      return userRepo.insertUser(newUser);
    }
};