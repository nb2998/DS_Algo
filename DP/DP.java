package Lec11;

public class DP {

	static int fibBUSE(int n) {
		int[] strg = new int[2];
		strg[0] = 0;
		strg[1] = 1;

		for (int i = 2; i < n + 1; i++) {
			int temp = strg[0];
			strg[0] = strg[1];
			strg[1] = temp + strg[1];
		}

		return strg[1];
	}

	static int boardPathTD(int curr, int end, int[] strg) {
		if (curr > end)
			return 0;
		if (curr == end)
			return 1;

		int count = 0;

		if (strg[curr] != 0)
			return strg[curr];

		for (int dice = 1; dice <= 6; dice++) {
			count += boardPathTD(curr + dice, end, strg);
		}

		strg[curr] = count;
		return count;
	}

	static int boardPathBU(int curr, int end) {
		int[] strg = new int[end + 6];

		strg[end] = 1;

		for (int i = end - 1; i >= curr; i--) {
			strg[i] = strg[i + 1] + strg[i + 2] + strg[i + 3] + strg[i + 4] + strg[i + 5] + strg[i + 6];
		}

		return strg[curr];
	}

	static int boardPathBUSE(int curr, int end) {
		int[] strg = new int[6];

		strg[5] = 1;
		int sum = 1;
		for (int i = 4; i >= 0; i--) {
			strg[i] += sum;
			sum += strg[i];
		}

		for (int i = end - 6; i >= curr; i--) {
			int temp = strg[5];
			for (int j = 5; j >= 1; j--) {
				strg[j] = strg[j - 1];
			}
			strg[0] = strg[1] + strg[2] + strg[3] + strg[4] + strg[5] + temp;
		}

		return strg[0];
	}

	static int mazePathTD(int cr, int cc, int er, int ec, int[][] strg) {
		if (cr == er && cc == ec)
			return 1;
		if (cr > er || cc > ec)
			return 0;

		if (strg[cr][cc] != 0)
			return strg[cr][cc];

		int h = mazePathTD(cr, cc + 1, er, ec, strg);
		int v = mazePathTD(cr + 1, cc, er, ec, strg);

		strg[cr][cc] = h + v;
		return h + v;

	}

	static int mazePathBU(int cr, int cc, int er, int ec) {
		int[][] strg = new int[er + 1][ec + 1];
		strg[er][ec] = 1;

		for (int i = er; i >= 0; i--) {
			for (int j = ec; j >= 0; j--) {
				if (i == er || j == ec)
					strg[i][j] = 1;
				if (i != er && j != ec)
					strg[i][j] = strg[i + 1][j] + strg[i][j + 1];
			}
		}

		return strg[cr][cc];
	}

	static int mazePathBUSE(int cr, int cc, int er, int ec) {
		int[] strg = new int[er + 1];
		strg[er] = 1;
		for (int k = er; k >= cr; k--) {
			strg[k] = 1;
		}
		// int sum=1;
		for (int i = ec - 1; i >= 0; i--) {
			for (int j = er; j >= 0; j--) {
				if (j != er)
					strg[j] = strg[j] + strg[j + 1];

			}
		}
		return strg[cr];
	}

	static int mazePathDiagBUSE(int cr, int cc, int er, int ec) {
		int[] strg = new int[er + 1];
		strg[er] = 1;
		int diag = 1;
		for (int k = er; k >= cr; k--) {
			strg[k] = 1;
		}
		for (int i = ec - 1; i >= 0; i--) {
			for (int j = er; j >= 0; j--) {
				if (j != er) {
					int temp = strg[j];
					strg[j] = strg[j] + strg[j + 1] + diag;
					diag = temp;
				}
				if (j == er)
					diag = 1;
			}
		}
		return strg[cr];
	}

	static int LCSBU(String s1, String s2) {

		int[][] strg = new int[s1.length() + 1][s2.length() + 1];

		for (int i = 0; i < s1.length(); i++)
			strg[i][s2.length()] = 0;
		for (int i = 0; i < s2.length(); i++)
			strg[s1.length()][i] = 0;

		for (int i = s1.length() - 1; i >= 0; i--) {
			for (int j = s2.length() - 1; j >= 0; j--) {
				if (s1.charAt(i) == s2.charAt(j)) {
					strg[i][j] = strg[i + 1][j + 1] + 1;
				} else {
					strg[i][j] = Math.max(strg[i][j + 1], strg[i + 1][j]);
				}
			}
		}

		return strg[0][0];
	}

	public static void main(String[] args) {
		System.out.println(fibBUSE(5));
		int n = 10;
		System.out.println(boardPathTD(0, n, new int[n]));
		System.out.println(boardPathBU(0, n));
		System.out.println(boardPathBUSE(0, n));
		int s = 3;
		System.out.println(mazePathTD(0, 0, s, s, new int[s + 1][s + 1]));
		System.out.println(mazePathBU(0, 0, s, s));
		System.out.println(mazePathBUSE(0, 0, s, s));
		System.out.println(mazePathDiagBUSE(0, 0, s, s));

		System.out.println(LCSBU("abcd", "agchd"));
	}

}
