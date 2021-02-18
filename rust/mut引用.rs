fn main(){
    let mut s1=String::from("Love");
    println!("s1 one {}",s1);
    push(&mut s1);
    println!("s1 two {}",s1);
    let a=jscd(&s1);
    println!("s1 cd {}",a);
}
fn push(s: &mut String){
    s.push_str("miku");
}
fn jscd(s: &String)->usize{
    s.len()
}