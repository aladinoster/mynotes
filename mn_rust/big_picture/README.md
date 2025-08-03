# README

The idea on this repo is to keep some of the ways to perform a simple sum from a single function to a asyncrhonous fashion:

## Compile

All the project should be compilable via 

```shell
cargo -b
```

## Explanations

### `sum.rs`

It is the more basic one pretty trivial. The `.inspect(...)` part is optional is only to execute a closure. A closure is somehow like a lambda (function-like block of code).

```rust
let add_one = |x| x + 1;
let result = add_one(5); // result is 6
```


