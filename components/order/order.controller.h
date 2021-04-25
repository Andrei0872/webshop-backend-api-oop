#include "order.service.h"

class OrderController {
  private:
    OrderService orderService;
  
  public:
    OrderController(ProductService& ps, UserService& us): orderService(ps, us) {};

    void insertOrder (nlohmann::json body) {
      // TODO: try catch
      try {
        orderService.insertOrder(body);

        // return ""
      } catch (string err) {
        // return "[ERROR]: " + err;
        cout << err << '\n';
      }
    }
};