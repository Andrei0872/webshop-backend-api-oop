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
  rawUser.insert({ "fName", "Andrei" });
  rawUser.insert({ "lName", "Gatej" });
  rawUser.insert({ "country", "RO" });
  userController.insertUser(rawUser);

  rawUser.clear();

  rawUser.insert({"fName", "John"});
  rawUser.insert({"lName", "Doe"});
  rawUser.insert({"country", "GE"});
  userController.insertUser(rawUser);

  rawUser.clear();

  rawUser.insert({"fName", "Jane"});
  rawUser.insert({"lName", "Doe"});
  rawUser.insert({"country", "BG"});
  userController.insertUser(rawUser);

  userController.getAll();
}