fn main() {
    let number = Some(5);
    let stra = Some(String::from("a string"));
    let absent: Option<i32> = None;
    let k = Some(9);
    if let Some(p) = miku(k) {
        println!("p = {}", p);
    } else {
        println!("no noting");
    }
    let x: i32 = 5;
    let y: Option<i32> = Some(5);
    let mut temp = 0;
    match y {
        Some(i) => {
            temp = i;
        }
        None => {
            println!("do nothing");
        }
    }
    let sum = x + temp;
    println!("{}", sum);
    let a = Some(99);
    match miku(a) {
        Some(i) => println!("{}", i),
        None => println!("no num"),
    }
}

fn miku(x: Option<i32>) -> Option<i32> {
    match x {
        Some(x) => Some(x + 1),
        None => None,
    }
}
