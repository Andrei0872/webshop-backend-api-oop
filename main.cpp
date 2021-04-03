#include <iostream>

#include "./utils/types.h"
#include "./components/product/product.entity.h"
#include "./db/drivers/memory.driver.h"

#include "./components/user/user.controller.h"

// #include "./cli/cli.h"

using namespace std;

int main () {
  MemoryDriver* memoryDriver = new MemoryDriver();
  Database::getInstance().setDriver(memoryDriver);
  // Database::getInstance().printDriverId();

  // Normally, this would be an async action
  // but in case we're just using the MemoryDriver
  // which does not require any async actions
  Database::getInstance().connect();

  UserController userController;

  CliInput rawUser;
  rawUser.insert({ "firstName", "Andrei" });
  rawUser.insert({ "lastName", "Gatej" });
  rawUser.insert({ "country", "RO" });
  userController.insertUser(rawUser);

  rawUser.clear();

  rawUser.insert({"firstName", "John"});
  rawUser.insert({"lastName", "Doe"});
  rawUser.insert({"country", "GE"});
  userController.insertUser(rawUser);

  rawUser.clear();

  rawUser.insert({"firstName", "Jane"});
  rawUser.insert({"lastName", "Doe"});
  rawUser.insert({"country", "BG"});
  userController.insertUser(rawUser);

  userController.getAll();

  // auto u = userController.getById(1);
  // cout << u;

  rawUser.clear();
  rawUser.insert({ "firstName", "ANDREI" });
  userController.updateUser(1, rawUser);

  userController.getAll();
}