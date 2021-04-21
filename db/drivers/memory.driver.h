#pragma once

// #include "../db.h"

class MemoryDriver : public DBDriver {
  private:

    // Just some hardcoded data when using this driver
    void populateDb (Config config) {
      TablesMap tables;

      // DBTable* productTable = new DBTable("product");
      // tables["product"] = productTable;

      // DBTable *userTable = new DBTable("user");
      // tables["user"] = userTable;

      // DBTable *adminTable = new DBTable("admin");
      // tables["admin"] = adminTable;

      databases[config.getDBName()] = tables;
    }

  public:
    MemoryDriver(): DBDriver("@ID_MEMORY_DRIVER") {
      cout << "MEMORY DRIVER INIT \n";
    }

    virtual void connect(Config config) {
      cout << "[MEMORY DRIVER]: CONNECTING \n";
      populateDb(config);
    }
};