fn main() {
    //bool
    let is_true: bool = true;
    println!("is true = {}", is_true);
    let is_false: bool = false;
    println!("is false = {}", is_false);
    println!("max={}", usize::max_value());
    //数组
    //[type;size]
    let arr: [u32; 5] = [1, 2, 3, 4, 50];
    println!("{}", arr[0]);
    show(arr);
    let o: (i32, char, f32) = (-32, '我', 0.001);
    println!("{}", o.0);
    println!("{}", o.1);
    println!("{}", o.2);
}

fn show(arr: [u32; 5]) {
    for i in &arr {
        println!("{}", i);
    }
}
