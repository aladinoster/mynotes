#[derive(Debug, Clone)]
enum CoffeType {
    HOT(Option<f64>),
    COLD(Option<f64>),
}

#[derive(Debug, Clone)]
struct Coffee {
    id: i64,
    state: CoffeType,
    name: String,
}

fn main() {
    let x: i8 = 8;
    let xc: i32 = "132".parse().unwrap();
    let y: u8 = 8;
    let z: f32 = 2.5;
    let c: char = 'B';
    let v: bool = true;
    let my_tuple = ('A', 1, 2);
    let nested_tuple: ((i32, i32), (i32, i32)) = ((1, 2), (3, 4));
    let ((n1, n2), (n3, n4)) = nested_tuple;
    let my_array = [1, 2, 3];
    let same_value_array: [i32; 10] = [1; 10];
    let my_typed_array: [i32; 3] = [1, 2, 3];
    let mut coffee = Coffee {
        id: 1,
        state: CoffeType::COLD(Some(20.2)),
        name: String::from("Latte"),
    };

    println!("x (i8): {}", x);
    println!("xc (i8): {}", xc);

    println!("y (u8): {}", y);
    println!("z (f32): {}", z);
    println!("z floor (f32): {}", z.floor());
    println!("z ceil  (f32): {}", z.ceil());
    println!("z round (f32): {}", z.round());

    let zx: i32 = z as i32 + x as i32;
    let xz: f32 = x as f32 + z;
    println!("zx (i32): {}", zx);
    println!("xz (f32): {}", xz);

    println!("c (char): {}", c);
    println!("c is uppercase (char): {}", c.is_uppercase());
    println!("c is lowercase (char): {}", c.is_lowercase());
    println!("c uppercase (char): {}", c.to_uppercase());
    println!("c ascii upppercase (char): {}", c.to_ascii_uppercase());
    println!("c string (char): {}", c.to_string());

    println!("v (bool): {}", v);

    // Print tuple elements
    println!("my_tuple: ({}, {}, {})", my_tuple.0, my_tuple.1, my_tuple.2);
    println!("nested_tuple: (({}, {}), ({},{}))", n1, n2, n3, n4);
    for i in same_value_array {
        println!("Number: {}", i);
    }
    println!("array same_value {:?}", same_value_array);
    println!(
        "array mem size {}",
        std::mem::size_of_val(&same_value_array)
    );

    // Print arrays
    println!("my_array: {:?}", my_array);
    println!("my_typed_array: {:?}", my_typed_array);

    // Print Coffee struct
    println!("coffee.id: {}", coffee.id);
    println!("coffee.name: {}", coffee.name);
    println!("coffee.state: {:?}", coffee.state);

    // Updates
    coffee.id = 2;
    coffee.name = String::from("Paul");
    println!("new coffee.id: {}", coffee.id);
    println!("new coffee.name: {}", coffee.name);

    println!("Instance coffee {:?}", coffee);

    let mut combined2 = coffee.clone();
    // moves coffe to combined (we lose owner ship)
    let combined: Coffee = Coffee { id: 3, ..coffee };

    println!("New instance combined {:?}", combined);

    combined2.id = 3;
    println!("New instance combined2 {:?}", combined2);
}
