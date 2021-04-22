#include "order.service.h"

class OrderController {
  private:
    OrderService orderService;
  
  public:
    OrderController(const ProductService& ps, const UserService& us): orderService(ps, us) {};
};