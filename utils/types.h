#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <any>
#include <functional>

using namespace std;

class Serializable {
  public:
    virtual string serialize() = 0;
};

class Entity : public Serializable {
  protected:
    virtual vector<reference_wrapper<string>> getPropsAsRefs() = 0;

  public:
    virtual vector<string> getProperties () = 0;
    virtual int getId () = 0;

    string serialize() {
      auto propsRefs = getPropsAsRefs();
      auto properties = getProperties();

      string res = "\n";

      res += "ID: " + to_string(getId()) + '\n';

      for (size_t i = 0; i < propsRefs.size(); i++) {
        res += properties[i] + ": " + propsRefs[i].get() + '\n';
      }

      return res;
    }
};

enum class Values {
  String, Boolean, Integer
};

typedef map<string, string> CliInput;
