use std::sync::Arc;
use std::sync::Mutex;
use std::thread;

struct Accumulator {
    sum: i32,
    operation_count: i32,
}

impl Accumulator {
    fn new(sum: i32) -> Accumulator {
        Accumulator {
            sum,
            operation_count: 0,
        }
    }

    fn add(&mut self, increment: i32) {
        self.sum += increment;
        self.operation_count += 1;
    }

    fn get_sum(&self) -> i32 {
        self.sum
    }

    fn get_count(&self) -> i32 {
        self.operation_count
    }
}

fn add(n1: i32, n2: i32) -> i32 {
    let acc = Arc::new(Mutex::new(Accumulator::new(n1)));
    let (count, increment) = if n2 > 0 { (n2, 1) } else { (-n2, -1) };
    let mut handles = vec![];

    for _ in 0..count {
        let inner_acc = Arc::clone(&acc);
        handles.push(thread::spawn(move || {
            let mut guarded_acc = inner_acc.lock().unwrap();
            guarded_acc.add(increment);
        }));
    }

    for handle in handles {
        handle.join().unwrap();
    }

    let final_acc = acc.lock().unwrap();
    final_acc.get_sum()
}

fn main() {
    let a = 38;
    let b = 4;
    println!("{} + {} = {}", a, b, add(a, b));
}
