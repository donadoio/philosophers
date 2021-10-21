/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:35:53 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/21 21:35:55 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_str_isnum(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
