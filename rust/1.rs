fn main() {
    // miku(10);
    let a = Yan::Love;
    let b = Yan::Miku(String::from("Miku"));
    a.lm();
    b.lm();
    let some_number = Some(5);
    let some_string = Some(String::from("miku"));
    let absent_number: Option<i32> = None;
    let x: i32 = 5;
    let y: Option<i32> = Some(5);
    // let sum=x+y; 不是同一个类型
    let mut temp = 0;
    match y {
        Some(i) => {
            temp = i;
        }
        None => {
            println!("do nothing");
        }
    };
    let sum = x + temp;
    println!("{}", sum);
    let result = plus(y);
    match result {
        Some(i) => {
            println!("i={}", i);
        }
        None => {
            println!("错误");
        }
    };
}
fn plus(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(x) => Some(x + 1),
    }
}

enum Yan {
    Love,
    Miku(String),
}

impl Yan {
    // add code here
    fn lm(&self) {
        match *self {
            Yan::Love => println!("初音我老婆"),
            _ => println!("就这样吧"),
        }
    }
}
