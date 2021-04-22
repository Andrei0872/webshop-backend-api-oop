#include "user.repository.h"

#include <algorithm>

using namespace std;

// TODO: keep track of user ids

class UserService {
  private:
    UserRepository userRepo;
    int crtUserId = 0;

    User createUser (CliInput rawUser, int id = -1) {
      User newUser(
        id == - 1 ? ++crtUserId : id,
        rawUser.at("firstName"),
        rawUser.at("lastName"),
        rawUser.at("country")
      );

      return newUser;
    }

  public:
    UserService() : userRepo() {
      cout << "USER SERVICE INIT\n";
    };

    UserService (const UserService& u) { }

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
          [&userId](User &u) { return u.getId() == userId; });
    }

    // TODO: maybe return User
    bool insertUser (CliInput rawUser) {
      return userRepo.insertUser(createUser(rawUser));
    }

    User updateUser (int userId, CliInput rawUser) {
      auto crtUser = getById(userId);
      auto userProps = crtUser.getProperties();

      // Creating a new user by mergin what's new with what's already there
      for (size_t i = 0; i < userProps.size(); i++) {
        auto prop = userProps[i];

        if (rawUser.find(prop) == rawUser.end()) {
          auto existingVal = crtUser.getPropertyValue(prop);
          rawUser.insert({ prop, existingVal });
        }
      }

      auto newUser = createUser(rawUser, userId);

      userRepo.updateUser(newUser);
      
      return newUser;
    }

    bool deleteUser (int userId) {
      return userRepo.deleteUser(userId);
    }
};