#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Serializable {
  public:
    virtual string serialize() = 0;
};

class Entity {};