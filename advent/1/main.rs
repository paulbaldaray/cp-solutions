use std::io::{stdin, BufRead};
fn main() {
    let mut count = 0;
    let mut p = (0, 0, 0);
    for (i, x) in stdin().lock().lines()
            .map(|s| s.unwrap().trim().parse().unwrap())
            .enumerate() {
        if i > 2 && x > p.2 {
            count += 1;
        }
        p = (x, p.0, p.1);
    }
    println!("{}", count);
}
