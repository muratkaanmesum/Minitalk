/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:27:20 by mmesum            #+#    #+#             */
/*   Updated: 2022/11/18 15:05:44 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
	int		j;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	ft_printf("%d", pid);
	i = 0;
	while (argv[2][i])
	{
		j = 0;
		while (j < 8)
		{
			if (argv[2][i] & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(100);
		}
		i++;
	}
	return (0);
}
