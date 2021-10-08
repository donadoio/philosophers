/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_last.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/02 20:44:32 by lwray         #+#    #+#                 */
/*   Updated: 2021/10/08 11:31:39 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_philo	*lst_philo_last(t_philo *last)
{
	if (last == NULL)
		return (NULL);
	while ((last->next) != NULL)
		last = (last->next);
	return (last);
}

