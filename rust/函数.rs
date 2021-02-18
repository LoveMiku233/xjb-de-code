fn main() {
    println!("Hello, world!");
    let y = 6;
    let x = {
        let y = y + 7;
        y
    };
    let x=Miku(x, 233);
    println!("{}",x);
    let nb=true;
    let i=if nb{2}else{3};
    println!("{}",i);
    let mut i:i32=1;
    loop{
        println!("Love Miku!");
        if i>20 {
            break;
        }
        i+=1;
    }
}
fn Miku(x: i32, y: i32) -> i32 {
    println!("Miku! {} {}", x, y);
    return x+y;
}
