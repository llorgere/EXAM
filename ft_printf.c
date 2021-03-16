#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &(str[i]), i);
		i++;
	}
	return (i);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	char		*tmp;
	int			size_tab;
	char		**tab;
	int			i;
	int			j;

	i = 0;
	size_tab = 0;
	tmp = (char *)str;
	while (str[i] != '\0')
	{
		if(str[i] == '%')
		{
			if (i != 0)
				size_tab++;
			i++;
			while (str[i] != 's' && str[i] != 'i' && str[i] != 'x' && str[i] != '\0')
				i++;
			if (str[i] != '\0')
				size_tab++;
			else
				break;
		}
		i++;
	}
	i = 0;
	if (size_tab == 0)
	{
		return (ft_putstr(tmp));
	}
	else
	{
		if(!(tab = (char **)malloc((char *) * (size_tab + 1))))
			return (0);
		while (str[i] != '\0')
		{
			j = i;
			while (str[i] != '%')
				i++;
			if(str[i] == '%')
			{
				if (i != 0)
					size_tab++;
				i++;
				while (str[i] != 's' && str[i] != 'i' && str[i] != 'x' && str[i] != '\0')
					i++;
				if (str[i] != '\0')
					size_tab++;
				else
					break;
			}
			i++;
		}
	}
	va_start(ap, str);
}
