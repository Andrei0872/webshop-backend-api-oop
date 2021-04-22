#include <iostream>

// #include "./dependencies/http/httplib.h"
// #include "./dependencies/json/single_include/nlohmann/json.hpp"

#include "./utils/types.h"

#include "./db/db.h"
#include "./db/drivers/memory.driver.h"

#include "./components/user/user.controller.h"
#include "./components/product/product.controller.h"
#include "./components/order/order.controller.h"


using namespace std;
// using json = nlohmann::json;

int main () {
  MemoryDriver* memoryDriver = new MemoryDriver();
  Database::getInstance().setDriver(memoryDriver);
  // Database::getInstance().printDriverId();

  // Normally, this would be an async action
  // but in case we're just using the MemoryDriver
  // which does not require any async actions
  Database::getInstance().connect();

  auto tempUserStuff = []() {
    UserController userController;

    CliInput rawUser;
    rawUser.insert({"firstName", "Andrei"});
    rawUser.insert({"lastName", "Gatej"});
    rawUser.insert({"country", "RO"});
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
  };

  auto tempProductStuff = []() {
    ProductController productController;

    CliInput rawProduct;
    rawProduct.insert({"name", "product_1"});
    rawProduct.insert({"price", "120"});
    productController.insertProduct(rawProduct);
  
    rawProduct.clear();

    rawProduct.insert({"name", "product_2"});
    rawProduct.insert({"price", "200"});
    productController.insertProduct(rawProduct);

    rawProduct.clear();

    rawProduct.insert({"name", "product_3"});
    rawProduct.insert({"price", "119"});
    productController.insertProduct(rawProduct);

    // productController.getAll();

    // auto p = productController.getById(1);
    // cout << p;

    // rawProduct.clear();
    // rawProduct.insert({ "price", "99999" });
    // productController.updateProduct(1, rawProduct);

    // productController.getAll();

    productController.deleteProduct(1);
    productController.deleteProduct(3);
    // productController.deleteProduct(4);
    // productController.deleteProduct(2);
    // productController.deleteProduct(100);
    productController.getAll();
  };

  auto tempOrderStuff = []() {
    // Req.body type: { userId, productId, quantity }
    //  Check if `userId` & `productId` exist
    //  Check if the `product` exists already

    //  Add the product to the list
    //  Remove the product from the list
    //  Update product's quantity
    //  Show all the products from the order that belong to a user

    ProductController productController;
    UserController userController;

    OrderController orderController(productController.getProductService(), userController.getUserService());
  };

  tempOrderStuff();

  // auto j3 = json::parse(R"({"happy": true, "pi": 3.141})");
  // cout << j3.at("happy") << '\n';

  // httplib::Server svr;

  // svr.Get("/hi", [](const httplib::Request &req, httplib::Response &res) {
  //   cout << req.body;
  //   res.set_content("Hello World!", "text/plain");
  // });

  // svr.Post("/user", [](const httplib::Request &req, httplib::Response &res) {
  //   cout << req.body;
  //   auto parsed = json::parse(req.body);
  //   res.set_content(req.body + " " + to_string(parsed.at("key1")), "text/plain");
  // });

  // svr.listen("127.0.0.1", 5000);

  delete memoryDriver;
}