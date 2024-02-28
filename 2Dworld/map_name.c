/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:59:33 by vpechinn          #+#    #+#             */
/*   Updated: 2024/02/21 19:50:25 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_name_map(char *argv)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(argv) - 1;
	if (argv[k] == 'r')
		i++;
	if (argv[k - 1] == 'e')
		i++;
	if (argv[k - 2] == 'b')
		i++;
	if (argv[k - 3] == '.')
		i++;
	if (i != 4)
	{
		write(2, "Erorr'\n Wrong File\n", 18);
		exit (0);
	}
	return (1);
}