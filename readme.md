# backend-api-oop

## TODOS

* product
  * [X] CRUD
  * [ ] endpoints

* user
  * [ ] endpoints

* order
  * [ ] CRUD order
  * [ ] an order must have a user, and the user might have at least one product(the products in the order must be unique)
  * [ ] might have to extend the `Product` class so that it also supports a `quantity` property
  * [ ] endpoints

* API
  * [ ] have an api that yields the app's state
  * [ ] add Postman

* [ ] add `Logger` class

* IDEAS
  * when a product/user is deleted, use make sure the changes are reflected into `orders`(the `Observer Pattern`)

## Project's Architecture

// TODO:

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

* mention about what are `controller`, `service`, `repository` etc...