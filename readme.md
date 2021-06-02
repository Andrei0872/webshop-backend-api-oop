# backend-api-oop

## Requirements

* make sure you can run `Makefile` commands

---

## Getting started

### Add the env variables

#### Linux

```bash
cp .env.example .env
```

**Note**: the values must be strings, e.g: `export DB_USER="andrei"`.

#### Windows

```bash
cp .env.example .env.bat && sed -i s/export/set/g .env.bat
```

### Build and run

#### Linux

```bash
source .env && make
```

Additionally, if you want to inspect `valgrind`'s outputs, you can use:

```bash
env $(cat .env) valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./main &> valgrind.txt
```

#### Windows

```bash
call .env.bat && make
```

---

## App overview

There are 3 main entities: `User`, `Product`, `Order`, each of which has CRUD operations defined.

The `Order` entity has an additional feature: when a product entity is deleted(the product does not have to necessarily exist in the order's products list), that product will be automatically deleted from the orders' products list as well. This is achieved with the help of the `Observer` pattern.