use std::sync::atomic::{AtomicI32, Ordering};
use std::sync::Arc;
use std::thread;

struct Accumulator(AtomicI32);

impl Accumulator {
    fn new(value: i32) -> Self {
        Accumulator(AtomicI32::new(value))
    }

    fn fetch_add(&self, val: i32, order: Ordering) -> i32 {
        self.0.fetch_add(val, order)
    }

    fn load(&self, order: Ordering) -> i32 {
        self.0.load(order)
    }
}

fn add(n1: i32, n2: i32) -> i32 {
    let sum = Arc::new(Accumulator::new(n1));
    let (count, increment) = if n2 > 0 { (n2, 1) } else { (-n2, -1) };
    let mut handles = vec![];

    for _ in 0..count {
        let inner_sum = Arc::clone(&sum);
        handles.push(thread::spawn(move || {
            inner_sum.fetch_add(increment, Ordering::SeqCst);
        }));
    }

    for handle in handles {
        handle.join().unwrap();
    }

    sum.load(Ordering::SeqCst)
}

fn main() {
    let a = 38;
    let b = 4;
    println!("{} + {} = {}", a, b, add(a, b));
}
