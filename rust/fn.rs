fn fun() {
    println!("this is function");
}
fn fun1(a: i32, b: char) {
    println!("{},{}", a, b);
}
fn fun2(a: i32, b: i32) -> i32 {
    a + b
}
fn main() {
    fun();
    let a: i32 = -32;
    let b: char = '我';
    let c: i32 = 8;
    fun1(a, b);
    println!("{}", fun2(a, c));

    let i = { a - c };
    println!("{}", i);
}
