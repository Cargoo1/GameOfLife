/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gof.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:06:48 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/11/18 18:26:38 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gof.h"
#include <stddef.h>
#include <stdio.h>

void	display_map(int **map, size_t rows_len, size_t cols_len)
{
	for (size_t rows = 0; rows < rows_len; ++rows)
	{
		for (size_t cols = 0; cols < cols_len; ++cols)
		{
			if (map[rows][cols] == 1)
				putchar('O');
			else if (map[rows][cols] == 0)
				putchar(' ');
		}
		putchar('\n');
	}
}

void	gof(int	**map, size_t rows_len, size_t cols_len, size_t ticks)
{
	int		directions[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
	for (size_t i = 0; i < ticks; ++i)
	{
		for (size_t rows = 0; rows < rows_len; ++rows)
		{
			for (size_t cols = 0; cols < cols_len; ++cols)
			{
				int	alive = 0;
				for (size_t j = 0; j < 8; ++j)
				{
					int	x = rows + directions[j][0];
					int y = cols + directions[j][1];
					if (x < 0 || x >= (int)rows_len || y < 0 || y >= (int)cols_len)
						continue;
					if (map[x][y] == 1)
						++alive;
				}
				if (map[rows][cols] == 1 && (alive < 2 || alive > 3))
					map[rows][cols] = -1;
				else if (map[rows][cols] == 0 && alive == 3)
					map[rows][cols] = 2;
			}
		}
		for (size_t rows = 0; rows < rows_len; ++rows)
		{
			for (size_t cols = 0; cols < cols_len; ++cols)
			{
				if (map[rows][cols] == -1)
					map[rows][cols] = 0;
				else if (map[rows][cols] == 2)
					map[rows][cols] = 1;
			}
		}
	}
	display_map(map, rows_len, cols_len);
}
