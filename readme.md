# backend-api-oop

## Requirements

* make sure you can run `Makefile` commands

---

## Getting started

1. add your env variables

```bash
cp .env.example .env
```

2. build & run

```bash
env $(cat .env) make
```

Additionally, if you want to inspect `valgrind`'s outputs, you can use:

```bash
env $(cat .env) valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./main &> valgrind.txt
```

---

## App overview

There are 3 main entities: `User`, `Product`, `Order`, each of which has CRUD operations defined.

The `Order` entity has an additional feature: when a product entity is deleted(the product does not have to necessarily exist in the order's products list), that product will be automatically deleted from the orders' products list as well. This is achieved with the help of the `Observer` pattern.