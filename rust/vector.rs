// 创建空的vector : Vec<T>
fn main() {
    let mut v: Vec<i32> = Vec::new();
    //v.push(1);
    let v = vec![1, 2, 3];
    // {
    //     let v1=vec![1,2,3];
    // }
    //使用索引的方式
    let one: &i32 = &v[0];
    println!("{}", one);
    println!("{}", *one);

    match v.get(1) {
        Some(i) => {
            println!("{}", i);
        }
        _ => println!("none"),
    }
    //更新
    let mut v2: Vec<i32> = Vec::new();
    v2.push(1);
    v2.push(2);
    v2.push(4);
    v2.push(3);
    for i in &v2 {
        println!("{}", i);
    }
    for i in &mut v2 {
        *i += 1;
        println!("{}", i);
    }
    enum con {
        Text(String),
        Int(i32),
    };
    let c = vec![con::Text(String::from("sting")), con::Int(-1)];
}
