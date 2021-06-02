#include <iostream>

// #include "./dependencies/http/httplib.h"
#include "./dependencies/json/single_include/nlohmann/json.hpp"

#include "./utils/observables.h"

#include "./utils/types.h"

#include "./db/db.h"
#include "./db/drivers/memory.driver.h"

#include "./components/user/user.controller.h"
#include "./components/product/product.controller.h"
#include "./components/order/order.controller.h"

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

  ProductController productController;
  UserController userController;
  OrderController orderController(productController.getProductService(), userController.getUserService());

  // User CRUD
  cout << "\n-------------USER------------- \n";
  // Create
  cout << "\n\t CREATE: \n";
  CliInput rawUser;
  rawUser.insert({"firstName", "Andrei"});
  rawUser.insert({"lastName", "Gatej"});
  rawUser.insert({"country", "RO"});
  userController.insertUser(rawUser);
  rawUser.clear();
  rawUser.insert({"firstName", "Jane"});
  rawUser.insert({"lastName", "Doe"});
  rawUser.insert({"country", "DE"});
  userController.insertUser(rawUser);
  // Read
  cout << "\n\t READ: \n";
  userController.getAll();
  cout << "User with ID = 1: " << userController.getById(1);
  // Update
  cout << "\n\t UPDATE: \n";
  rawUser.clear();
  rawUser.insert({ "firstName", "ANDREI" });
  userController.updateUser(1, rawUser);
  cout << "User with ID = 1: " << userController.getById(1);
  // Delete
  cout << "\n\t DELETE: \n";
  userController.deleteUser(1);
  cout << "\nUser list after deleting the user with id 1: \n";
  userController.getAll();

  // Product CRUD
  cout << "\n\n-------------PRODUCT------------- \n";
  // Create
  cout << "\n\t CREATE: \n";
  CliInput rawProduct;
  rawProduct.insert({"name", "product_1"});
  rawProduct.insert({"price", "120"});
  productController.insertProduct(rawProduct);
  rawProduct.clear();
  rawProduct.insert({"name", "product2"});
  rawProduct.insert({"price", "60"});
  productController.insertProduct(rawProduct);
  rawProduct.clear();
  rawProduct.insert({"name", "product3"});
  rawProduct.insert({"price", "15"});
  productController.insertProduct(rawProduct);
  rawProduct.clear();
  rawProduct.insert({"name", "product4"});
  rawProduct.insert({"price", "30"});
  productController.insertProduct(rawProduct);
  rawProduct.clear();
  rawProduct.insert({"name", "product5"});
  rawProduct.insert({"price", "50"});
  productController.insertProduct(rawProduct);
  // Read
  cout << "\n\t READ: \n";
  productController.getAll();
  cout << "Product with ID = 1: " << productController.getById(1) << '\n';
  cout << "Product with ID = 2: " << productController.getById(2);
  // Update
  cout << "\n\t UPDATE: \n";
  rawProduct.clear();
  rawProduct.insert({ "name", "PRODUCT_1" });
  productController.updateProduct(1, rawProduct);
  cout << "Product with ID = 1 AFTER update: " << productController.getById(1) << '\n';
  // Delete
  cout << "\n\t DELETE: \n";
  productController.deleteProduct(1);
  productController.deleteProduct(2);
  cout << "\nProduct list after deleting the products with id 1 and 2: \n";
  productController.getAll();

  // Order CRUD
  cout << "\n\n-------------ORDER------------- \n";
  // Create
  cout << "\n\t CREATE: \n";
  auto body = json::parse(R"({"userId":2,"productsInfo":[{"productId":3,"quantity":2},{"productId":4,"quantity":10}]})");
  orderController.insertOrder(body);
  body = json::parse(R"({"userId":2,"productsInfo":[{"productId":3,"quantity":2},{"productId":4,"quantity":10}, {"productId":5,"quantity":20}]})");
  orderController.insertOrder(body);
  // Read
  cout << "\n\t READ: \n";
  cout << "Orders list: \n";
  orderController.readOrders();
  cout << "The order with ID = 1: \n";
  orderController.readOrder(1);
  cout << "The order with ID = 2: ";
  orderController.readOrder(2);
  // Delete
  cout << "\n\t DELETE: \n";
  // Trying to delete an unexisting order
  orderController.deleteOrder(3);
  orderController.deleteOrder(1);
  cout << "Orders list after deleting the order with ID = 1: \n";
  orderController.readOrders();
  // The `Observer` pattern applied
  // orderController.readOrders();
  cout << "\n\t DELETING the product with ID = 4 - it will dissapear from the existing orders too: \n";
  productController.deleteProduct(4);
  cout << "Orders list after deleting the PRODUCT with ID = 4: \n";
  orderController.readOrders();

  delete memoryDriver;
}