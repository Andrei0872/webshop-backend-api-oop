#pragma once

#include <iostream>
#include <string>

using namespace std;

class Product : public Entity {
  private:
    int id;
    int price;
    string name;
    string created_at;

  public:
    string serialize () {
      return "product serialized";
    }
};