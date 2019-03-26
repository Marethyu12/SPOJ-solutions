import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;

import java.util.StringTokenizer;

public class ALCATRAZ3 implements Runnable {
	private BufferedReader reader;
	private StringTokenizer tokenizer;
	private PrintWriter out;
	
	private int N;
	private int M;
	private Vertex[][] grid;
	private Vertex start;
	private int k;
	private boolean flag;
	
	public static void main(String[] args) {
		new Thread(new ALCATRAZ3()).start();
	}
	
	public void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			out = new PrintWriter(System.out);
			solve();
			reader.close();
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(1);
		}
	}
	
	private void solve() throws IOException {
		N = nextInt();
		M = nextInt();
		
		grid = new Vertex[N][M];
		
		k = nextInt();
		
		start = new Vertex(nextInt() - 1, nextInt() - 1, false);
		
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				grid[i][j] = new Vertex(i, j, nextToken().equals("*"));
			}
		}
		
		flag = false;
		
		dfs(start.x, start.y, 0, new boolean[N][M]);
		
		out.println(flag ? "YES" : "NO");
	}
	
	private void dfs(int x, int y, int steps, boolean[][] map) {
		if (steps >= k && x == start.x && y == start.y) {
			flag = true;
			
			return;
		}
		
		if (x < 0 || x > N - 1 || y < 0 || y > M - 1 || map[x][y] || grid[x][y].blocked) {
			//System.err.println("I am at step " + steps + ", at (" + (x + 1) + ", " + (y + 1) + ")" + ", oh fuck! I have to go back...");
			
			return;
		}
		
		map[x][y] = true;
		
		//System.err.println("I am at step " + steps + ", at (" + (x + 1) + ", " + (y + 1) + ")");
		
		dfs(x - 1, y, steps + 1, map);
		dfs(x + 1, y, steps + 1, map);
		dfs(x, y + 1, steps + 1, map);
		dfs(x, y - 1, steps + 1, map);
		
		map[x][y] = false;
		
		//System.err.println("I am back to step " + steps + ", at (" + (x + 1) + ", " + (y + 1) + ")");
	}
	
	private class Vertex {
		public int x;
		public int y;
		public boolean blocked;
		
		public Vertex(int x, int y, boolean blocked) {
			this.x = x;
			this.y = y;
			this.blocked = blocked;
		}
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		
		return tokenizer.nextToken();
	}
}