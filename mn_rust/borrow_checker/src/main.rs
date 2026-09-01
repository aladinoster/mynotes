fn main() {
    let string1 = "some".to_string();
    let string2 = string1;

    // println!("{}", string1); // "some" has been borrowed to string2 so string1 is uninit
    println!("{}", string2);

    let num1: i32 = 36;
    let num2 = num1;

    println!("{}", num1); // int are not moved
    println!("{}", num2);
}
