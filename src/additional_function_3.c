/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:41:23 by pmartyny          #+#    #+#             */
/*   Updated: 2019/02/19 11:41:26 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		fill_plateau_first(t_struct *t_str)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (!(t_str->plateau =
		(char **)malloc(sizeof(char *) * t_str->plateau_row)))
		return (-1);
	while (i < t_str->plateau_row)
	{
		if (get_next_line(0, &line) < 0)
			return (-1);
		t_str->plateau[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	return (0);
}

int		fill_piece_first(t_struct *t_str)
{
	char	*line;
	int		i;

	i = -1;
	if (!(t_str->piece =
		(char**)malloc(sizeof(char*) * t_str->plateau_row)))
		return (-1);
	while (++i < t_str->piece_row)
	{
		get_next_line(0, &line);
		if (!(t_str->piece[i] =
			(char*)malloc(sizeof(char) * t_str->plateau_col)))
			return (-1);
		byzero(&t_str->piece[i], t_str->plateau_col);
		re_line_piece(&t_str->piece[i], line);
		ft_strdel(&line);
	}
	i--;
	while (++i < t_str->plateau_row)
	{
		if (!(t_str->piece[i] = (char*)malloc(t_str->plateau_col)))
			return (-1);
		byzero(&t_str->piece[i], t_str->plateau_col);
	}
	return (0);
}

int		check_invalid_position(char plateau_pos, char piece_pos, t_struct t_str)
{
	char	symb_l;
	char	symb_s;

	symb_l = (t_str.player_symbols[0] == 'o' ? 'x' : 'o');
	symb_s = (t_str.player_symbols[1] == 'O' ? 'X' : 'O');
	if ((plateau_pos == symb_l || plateau_pos == symb_s) && piece_pos == '*')
		return (-1);
	else
		return (0);
}

int		check_valid_position(char plateau_pos, char piece_pos, t_struct t_str)
{
	char	symb_l;
	char	symb_s;

	symb_l = t_str.player_symbols[1];
	symb_s = t_str.player_symbols[0];
	if ((plateau_pos == symb_l || plateau_pos == symb_s) && piece_pos == '*')
		return (0);
	else
		return (-1);
}

void	fill_cord(int val, int counter, int row, int col)
{
	if (counter == 1 && (g_val == 0 || g_val > val))
	{
		g_row = row;
		g_col = col;
		g_val = val;
	}
}
