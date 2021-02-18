//创建hashmap
use std::collections::HashMap;
fn main() {
    let mut miku: HashMap<String, i32> = HashMap::new();
    miku.insert(String::from("ten"), 10);
    miku.insert(String::from("two ten"), 20);

    let keys = vec![String::from("ten"), String::from("two ten")];
    let values = vec![20, 30];
    let miku: HashMap<_, _> = keys.iter().zip(values.iter()).collect();

    let k = String::from("ten");
    //if let Some(v) = miku.get(&k) {
    //     println!("{}", v);
    // }
    let v = miku.get(&k);
    match v {
        Some(i) => println!("{}", i),
        None => println!("233"),
    }

    for (key, values) in &miku {
        println!("{},{}", key, values);
    }

    let mut ss1 = HashMap::new();
    ss1.insert(String::from("one"), 1);
    ss1.insert(String::from("two"), 2);
    ss1.insert(String::from("three"), 3);
    ss1.entry(String::from("miku")).or_insert(1);
    for (key, values) in &ss1 {
        println!("{},{}", key, values);
    }

    let text = "hello world world hello";
    let mut ss2 = HashMap::new();
    for word in text.split_ascii_whitespace() {
        let count = ss2.entry(word).or_insert(0);
        *count += 1;
    }
    for (key, values) in &ss2 {
        println!("{},{}", key, values);
    }
}
