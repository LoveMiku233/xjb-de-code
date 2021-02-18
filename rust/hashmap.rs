use std::collections::HashMap;

fn main() {
    let i: i32 = 1;
    let mut scores: HashMap<String, i32> = HashMap::new();
    scores.insert(String::from("miku"), 1);
    scores.insert(String::from("yankai"), 2);

    let keys = vec![String::from("miku"), String::from("yankai")];
    let values = vec![10, 20];
    let scores: HashMap<_, _> = keys.iter().zip(values.iter()).collect();
    let k = String::from("miku");
    if let Some(v) = scores.get(&k) {
        println!("{},miku={}", i, v);
    }
}
