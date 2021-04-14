#include <iostream>

#include "./dependencies/http/httplib.h"
#include "./dependencies/json/single_include/nlohmann/json.hpp"

#include "./utils/types.h"
#include "./components/product/product.entity.h"
#include "./db/drivers/memory.driver.h"

#include "./components/user/user.controller.h"

using namespace std;
using json = nlohmann::json;

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

  // userController.getAll();

  // auto u = userController.getById(1);
  // cout << u;

  // rawUser.clear();
  // rawUser.insert({ "firstName", "ANDREI" });
  // userController.updateUser(1, rawUser);

  userController.deleteUser(1);
  userController.deleteUser(3);
  // userController.deleteUser(4);
  // userController.deleteUser(2);
  // userController.deleteUser(100);
  userController.getAll();

  auto j3 = json::parse(R"({"happy": true, "pi": 3.141})");
  cout << j3.at("happy") << '\n';

  httplib::Server svr;

  svr.Get("/hi", [](const httplib::Request &req, httplib::Response &res) {
    cout << req.body;
    res.set_content("Hello World!", "text/plain");
  });

  svr.Post("/user", [](const httplib::Request &req, httplib::Response &res) {
    cout << req.body;
    auto parsed = json::parse(req.body);
    res.set_content(req.body + " " + to_string(parsed.at("key1")), "text/plain");
  });

  svr.listen("0.0.0.0", 8080);

  delete memoryDriver;
}