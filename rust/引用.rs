fn main() {
    let s1 = gives();
    println!("{} s1", s1);
    let mut s2 = String::from("hello");
    let s3 = back(s2); //s2不能使用

    s2 = back(s3);
    println!("{} s2", s2);
    let mut cd = jscd(&s2);
    println!("{} s2 cd", cd);
    pushstr(&mut s2);
    println!("{} s2", s2);
    cd = jscd(&s2);
    println!("{} s2 2 cd", cd);
    //println!("{} s2",s2);
}

fn gives() -> String {
    let s = String::from("Miku");
    s //使用权给s1
}

fn back(s: String) -> String {
    s
}

//引用 &
fn jscd(s: &String) -> usize {
    s.len()
}
//借用 &mut
fn pushstr(s: &mut String) {
    s.push_str(" Miku");
}
