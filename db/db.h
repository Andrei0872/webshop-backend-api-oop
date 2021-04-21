#include "../config.h"
#include<map>
#include<string>
#include <vector>

using namespace std;

class Bar{};

class DBTable {
  protected:
    string name;
    vector<string> columns;
    vector<Entity> data;

  public:
    DBTable(string name = ""): name(name) {
      cout << "TABLE INIT: " << name << '\n';
    };

    void hello () {
      cout << "Hello from DBTABLE \n";
    }
};

typedef map<string, DBTable*> TablesMap;
typedef map<string, TablesMap> DatabasesMap;

class DBDriver {
  private:
    string ID;

  protected:
    DatabasesMap databases;

  public:
    DBDriver(string ID = ""): ID(ID) {};
    virtual ~DBDriver () { }

    TablesMap selectDb(string name) {
      return databases.at(name);
    };
    
    DBTable* selectTable (TablesMap tables, string tableName) {
      cout << "CRT TABLE NAME " << tableName << '\n';
      
      return tables.at(tableName);
    }

    string getId () {
      return ID;
    }
    virtual void connect(Config config) {};
};

class Database {
  private:
    Config config;
    DBDriver* driver;
    TablesMap crtDb;
    TablesMap tables;

    Database () { cout << "DB INIT\n"; }

    void setDbBasedOnConfig () {
      tables = driver->selectDb(config.getDBName());
    }
  
  public:

    static Database& getInstance () {
      static Database instance;

      return instance;
    }

    TablesMap getTables () {
      return tables;
    }

    void setDriver (DBDriver* newDriver) {
      driver = newDriver;
    }

    void printDriverId () {
      cout << "CURRENT DRIVER ID: " << driver->getId() << "\n";
    }

    void connect () {
      driver->connect(config);
      setDbBasedOnConfig();
    }

    DBTable* selectTable (string tableName) {
      return driver->selectTable(crtDb, tableName);
    }
};

class Repository {
  protected:
    Database db;

  protected:
  
    // Add tables to DB _dynamically_, based on entity repositories
    void setTable (string tableName, DBTable* table) {
      db.getTables().insert({ tableName, table });
    }
  
  public:
    Repository (): db(Database::getInstance()) {};
};