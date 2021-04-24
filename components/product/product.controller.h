#include "product.service.h"
#include <map>
#include <algorithm>

using namespace std;

class ProductController {
  private:
    ProductService productService;

  public:
    ProductController(): productService() {
      cout << "PRODUCT CONTROLLER INIT \n";
    };

    void operator<< (const vector<string>& serializedProducts) {
      for_each(serializedProducts.begin(), serializedProducts.end(), [](string u) { cout << u << "\n\n"; });
      
      return;
    }

    void getAll () {
      try { 
        auto products = productService.getAll(true);
        
        *this << products;
      } catch (char const* e) {
        cout << e << '\n';
      }

    }

    Product getById (int productId) {
      return productService.getById(productId);
    }

    void insertProduct (CliInput rawProduct) {
      bool ok = productService.insertProduct(rawProduct);

      if (!ok) {
        return;
      }

      cout << "The product has been successfully added. \n";
    }

    void updateProduct (int productId, CliInput newProduct) {
      auto updatedProduct = productService.updateProduct(productId, newProduct);

      cout << "\nUPDATED PRODUCT:";
      cout << updatedProduct;
    }

    void deleteProduct (int productId) {
      bool successfullyDeleted = productService.deleteProduct(productId);

      string message;

      if (successfullyDeleted) {
        message = "Successfully deleted ";
      } else {
        message = "There was a problem deleting the ";
      }

      message += "product with id=" + to_string(productId);

      cout << message << '\n';
    }

    ProductService& getProductService () {
      return productService;
    }
};