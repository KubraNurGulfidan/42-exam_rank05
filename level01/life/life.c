#include <unistd.h>
#include <stdlib.h>

static void printboard(char *board, int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
			putchar(board[y * w + x] ? '0' : ' ');
		putchar('\n');
	}
}

static int count_neighbor(char *board, int w, int h, int x, int y)
{
	int cnt = 0;
	for (int dy = -1; dy <= 1; dy++)
	{
		for (int dx = -1; dx <= 1; dx++)
		{
			if (dy == 0 && dx == 0)
				continue;;
			int nx = x + dx;
			int ny = y + dy;
			if(nx >= 0 && nx < w && ny >= 0 && ny < h)
				cnt += board[ny * w + nx] ? 1 : 0;
		}
	}
	return cnt;
}

static void step(char *board, char * next, int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int n = count_neighbor(board, w, h, x, y);
			if (board[y * w + x])
				next[y * w + x] = (n == 2 || n == 3);
			else
				next[y * w + x] = (n == 3);
		}
	}
}

int main(int ac, char **av)
{
	if(ac != 4)
		return 1;

	int w = atoi(av[1]);
	int h = atoi(av[2]);
	int iter = atoi(av[3]);

	char *board = calloc(w*h, 1);
	char *next = calloc(w*h, 1);

	if(!board || !next)
		return 1;

	int x = 0, y = 0, pen = 0;
	char c;

	while (read(0, &c, 1) > 0)
	{
		if(c == 'x')
			pen = !pen;
		if(c == 'a' && x > 0)
			x--;
		else if(c == 'd' && x < w -1)
			x++;
		else if(c == 'w' && y > 0)
			y--;
		else if(c == 's' && y < h -1)
			y++;
		if(pen)
			board[y * w + x] = 1;
	}

	for(int i = 0; i < iter; i++)
	{
		step(board, next, w, h);
		char *temp = board;
		board = next;
		next = temp;
	}
	
	printboard(board, w, h);

	free(board);
	free(next);
	return 0;
}