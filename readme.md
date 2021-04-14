# backend-api-oop

## Project's Architecture

## Project's state

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

TODO.