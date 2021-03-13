#include "../config.h"

using namespace std;

class Database {
  private:
    Config config;

    // Making sure it remains singleton
    Database () { cout << "DB\n"; }
    Database(Database const &);
    void operator=(Database const &);
  public:

    static Database& getInstance () {
      static Database instance;

      return instance;
    }
};