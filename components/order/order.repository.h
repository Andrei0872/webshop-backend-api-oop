#include <iostream>
#include <string>

#include "../../utils/types.h"
#include "order.entity.h"

using namespace std;

class OrderRepository : public Repository {
  private:
    OrderTable* orderTable;
    int crtOrderId = 0;

    vector<ProductInfo> convertRawProductInfo (nlohmann::json rawProductsInfo) {
      vector<ProductInfo> res;

      for (auto pInfo : rawProductsInfo) {
        ProductInfo productInfo;
        productInfo.productId = to_string(pInfo.at("productId"));
        productInfo.quantity = to_string(pInfo.at("quantity"));

        res.push_back(productInfo);
      }

      return res;
    }

  public:
    OrderRepository(): Repository() {
      cout << "ORDER REPO \n";

      orderTable = new OrderTable("order");

      setTable("order", orderTable);
    }

    ~OrderRepository () {
      delete orderTable;
    }

    void insertOrder (string userId, nlohmann::json rawProductsInfo) {
      Order o(
        ++crtOrderId,
        userId,
        convertRawProductInfo(rawProductsInfo)
      );

      orderTable->insertOne(o);

      // cout << orderTable->selectAll().size();
    }

    vector<Order> selectAll () {
      return orderTable->selectAll();
    }
};