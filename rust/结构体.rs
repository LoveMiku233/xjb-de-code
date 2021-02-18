fn main() {
    #[derive(Debug)]
    struct Miku {
        name: String,
        count: String,
        active: bool,
        nonce: u64,
    };
    let mut LoveMiku = Miku {
        name: String::from("LoveMiku"),
        count: String::from("1234567"),
        active: true,
        nonce: 10000,
    };
    LoveMiku.name = String::from("233");
    println!("{}", LoveMiku.name);

    let name = String::from("Miku");
    let count = String::from("110");
    let active = true;
    let nonce = 1213213;
    let user1 = Miku {
        count,
        name,
        active,
        nonce,
    };
    println!("{}", user1.name);

    let user2 = Miku {
        name: String::from("gyhfg"),
        ..user1
    };
    println!("{} {}", user2.name, user2.count);

    //元组结构体 字段没名字 圆括号
    struct Miku1(i32, i32);
    let mut x = Miku1(10, 20);
    let b = Miku1(30, 11);
    x.0 = 111;
    println!("x 1 {} 2 {}", x.0, x.1);

    //没有任何字段的结构体
    struct Miku3 {};
    //打印结构体
    println!("{:?}",LoveMiku);
}
