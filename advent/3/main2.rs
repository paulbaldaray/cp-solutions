use std::io::{stdin, BufRead};
fn main() {
    let mut nums = stdin().lock().lines()
        .map(|s| s.unwrap().chars().collect::<Vec<char>>())
        .collect::<Vec<Vec<char>>>();
    let (m, n) = (nums.len(), nums[0].len());
    let calc = |most| -> i32 {
        let (mut has, mut last) = (vec![true; m], 0);
        for j in 0..n {
            let mut bal = 0;
            for i in 0..m {
                if has[i] {
                    bal += if nums[i][j] == '1' { 1 } else { -1 };
                }
            }
            for i in 0..m {
                if most ^ (bal >= 0) ^ (nums[i][j] == '1') {
                    has[i] = false;
                } else if has[i] {
                    last = i;
                }
            }
        }
        let mut ans = 0;
        for c in &nums[last] {
            ans = if *c == '1' { 2*ans + 1 } else { 2* ans };
        }
        ans
    };
    println!("{}", calc(true) * calc(false));
}
