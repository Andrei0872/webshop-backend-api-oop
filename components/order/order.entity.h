
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

  // TODO: copy constructor

  // TODO: =, << operators

  virtual int getId () const {
    return id;
  }

  virtual vector<string> getProperties () const {
    return properties;
  }
};

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
};