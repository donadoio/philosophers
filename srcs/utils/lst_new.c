/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/02 20:44:38 by lwray         #+#    #+#                 */
/*   Updated: 2021/10/08 11:40:18 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_philo	*lst_philo_new(t_data *data, int i)
{
	t_philo	*node;

	node = (t_philo *)malloc(sizeof(t_philo));
	if (!node)
		return (NULL);
	node->fork = 1;
	node->data = data;
	node->num = i;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}
