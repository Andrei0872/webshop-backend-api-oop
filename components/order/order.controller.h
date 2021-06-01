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

    void readOrders () {
      auto orders = orderService.getAll();
      for_each(orders.begin(), orders.end(), [](Order o) {
        cout << o << "\n\n";
      });
    }

    void readOrder (int orderId) {
      try {
        Order o = orderService.getOne(orderId);
        cout << o << '\n';
      } catch (OrderNotFound err) {
        cout << err.getMessage() << '\n';
      }
    }
};