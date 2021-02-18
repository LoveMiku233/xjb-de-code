use std::fs::File;
use std::io;
use std::io::Read;
fn main() {
    let r = read_name();
    match r {
        Ok(s) => println!("s={}", s),
        Err(e) => println!("err={:?}", e),
    }
}

fn read_name() -> Result<String, io::Error> {
    let f = File::open("hello.txt")?;
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    Ok(s)
}
