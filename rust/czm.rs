use std::io;
use std::cmp::Ordering;
fn main() {
      let a:u32=50;
       println!("猜数字!");
       loop{
            println!("请输入你的数字");
            let mut guess = String::new();
            io::stdin().read_line(&mut guess).expect("输入错误");
            if(guess=="exit"){ break;}
            let guess: u32 = match guess.trim().parse() {
                  Ok(num) => num,
                  Err(_) => continue,
              };
             match guess.cmp(&a) {
                 Ordering::Less=>println!("小了"),
                 Ordering::Greater => println!("大了"),
                 Ordering::Equal => {println!("你赢了!");break;},
             }

       }
}