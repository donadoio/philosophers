/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 16:58:01 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/21 21:35:48 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	return ;
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n <= -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
	}
}

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

uint64_t	ft_time(void)
{
	struct timeval	time;
	uint64_t		result;

	if (gettimeofday(&time, 0) < 0)
	{
		error("\033[1m\033[31mFailed to retrieve time using \
gettimeofday().\033[39m");
		return (-42);
	}
	result = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (result);
}
