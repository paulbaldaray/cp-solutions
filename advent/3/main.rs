use std::io::{stdin, BufRead};
fn main() {
    let mut balance = Vec::new();
    for s in stdin().lock().lines() {
        for (i, x) in s.unwrap().chars().enumerate() {
            if i == balance.len() {
                balance.push(0);
            }
            balance[i] += if x == '1' { 1 } else { -1 };
        }
    };

    let (mut gamma, mut epsilon) = (0, 0);
    for c in balance {
        gamma *= 2;
        epsilon *= 2;
        if 2*c > 0 {
            gamma += 1;
        } else {
            epsilon += 1;
        }
    }

    println!("{}", gamma * epsilon);
}
