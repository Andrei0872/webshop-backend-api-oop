#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <any>
#include <functional>
#include <algorithm>
#include <iterator>

using namespace std;

class Serializable {
  public:
    virtual string serialize() const {
      throw "Must be implemented";
      
      return "";
    };
};

class Entity : public Serializable {
  protected:
    virtual vector<reference_wrapper<const string>> getPropsAsRefs() const {
      // TODO: create a custom exception
      throw "Must be implemented";
      
      vector<reference_wrapper<const string>> temp;
      
      return temp;
    };

    virtual vector<reference_wrapper<string>> getMutablePropsAsRefs () = 0;

  public:
    virtual vector<string> getProperties () const {
      // TODO: create a custom exception
      throw "Must be implemented";

      vector<string> temp;

      return temp;
    };
    virtual int getId () const {
      // TODO: create a custom exception
      throw "Must be implemented";

      return 0;
    };

    string serialize() const {
      auto propsRefs = getPropsAsRefs();
      auto properties = getProperties();

      string res = "\n";

      res += "ID: " + to_string(getId()) + '\n';

      for (size_t i = 0; i < propsRefs.size(); i++) {
        res += properties[i] + ": " + propsRefs[i].get() + '\n';
      }

      return res;
    }

    string getPropertyValue (string prop) const {
      auto props = getProperties();
      auto it = find_if(props.begin(), props.end(), [&, prop](string p) { return p == prop; });

      // TODO: throw error
      if (it == props.end()) {
        return "";
      }

      auto propsRefs = getPropsAsRefs();
      int idx = distance(props.begin(), it);

      return propsRefs[idx].get();
    }

    void setPropertyValue (const string& prop, const string& val) {
      auto props = getProperties();
      auto it = find_if(props.begin(), props.end(), [&, prop](string p) { return p == prop; });

      // TODO: throw error
      if (it == props.end()) {
        throw "Property not found";
      }

      auto propsRefs = getMutablePropsAsRefs();
      int idx = distance(props.begin(), it);

      propsRefs[idx].get() = val;
    }
};

enum class Values {
  String, Boolean, Integer
};

typedef map<string, string> CliInput;
