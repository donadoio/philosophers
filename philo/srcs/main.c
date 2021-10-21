/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:37:58 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/21 21:38:19 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	format_check(char	**argv)
{
	if (!ft_str_isnum(argv[1]))
		return (0);
	if (!ft_str_isnum(argv[2]))
		return (0);
	if (!ft_str_isnum(argv[3]))
		return (0);
	if (!ft_str_isnum(argv[4]))
		return (0);
	if (argv[5])
		if (!ft_str_isnum(argv[5]))
			return (0);
	return (1);
}

int	argc_check(int argc)
{
	if (argc == 5)
		return (1);
	else if (argc == 6)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc_check(argc) == 0)
		return (1);
	if (format_check(argv) == 0)
		return (1);
	data = data_init();
	parse_data(argc, argv, &data);
	if (program_init(&data) == 0)
		return (1);
	if (routine_init(&data) == 0)
		return (1);
	return (0);
}
