fn main() {
    let x:i32=6;
    {
        let y:i32=9;
        println!("{}",y);
    }
    println!("{}",x);
    {
        let mut s1=String::from("miku");
        let s2 = s1;//s1 无效
        println!("{}",s2);
        //clone方法
        let s3= s2.clone();
        println!("{},{}",s2,s3);
    }
    //copy 特征
    //所有的整型
    //浮点型
    //布尔值
    //char
    //
    let a=1;
    let b=a;
    println!("{},{}",a,b);//在栈上直接复制
    let l:char='m';
    let k=l;
    println!("{},{}",l,k);//在栈上直接复制


}