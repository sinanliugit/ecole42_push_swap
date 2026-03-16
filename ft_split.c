#include "push_swap.h"

// 5 functions
static int	count_words(const char *s, char c)
{
	int	inword;
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		inword = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			inword = 1;
		}
		if (inword == 1)
			count++;
	}
	return (count);
}

static char	*fill_word(const char *s, int len, int start)
{
	char	*word;
	int		i;
	int		w;

	i = start;
	w = 0;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (s[i] && w < len)
		word[w++] = s[i++];
	word[w] = '\0';
	return (word);
}

static char	**ft_free(char **tab, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	**do_malloc(char const *s, char c)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

// the following index i is for the original big string,
// 	q is for each seperated word; in the end , we need mke tab[q] = 0/NULL,
// 	if not , seg fault
char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		q;
	int		i;
	int		len;

	q = 0;
	i = 0;
	tab = do_malloc(s, c);
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
		tab[q] = fill_word(s, len, i - len);
		if (!tab[q])
			return (ft_free(tab, q));
		q++;
	}
	tab[q] = 0;
	return (tab);
}

// int	main(void)
// {
// 	char	**tab;

// 	tab = ft_split(" 1 2  45",' ');
// 	for (int i = 0; i <= count_words("salut a tous",' '); i++)
// 	{
// 		printf ("%s\n", tab[i]);
// 	}
// }
