#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <any>

using namespace std;

class Serializable {
  public:
    virtual string serialize() = 0;
};

class Entity : public Serializable {
  public:
    virtual vector<string> getProperties ();
};

enum class Values {
  String, Boolean, Integer
};

typedef map<string, string> CliInput;
