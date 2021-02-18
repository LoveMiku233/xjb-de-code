fn miku(some_str: String) {
    println!("{}", some_str);
}
fn make_copy(i: i32) {
    println!("{}", i);
}
fn main() {
    let s = String::from("hello");
    miku(s);
    let x = 5;
    make_copy(x);
}
