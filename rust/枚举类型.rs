fn main() {
    //c语言定义方法
    enum IP {
        v4,
        v6,
    };
    struct miku {
        kind: IP,
        add: String,
    };
    let i1 = miku {
        kind: IP::v4,
        add: String::from("192.168.1.1"),
    };
    //rust方法
    enum IP2 {
        V4(String),
        V6(String),
    };

    let v4u = IP2::V4(String::from("123"));
    let v6u = IP2::V6(String::from("322"));

    enum IP3 {
        V4(i8, i8, i8, i8),
        V6(i8, i8, i8, i8),
    };
    let V4n = IP3::V4(2, 1, 3, 4);
    let V6n = IP3::V6(1, 1, 1, 1);

    //Message用法
    enum Message {
        Quit,
        Move(i32, i32),
        nonono(String),
        Change(i32, i32, i32),
    };
    impl Message {
        fn print(&self) {
            match *self {
                Message::Quit => println!("Quit"),
                Message::Move(x, y) => println!("{},{}", x, y),
                Message::Change(a, b, c) => println!("{},{},{}", a, b, c),
                _ => println!("2333"),
            }
        }
    };
    let message = Message::Move(4, 7);
    let quit = Message::Quit;

    quit.print();
    message.print();
}
