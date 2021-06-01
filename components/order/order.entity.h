
#include <iostream>
#include <vector>
#include "../../utils/types.h"

using namespace std;

typedef struct { string productId; string quantity; } ProductInfo;

class Order : public Entity {
  private:
    int id;
    string userId;
    vector<ProductInfo> productsInfo;

    vector<string> properties{"userId", "productsInfo"};
  
  protected:
    virtual vector<reference_wrapper<const string>> getPropsAsRefs () const {
      vector<reference_wrapper<const string>> propsRefs{userId};

      return propsRefs;
    }

    virtual vector<reference_wrapper<string>> getMutablePropsAsRefs () {
      vector<reference_wrapper<string>> propsRefs{userId};
      return propsRefs;
    }
  
  public:
    Order (int orderId, string& userId, vector<ProductInfo> productsInfo):
      id(orderId), userId(userId), productsInfo(productsInfo) { };

    friend ostream& operator<<(ostream& os, Order& o);

    vector<ProductInfo>& getProductsInfo () {
      return productsInfo;
    }

    virtual int getId () const {
      return id;
    }

    virtual vector<string> getProperties () const {
      return properties;
    }
};

ostream& operator<< (ostream& os, Order& o) {
  os << "Order ID: " << o.id << '\n';
  os << "User ID: " << o.userId << '\n';
  os << "Products :";

  if (!o.productsInfo.size()) {
    cout << "There are no products in this order. \n";

    return os;
  }

  cout << '\n';

  for_each(o.productsInfo.begin(), o.productsInfo.end(), [](ProductInfo& pI) {
    cout << "\tProduct ID: " << pI.productId << ", " << "Quantity: " << pI.quantity << '\n';
  });

  return os;
}

class OrderTable : public DBTable {
  private:
    vector<Order> orders;
  
  public:
    OrderTable(string name): DBTable(name) {};
  
    vector<Order> selectAll () const {
      return orders;
    }

    void insertOne (Order& order) {
      orders.push_back(order);
    }

    void deleteOne (int orderId) {
      if (!orders.size()) {
        throw string("There are no more orders - nothing to delete");
      }
      
      auto it = remove_if(
        orders.begin(),
        orders.end(),
        [&, orderId](const Order& o) {
          return o.getId() == orderId;
        }
      );

      if (it == orders.end()) {
        string errorMsg = "The order with id=";
        errorMsg += to_string(orderId) + "does not exist!";

        throw errorMsg;
      }

      orders.erase(it, orders.end());
    }

    void deleteProductFromAllOrders (string productId) {
      // Deleting the product with `productId`
      // from all the orders.
      for_each(orders.begin(), orders.end(), [&](Order& o) {
        auto& productsInfo = o.getProductsInfo();
        auto it = find_if(productsInfo.begin(), productsInfo.end(), [&productId](ProductInfo& pI) {
          return pI.productId == productId;
        });

        if (it == productsInfo.end()) {
          return;
        }

        productsInfo.erase(it);
      });
    }
};