#pragma once

#include "../../utils/types.h"

class MemoryDriver : public DBDriver {
  private:
    map<string, map<string, DBTable<Entity>>> databases;

  public:
    MemoryDriver(): DBDriver("memory") {
      
    }
};