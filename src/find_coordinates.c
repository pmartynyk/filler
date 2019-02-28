/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:44:37 by pmartyny          #+#    #+#             */
/*   Updated: 2019/02/04 14:44:39 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include <stdio.h>

int		count_enemy(t_struct *t_str)
{
	int		i;
	int		j;
	int		count;
	char	symb_l;
	char	symb_s;

	i = -1;
	count = 0;
	symb_l = (t_str->player_symbols[0] == 'o' ? 'x' : 'o');
	symb_s = (t_str->player_symbols[1] == 'O' ? 'X' : 'O');
	while (++i < t_str->plateau_row)
	{
		j = -1;
		while (++j < t_str->plateau_col)
			if (t_str->plateau[i][j] == symb_l
				|| t_str->plateau[i][j] == symb_s)
				count++;
	}
	return (count);
}

void	find_coordinates(t_struct *t_str)
{
	int			i;
	int			j;
	static int	x = 0;
	int			y;

	i = -1;
	y = 0;
	if (t_str->matr == NULL)
		craete_int_matr(t_str);
	if ((y = count_enemy(t_str)) > x)
	{
		fill_enemy_matr(t_str);
		fill_length(t_str);
		x = y;
	}
	while (++i < t_str->plateau_row)
	{
		j = -1;
		while (++j < t_str->plateau_col)
			check_coordinates(*t_str, i, j);
	}
	print_cord();
}

int		validation(char c, char a, t_struct t_str, int *counter)
{
	if (c == '\0')
		return (1);
	if (check_invalid_position(c, a, t_str) == -1)
		return (1);
	if (check_valid_position(c, a, t_str) == 0)
		(*counter)++;
	if (*counter > 1)
		return (1);
	return (0);
}

void	check_coordinates(t_struct t_str, int row, int col)
{
	int		i;
	int		j;
	int		counter;
	int		val;

	i = -1;
	counter = 0;
	val = 0;
	while (++i < t_str.piece_row)
	{
		j = -1;
		if (row + i >= t_str.plateau_row)
			return ;
		while (++j < t_str.piece_col)
		{
			if (validation(t_str.plateau[row + i][col + j],
				t_str.piece[i][j], t_str, &counter) == 1)
				return ;
			if (t_str.piece[i][j] == '*')
				val += t_str.matr[row + i][col + j];
		}
	}
	fill_cord(val, counter, row, col);
}
