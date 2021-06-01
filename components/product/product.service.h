#include "product.repository.h"

#include <algorithm>

using namespace std;

class ProductService {
  private:
    ProductRepository productRepo;
    int crtProductId = 0;
    Subject productDeleteSubject;

    Product createProduct (CliInput rawProduct, int id = -1) {
      Product newProduct(
        id == - 1 ? ++crtProductId : id,
        rawProduct.at("name"),
        rawProduct.at("price")
      );

      return newProduct;
    }

  public:
    ProductService() : productRepo() {
      cout << "PRODUCT SERVICE INIT\n";
    };

    friend class OrderService;

    ProductService (const ProductService& p) {}

    template <
      typename Serialize,
      typename T = enable_if<is_same<Serialize, bool>{}>
    >
    vector<string> getAll (Serialize) {
      auto products = productRepo.selectAll();
      vector<string> serializedProducts;

      serializedProducts.resize(products.size());

      transform(
        products.begin(), 
        products.end(), 
        serializedProducts.begin(),
        [](Product &p) -> string { return p.serialize(); }
      );

      return serializedProducts;
    }

    vector<Product> getAll() {
      return productRepo.selectAll();
    }

    int getLength () {
      return productRepo.selectAll().size();
    }

    Product getById (int productId) {
      auto products = productRepo.selectAll();

      auto it = find_if(
          products.begin(), products.end(),
          [&productId](Product &p) { return p.getId() == productId; });

      if (it == products.end()) {
        throw "The product with id: " + to_string(productId) + "does not exist";
      }

      return *it;
    }

    bool insertProduct (CliInput rawProduct) {
      return productRepo.insertProduct(createProduct(rawProduct));
    }

    Product updateProduct (int productId, CliInput rawProduct) {
      auto crtProduct = getById(productId);
      auto productProps = crtProduct.getProperties();

      // Creating a new product by merging what's new with what's already there
      for (size_t i = 0; i < productProps.size(); i++) {
        auto prop = productProps[i];

        if (rawProduct.find(prop) == rawProduct.end()) {
          auto existingVal = crtProduct.getPropertyValue(prop);
          rawProduct.insert({ prop, existingVal });
        }
      }

      auto newProduct = createProduct(rawProduct, productId);

      productRepo.updateProduct(newProduct);
      
      return newProduct;
    }

    bool deleteProduct (int productId) {
      bool ok = productRepo.deleteProduct(productId);

      if (ok) {
        productDeleteSubject.next(productId);
      }

      return ok;
    }
};