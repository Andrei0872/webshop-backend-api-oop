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
      
      if (!orders.size()) {
        cout << "There are no orders - nothing to print. \n";
        return;
      }
      
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

    void deleteOrder (int orderId) {
      bool ok = orderService.deleteOrder(orderId);

      if (ok) {
        cout << "Successfully deleted the order with id " << orderId << '\n';
      }
    }
};