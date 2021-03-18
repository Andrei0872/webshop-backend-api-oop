# backend-api-oop

## Project's Architecture

## Project's state

* [ ] user
  * [X] entity
  * [ ] controller
  * [ ] service
  * [ ] repository
  * [ ] allow an user to make an order
  * [ ] endpoint for adding a new user
  * [ ] list all users
* [ ] admin
  * is a kind of user
  * [ ] entity
  * [ ] controller
  * [ ] service
  * [ ] repository
  * [ ] allow an admin to add products
  * [ ] allow an admin to add a discount to a product
* [ ] product
  * [ ] entity
  * [ ] controller
  * [ ] service
  * [ ] repository
  * [ ] list products
* [ ] order
  * has one or more products
  * can belong to **only one user** and a **user can have more orders**
  * this will imply a **new db table**, `products_ordered`, which will contain the state of the ordered product(it may vary from the one in the `products` table, because discounts may be factored in, or different quantities may be used) and the FK of the record in the `orders` table.
  * [ ] entity
  * [ ] repository
  * [ ] `products_ordered` table (simulated)
  * [ ] `user_product` junction table (simulated)
  * [ ] list all orders for a given user
  * [ ] listen the products in an order
* [ ] discount
  * [ ] entity
  * [ ] list discounts
* [ ] database
  * [X] db config obj
  * [ ] drivers
    * [ ] mysql (not going to be used, just for demo purposes)
    * [ ] memory
  * [ ] include drivers
* [ ] create a tiny CLI app instead of a server
* [ ] add a `Logger` class
* [ ] add teardown logic in destructors

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

---

## App overview

TODO.