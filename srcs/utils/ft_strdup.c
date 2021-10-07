/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/02 20:43:41 by lwray         #+#    #+#                 */
/*   Updated: 2021/10/07 19:33:49 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;
	int		src_len;

	if (src == NULL)
		return (NULL);
	src_len = ft_strlen(src);
	dup = malloc(src_len + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
