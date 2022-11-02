/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:24:39 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:01:34 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Alloue et retourne un tableau de chaines de caracteres obtenu en 
	separant 's' a l'aide du caractere 'c' utilise comme delimeteur 
*/

static	int	ft_count_words(char const *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
		{
			words++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (words);
}

static int	ft_size_of_word(char const *s, char c, int start)
{
	int	size;

	size = start + 1;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

static	char	*ft_create_words(char const *str, int start, int end)
{
	char	*string;
	int		i;

	string = (char *)malloc(sizeof(char) * ((end - start) + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (start < end)
	{
		string[i] = str[start];
		i++;
		start++;
	}
	string[i] = '\0';
	return (string);
}

static char	**ft_free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		index_tab;
	int		start;
	int		end;

	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	index_tab = -1;
	start = 0;
	end = 0;
	while (++index_tab < ft_count_words(s, c))
	{
		while (s[start] && s[start] == c)
			start++;
		if (s[start] && s[start] != c)
			end = ft_size_of_word(s, c, start);
		tab[index_tab] = ft_create_words(s, start, end);
		if (!tab[index_tab])
			return (ft_free_tab(tab, index_tab));
		start = end;
	}
	tab[index_tab] = 0;
	return (tab);
}
