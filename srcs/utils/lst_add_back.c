/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_add_back.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/02 20:44:27 by lwray         #+#    #+#                 */
/*   Updated: 2021/10/08 12:00:31 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_philo	**lst_philo_add_back(t_philo **list, t_philo *new)
{
	t_philo	*last;

	if (new == NULL)
		return ((void *) NULL);
	if (*list)
	{
		last = lst_philo_last(*list);
		if (last)
		{
			new->previous = last;
			last->next = new;
		}
	}
	else if (list)
		*list = new;
	return (list);
}
