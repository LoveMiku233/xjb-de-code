fn main() {
    //创建空的字符串
    let mut s1 = String::new();
    s1.push_str("miku");
    println!("{}", s1);
    let s1 = "LoveMiku".to_string();
    println!("{}", s1);

    //更新字符串
    let mut s2 = String::new();
    s2.push_str("Hello");
    println!("{}", s2);
    let ss = ",Miku".to_string();
    s2.push_str(&ss);
    s2.push_str("!");
    println!("{}", s2);

    let mut s2 = String::from("miku");
    s2.push('m');

    let s2 = "miku".to_string();
    let s3 = String::from("hello ");
    if let s4 = s3 + &s2 {
        println!("{}", s4);
    } else {
        println!("GG");
    }

    let s5 = String::from("凯严");
    println!("{}", s5.len());
    let s6 = &s5[0..3];
    println!("{}", s6);

    //chars
    for c in s5.chars() {
        println!("{}", c);
    }

    for b in s5.bytes() {
        println!("{}", b);
    }
}
