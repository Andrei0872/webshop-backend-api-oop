#include <iostream>

#include "../../utils/types.h"
#include "product.entity.h"

using namespace std;

class ProductRepository : public Repository {
    private:
      ProductTable* productTable;
    
    public:
      ProductRepository(): Repository() {
        cout << "PRODUCT REPO \n";

        productTable = new ProductTable("product");

        setTable("product", productTable);
      }

      ~ProductRepository () {
        delete productTable;
      }

      vector<Product> selectAll () {
        return productTable->selectAll();
      };

      bool insertProduct (Product p) {
        productTable->insertOne(p);

        return true;
      }

      bool updateProduct (Product p) {
        productTable->updateOne(p);

        return true;
      }

      bool deleteProduct (int productId) {
        try {
          productTable->deleteOne(productId);
        } catch (string msg) {
          cout << msg << '\n';
          return false;
        }

        return true;
      }
};