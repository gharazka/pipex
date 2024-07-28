/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:28:36 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/28 20:11:39 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_for_separated(char a, char c)
{
	if (a == c)
		return (1);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && check_for_separated(s[i], c))
			i++;
		while (s[i] && !check_for_separated(s[i], c))
			i++;
		count++;
	}
	if (i > 0 && check_for_separated(s[i - 1], c))
		count--;
	return (count);
}

static int	ft_sep_strlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (check_for_separated(s[i], c))
			break ;
		i++;
	}
	return (i);
}

static char	*make_word(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (ft_sep_strlen(s, c) + 1));
	while (s[i] && !check_for_separated(s[i], c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**words;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!words)
		return (NULL);
	while (s[i])
	{
		if (!check_for_separated(s[i], c))
		{
			words[k] = make_word(&s[i], c);
			k++;
			while (s[i] && !check_for_separated(s[i], c))
				i++;
		}
		else
			i++;
	}
	words[k] = NULL;
	return (words);
}
