import java.io.*;
import java.util.*;
public class Main {
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try { 
					st=new StringTokenizer(br.readLine());
				}catch (IOException e) {}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
	static boolean kmp(int[] lps, String s, String p) {
		Arrays.fill(lps, 0);
		for (int i = 1, j = 0; i < p.length(); ++i) {
			while (j > 0 && p.charAt(j) != p.charAt(i))
				j = lps[j-1];
			if (p.charAt(j) == p.charAt(i))
				lps[i] = ++j;
		}
		for (int i = 0, j = 0; i < s.length(); ++i) {
			while (j > 0 && p.charAt(j) != s.charAt(i))
				j = lps[j-1];
			if (p.charAt(j) == s.charAt(i))
				++j;
			if (j == p.length())
				return true;
		}
		return false;
	}
	public static void main(String[] args) {
		PrintWriter out = new PrintWriter(System.out);
		var sc = new FastScanner();
		int N = sc.nextInt();
		var substrings = new HashSet<String>();
        var first = sc.next();
        for (int i = 0; i < first.length(); ++i)
            for (int j = i; j < first.length(); ++j)
                substrings.add(first.substring(i, j+1));
		var lps = new int[100];
		for (int i = 0; i < N-1; ++i) {
			var s = sc.next();
			var nextSubstrings = new HashSet<String>();
			for (var p : substrings)
				if (kmp(lps, s, p))
					nextSubstrings.add(p);
			substrings = nextSubstrings;
		}
		int high = 0;
		for (var s : substrings)
			if (s.length() > high)
				high = s.length();
		out.println(high);
		out.close();
	}
}
