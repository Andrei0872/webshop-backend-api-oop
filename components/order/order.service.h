#include <string>

#include "order.repository.h"

using namespace std;

class OrderService {
  private:
    ProductService& productService;
    UserService& userService;

    OrderRepository orderRepo;

    bool isBodyValid (nlohmann::json body, string& errMessage) {
      try {
        // Making sure the `user` exists
        int userId = body.at("userId");
        userService.getById(userId);

        // Making sure the all the products exist
        auto productsInfo = body.at("productsInfo");
        for (auto pInfo : productsInfo) {
          productService.getById(pInfo.at("productId"));
        }

      } catch (string err ) {
        errMessage = "\n\n[isBodyValid] ERR: " + err + '\n';
        errMessage += "The given request body: " + to_string(body) + '\n';

        return false;
      }
      
      return true;
    }

  public:
    OrderService(ProductService &ps, UserService &us):
      productService(ps), userService(us), orderRepo() {};

    void insertOrder (nlohmann::json rawBody) {
      string errMessage = "";

      if (!isBodyValid(rawBody, errMessage)) {
        throw errMessage;
      }

      orderRepo.insertOrder(to_string(rawBody.at("userId")), rawBody.at("productsInfo"));
    }
};