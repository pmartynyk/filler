/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:42:21 by pmartyny          #+#    #+#             */
/*   Updated: 2019/02/05 12:42:22 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	count_length(int row, int col, t_struct *t_str)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	while (i < t_str->plateau_row)
	{
		j = 0;
		while (j < t_str->plateau_col)
		{
			x = (i - row < 0 ? row - i : i - row);
			y = (j - col < 0 ? col - j : j - col);
			if (t_str->matr[i][j] != 0 && (t_str->matr[i][j] == -1 ||
				t_str->matr[i][j] > x + y))
				t_str->matr[i][j] = x + y;
			j++;
		}
		i++;
	}
}

void	re_line_plateau(char **str, char *line)
{
	int i;
	int j;

	j = 0;
	i = 4;
	while (line[i])
	{
		(*str)[j] = line[i];
		i++;
		j++;
	}
}

void	re_line_piece(char **str, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		(*str)[i] = line[i];
		i++;
	}
}

void	my_byzero(char **str, int cnt, int len)
{
	int i;
	int	j;

	j = 0;
	while (j < cnt)
	{
		i = 0;
		while (i < len)
		{
			str[j][i] = '\0';
			i++;
		}
		j++;
	}
}

void	byzero(char **str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		(*str)[i] = '\0';
		i++;
	}
}
