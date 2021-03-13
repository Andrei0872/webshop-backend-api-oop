#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Serializable {
  public:
    virtual string serialize() = 0;
};

class Entity : public Serializable {};

// template<typename T>
// class DBTable {
//   private:
//     string name;
//     string *columns;
//     T* dataList;
//   public:
//     DBTable(T entity) {};

//     T* selectAll();
//     T find ();
//     bool deleteOne (T item);
// };

// map<string, DBTable<Entity>> selectDb(string name);
// DBTable<Entity> selectTable(map<string, DBTable<Entity>> tables);

class DBDriver {
  private:
    string ID;
  public:
    DBDriver(string ID): ID(ID) {};

    template<typename DB>
    DB selectDb(string name);
    template<typename DB, typename T>
    T selectTable (DB tables);

    virtual void connect(Config c);
};
