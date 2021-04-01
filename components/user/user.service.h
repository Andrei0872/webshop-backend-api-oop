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

    template <
      typename Serialize,
      typename T = enable_if<is_same<Serialize, bool>{}>
    >
    vector<string> getAll (Serialize) {
      auto users = userRepo.selectAll();
      vector<string> serializedUsers;

      serializedUsers.resize(users.size());

      transform(
        users.begin(), 
        users.end(), 
        serializedUsers.begin(),
        [](User &u) -> string { return u.serialize(); }
      );

      return serializedUsers;
    }

    vector<User> getAll() {
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