#include <iostream>

#include "./utils/types.h"
#include "./components/product/product.entity.h"
#include "./db/drivers/memory.driver.h"

#include "./components/user/user.controller.h"

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
}