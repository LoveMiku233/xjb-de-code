struct Miku {
    name: String,
    weight: f32,
    height: f32,
}
//方法 impl &self类似this指针
impl Miku {
    fn get_name(&self) -> &str {
        //String是分配在堆中，所以使用引用
        &(self.name[..])
    }
    fn get_weight(&self) -> f32 {
        self.weight
    }
    fn get_height(&self) -> f32 {
        self.height
    }
}

fn PrintStr(s: String) {
    println!("{}", s);
}

fn Printfloat(fone: f32) {
    println!("{}", fone);
}

fn main() {
    let User = Miku {
        name: String::from("Yankai"),
        weight: 3.12,
        height: 4.2,
    };
    let name1 = User.get_name();
    let w = User.get_weight();
    let h = User.get_height();

    println!("{}", name1);
    Printfloat(w);
    Printfloat(h);
}
