/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/02 20:43:50 by lwray         #+#    #+#                 */
/*   Updated: 2021/10/07 18:59:33 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	int		i;
	int		j;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	joined_str = (char *)malloc(len + 1);
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		joined_str[i] = s1[i];
		i++;
	}
	while ((i + j) < len)
	{
		joined_str[i + j] = s2[j];
		j++;
	}
	joined_str[i + j] = '\0';
	return (joined_str);
}
