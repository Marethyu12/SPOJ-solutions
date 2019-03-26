import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;

import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class SPIKES implements Runnable {
	private BufferedReader reader;
	private StringTokenizer tokenizer;
	private PrintWriter out;
	
	private int n;
	private int m;
	private int j;
	
	private Cell[][] maze;
	
	public static void main(String[] args) {
		new Thread(new SPIKES()).start();
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
		List<Cell> list = new ArrayList<>();
		
		boolean flag = false;
		
		n = nextInt();
		m = nextInt();
		j = nextInt();
		
		maze = new Cell[n][m];
		
		for (int i = 0; i < n; ++i) {
			String row = nextToken();
			
			for (int k = 0; k < m; ++k) {
				char id = row.charAt(k);
				
				if (id == '@') {
					list.add(new Cell(i, k, id));
				}
				
				maze[i][k] = new Cell(i, k, id);
			}
		}
		
		for (Cell entry : list) {
			if (dfs(entry.row, entry.col, new boolean[n][m], j, false)) {
				flag = true;
				break;
			}
		}
		
		if (flag) {
			out.println("SUCCESS");
		} else {
			out.println("IMPOSSIBLE");
		}
	}
	
	private boolean dfs(int row, int col, boolean[][] map, int lives, boolean discovered) {
		if (!inBounds(row, col) || map[row][col] || maze[row][col].id == '#') {
			return false;
		}
		
		if (maze[row][col].id == 's' && --lives < 0) {
			return false;
		}
		
		if (maze[row][col].id == 'x') {
			discovered = true;
			
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < m; ++y) {
					if (map[x][y]) {
						map[x][y] = false;
					}
				}
			}
			
			map[row][col] = true;
		}
		
		if (maze[row][col].id == '@' && discovered) {
			return true;
		}
		
		map[row][col] = true;
		
		return dfs(row + 1, col, map, lives, discovered) || dfs(row - 1, col, map, lives, discovered) || dfs(row, col + 1, map, lives, discovered) || dfs(row, col - 1, map, lives, discovered);
	}
	
	private boolean inBounds(int row, int col) {
		return (row >= 0 && row < n) && (col >= 0 && col < m);
	}
	
	private class Cell {
		public int row;
		public int col;
		
		public char id;
		
		public Cell(int row, int col, char id) {
			this.row = row;
			this.col = col;
			this.id = id;
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
		if (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		
		return tokenizer.nextToken();
	}
}