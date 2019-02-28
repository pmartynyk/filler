/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:27:02 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/31 17:27:03 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	craete_int_matr(t_struct *t_str)
{
	int i;
	int j;

	i = 0;
	t_str->matr = (int **)malloc(sizeof(int *) * t_str->plateau_row);
	while (i < t_str->plateau_row)
	{
		j = 0;
		t_str->matr[i] = (int *)malloc(sizeof(int) * t_str->plateau_col);
		while (j < t_str->plateau_col)
		{
			t_str->matr[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	fill_enemy_matr(t_struct *t_str)
{
	int		i;
	int		j;
	char	symb_l;
	char	symb_s;

	i = 0;
	symb_l = (t_str->player_symbols[0] == 'o' ? 'x' : 'o');
	symb_s = (t_str->player_symbols[1] == 'O' ? 'X' : 'O');
	while (i < t_str->plateau_row)
	{
		j = 0;
		while (j < t_str->plateau_col)
		{
			if (t_str->plateau[i][j] == symb_l ||
				t_str->plateau[i][j] == symb_s)
				t_str->matr[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	fill_length(t_struct *t_str)
{
	int		i;
	int		j;

	i = 0;
	while (i < t_str->plateau_row)
	{
		j = 0;
		while (j < t_str->plateau_col)
		{
			if (t_str->matr[i][j] == 0)
				count_length(i, j, t_str);
			j++;
		}
		i++;
	}
}

void	print_cord(void)
{
	ft_putnbr(g_row);
	ft_putchar(' ');
	ft_putnbr(g_col);
	ft_putchar('\n');
}

void	zero_cord(void)
{
	g_row = 0;
	g_col = 0;
	g_val = 0;
}
