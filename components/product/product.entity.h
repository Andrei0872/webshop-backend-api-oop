#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product : virtual public Entity {
  private:
    int id;
    string price;
    string name;

    vector<string> properties {"price", "name"};

    void assignNewProduct (const Product& newProduct) {
      auto crtProductPropsRefs = getProperties();

      for (size_t i = 0; i < crtProductPropsRefs.size(); i++) {
        setPropertyValue(crtProductPropsRefs[i], newProduct.getPropertyValue(crtProductPropsRefs[i]));
      }

      setId(newProduct.getId());
    }

  protected:
    virtual vector<reference_wrapper<const string>> getPropsAsRefs () const {
      vector<reference_wrapper<const string>> propsRefs{price, name};

      return propsRefs;
    }

    virtual vector<reference_wrapper<string>> getMutablePropsAsRefs () {
      vector<reference_wrapper<string>> propsRefs{price, name};
      return propsRefs;
    }

  public:
    Product(int id, string name, string price):
      id(id), name(name), price(price) { }

    Product (const Product& newProduct) {
      assignNewProduct(newProduct);
    }

    Product& operator= (const Product& rProduct) {
      assignNewProduct(rProduct);

      return *this;
    }

    friend ostream& operator << (ostream& os, const Product& p) {
      os << p.serialize();

      return os;
    }

    virtual int getId () const {
      return id;
    }

    void setId (const int& newId) {
      id = newId;
    }

    int getPrice () const {
      return stoi(price);
    }

    virtual vector<string> getProperties () const {
      return properties;
    }
};

class ProductTable : public DBTable {
  private:
    vector<Product> products;

  public:
    ProductTable(string name): DBTable(name) {};

    vector<Product> selectAll () const {
      return products;
    }

    void insertOne (Product product) {
      products.push_back(product);
    }

    void updateOne (const Product& newProduct) {
      for (size_t i = 0; i < products.size(); i++) {
        auto crtProduct = products[i];
        products[i] = crtProduct.getId() == newProduct.getId() ? newProduct : crtProduct;
      }
    }

    void deleteOne (int productId) {
      if (!products.size()) {
        throw string("There are no more products - nothing to delete");
      }
      
      auto it = remove_if(
        products.begin(),
        products.end(),
        [&, productId](const Product& p) {
          return p.getId() == productId;
        }
      );

      if (it == products.end()) {
        string errorMsg = "The product with id=";
        errorMsg += to_string(productId) + "does not exist!";

        throw errorMsg;
      }

      products.erase(it, products.end());
    }
};