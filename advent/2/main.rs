use std::io::{stdin, BufRead};
fn main() {
    let mut a = 0;
    let mut x = 0;
    let mut y = 0;
    for s in stdin().lock().lines().map(|s| s.unwrap()) {
        let mut it = s.split(" ");
        let d = it.next().unwrap();
        let v: i32 = it.next().unwrap().trim().parse().unwrap();
        if d == "forward" {
            x += v;
            y += v*a;
        } else if d == "down" {
            a += v;
        } else if d == "up" {
            a -= v;
        }
    };
    println!("{}", x * y);
}
