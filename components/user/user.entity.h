#pragma once

#include <string>
#include "../../utils/types.h"

using namespace std;

class User : public Entity {
  private:
    int id;
    string firstName;
    string lastName;
    string country;
    string registered_at;

  public:
    string serialize();
};