# KB-F_05111840000008

Anggara Yuda Pratama - 05111840000008  
Teknik Informatika - Fakultas Teknologi Elektro & Informatika Cerdas  
Institut Teknologi Sepuluh Nopember Surabaya

### Daftar Tugas
* [1.1 8-Puzzle BFS](https://github.com/anggarayp/KB-F_05111840000008#11-8-puzzle-bfs)
* [1.2 8-Puzzle DFS](https://github.com/anggarayp/KB-F_05111840000008#12-8-puzzle-dfs)
* [1.3 8-Puzzle IDS](https://github.com/anggarayp/KB-F_05111840000008#13-8-puzzle-ids)
* [1.4 8-Queen](https://github.com/anggarayp/KB-F_05111840000008#14-8-queen)
* [2.1 Heuristic-1]()
* [2.2 Heuristic-2]()
* [2.3 8-Queen_Hill Climbing]()
* [3. Minimax - TicTacToe]()
* [4. 4-Queen](https://github.com/anggarayp/KB-F_05111840000008#4-4-queen)

### 1.1 8-Puzzle BFS
BFS `(Breadth-First Search)` adalah algoritma yang melakukan pencarian secara melebar yang mengunjungi simpul secara preorder yaitu mengunjungi suatu simpul kemudian mengunjungi semua simpul yang bertetangga dengan simpul tersebut terlebih dahulu.

BFS menggunakan struktur data `queue` yang merupakan struktur data `First In`, `First Out` atau `FIFO`. Antrian ini menyimpan semua node yang harus kita jelajahi dan setiap kali sebuah node dieksplorasi ditambahkan ke set node yang dikunjungi.


### 1.2 8-Puzzle DFS

### 1.3 8-Puzzle IDS

### 1.4 8-Queen
[kodingan](https://github.com/anggarayp/KB-F_05111840000008/blob/master/1.4%208-Queen/8queen.cpp)

Awal-awal kita define N = 8, karena problemnya adalah 8-queen
```c
/* C/C++ program to solve N Queen Problem using 
backtracking */
#define N 4
#include <stdbool.h> 
#include <stdio.h> 
```

ld merupakan sebuah array di mana indeksnya mengindikasikan baris-col + N-1 (N-1) adalah untuk menggeser perbedaan untuk menyimpan indeks negatif. Sedangkan rd merupakan sebuah array di mana indeksnya mengindikasikan baris + col dan digunakan untuk memeriksa apakah seorang ratu dapat ditempatkan di diagonal kanan atau tidak. Untuk cl sendiri merupakan array kolom di mana indeksnya menunjukkan kolom dan digunakan untuk memeriksa apakah seorang ratu dapat ditempatkan di baris itu atau tidak
```c
int ld[30] = { 0 }; 

int rd[30] = { 0 }; 

int cl[30] = { 0 }; 
```

Fungsi utilitas rekursif untuk menyelesaikan problem N-Queen
```c
bool solveNQUtil(int board[N][N], int col) { 
	if (col >= N) 
		return true; 
    
	for (int i = 0; i < N; i++) { 
		if ((ld[i - col + N - 1] != 1 && 
				rd[i + col] != 1) && cl[i] != 1) { 
			
			board[i][col] = 1; 
			ld[i - col + N - 1] = 
						rd[i + col] = cl[i] = 1; 

	
			if (solveNQUtil(board, col + 1)) 
				return true; 
        
			board[i][col] = 0; // BACKTRACK 
			ld[i - col + N - 1] = 
						rd[i + col] = cl[i] = 0; 
		} 
	} 
	return false; 
}
```

Fungsi ini memecahkan masalah N Queen menggunakan Backtracking. Ini terutama menggunakan resolNQUtil () untuk menyelesaikan masalah. Ini mengembalikan false jika ratu tidak dapat ditempatkan, jika tidak, kembalikan benar dan mencetak penempatan ratu dalam bentuk 1s. Harap dicatat bahwa mungkin ada lebih dari satu solusi, fungsi ini mencetak salah satu solusi yang layak.
```c
bool solveNQ() { 
	int board[N][N] = { { 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 } }; 

	if (solveNQUtil(board, 0) == false) { 
		printf("Solution does not exist"); 
		return false; 
	} 

	printSolution(board); 
	return true; 
} 
```

Program driver untuk menguji fungsi di atas
```c
int main() { 
	solveNQ(); 
	return 0; 
} 
 ```

**Hasil : **

![](Screenshots/hasil_8queen.jpg)

### 4. 4-Queen
Penjelasan kodingannya sama seperti [8-Queen](https://github.com/anggarayp/KB-F_05111840000008#14-8-queen), hanya saja N-nya di define = 4

```c
/* C/C++ program to solve N Queen Problem using 
backtracking */
#define N 4
#include <stdbool.h> 
#include <stdio.h> 
```

**Hasil : **

![](Screenshots/hasil_4queen.jpg)
