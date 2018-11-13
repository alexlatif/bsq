
#include "snap.h"
#include "board_info.h"

int		find_swipe(char **matrix, char obstacle, int x, int y, int swipe)
{
	int i;
	int j;

	if (matrix[0][x + 1 + swipe] && matrix[y + 1 + swipe] && matrix[y][x] != obstacle)
	{
		i = y;
		while (i < y + 1 + swipe)
		{
			if (matrix[i][x + 1 + swipe] == obstacle)
				return swipe;
			i++;
		}

		j = x;
		while (j <= x + 1 + swipe)
		{
			if (matrix[i][j] == obstacle)
				return swipe;
			j++;
		}
		swipe++;
		return (find_swipe(matrix, obstacle, x, y, swipe));
	}
	else
		return swipe;
}

t_snap	find_snapshot(char **matrix, t_board binfo)
{
	t_snap			snapshot;
	unsigned int	i;
	int				j;
	int				swipe;

	snapshot.x = 0;
	snapshot.y = 0;
	snapshot.swipe = 0;
	i = 0;
	while (i < binfo.lines - 1)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			swipe = find_swipe(matrix, binfo.obstacle, j, i, 0);
			if (swipe > snapshot.swipe)
			{
				snapshot.x = j;
				snapshot.y = i;
				snapshot.swipe = swipe;
			}
			j++;
		}
		i++;
	}
	return (snapshot);
}

char **fill_matrix(char **matrix, t_snap snapshot, char full)
{
	int i;
	int j;

	i = snapshot.y;
	while (i <= snapshot.y + snapshot.swipe)
	{
		j = snapshot.x;
		while (j <= snapshot.x + snapshot.swipe)
		{
			matrix[i][j] = full;
			j++;
		}
		i++;
	}

	return (matrix);
}

char	**solve_matrix(char **matrix, t_board binfo)
{
	t_snap			snapshot;

	snapshot = find_snapshot(matrix, binfo);
	printf("arr[%d][%d] = %d swipes\n", snapshot.y, snapshot.x, snapshot.swipe);

	fill_matrix(matrix, snapshot, binfo.full);

	return matrix;
}