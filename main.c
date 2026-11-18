/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:05:45 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/11/18 18:33:38 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gof.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int**	create_map(size_t rows, size_t cols)
{
	int**	map = malloc(sizeof(int*) * (rows));
	for (size_t i = 0; i < rows; ++i)
	{
		map[i] = malloc(sizeof(int) * cols);
		for (size_t j = 0; j < cols; ++j)
			map[i][j] = 0;
	}
	return map;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return 1;
	size_t	rows_len = atoi(argv[2]);
	size_t	cols_len = atoi(argv[1]);
	int	**map = create_map(rows_len, cols_len);
	int	x = 0, y = 0, is_pencil_down = 0;
	char	move;
	while (read(0, &move, 1))
	{
		putchar(move);
		switch (move)
		{
			case 'w':
				y--;
				break;
			case 'a':
				x--;
				break;
			case 's':
				y++;
				break;
			case 'd':
				x++;
				break;
			case 'x':
				is_pencil_down = !is_pencil_down;
				break;
			case '\n':
				continue;
				break;
			default:
				return 2;
		}
		if (y < (int)rows_len && y >= 0 && x < (int)cols_len && x >= 0)
			map[y][x] = is_pencil_down;
	}
	gof(map, rows_len, cols_len, atoi(argv[3]));
}
