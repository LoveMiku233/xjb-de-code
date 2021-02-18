fn main() {
    let a = 3;
    if a == 1 {
        println!("{}", a);
    } else {
        println!("{}", a + 1);
    }
    let condition = if a == 1 { true } else { false };
    let x = if condition { 5 } else { 6 };
    println! {"{}",x};
    let mut i = 0;
    loop {
        if i == 10 {
            break;
        } else {
            i += 1;
        }
        println!("{}", i);
    }
    let arr: [i32; 5] = [1, 2, 3, 4, 5];
    for a in &arr {
        println!("{}", a);
    }
}
