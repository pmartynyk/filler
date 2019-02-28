/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:08:16 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/31 16:08:19 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		fill_t_struct(t_struct *t_str)
{
	int		end;
	char	*line;

	end = 0;
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			fill_plateau_size(t_str, &line);
		else if (ft_strstr(line, "Piece"))
		{
			fill_piece_size(t_str, &line);
			find_coordinates(t_str);
			if (g_val == 0)
				return (-1);
			zero_cord();
		}
		else
		{
			if (line != NULL)
				free(line);
			return (-1);
		}
	}
	return (0);
}

int		main(void)
{
	t_struct	t_str;

	t_str.plateau = NULL;
	t_str.piece = NULL;
	t_str.matr = NULL;
	zero_cord();
	check_and_fill_player(&t_str);
	while (1)
	{
		if (fill_t_struct(&t_str) == -1)
			return (0);
	}
	return (0);
}
