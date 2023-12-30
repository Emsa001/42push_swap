#include "../includes/libft/libft.h"
#include "checker.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// delete line find
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find len of first line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if eol == \0 return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// len of file - len of firstline + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// line == buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

// take line for return
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	// if no line return NULL
	if (!buffer[i])
		return (NULL);
	// go to the eol
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// malloc to eol
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// line = buffer
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// if eol is \0 or \n, replace eol by \n
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	// malloc if res dont exist
	if (!res)
		res = ft_calloc(1, 1);
	// malloc buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		// while not eof read
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// 0 to end for leak
		buffer[byte_read] = 0;
		// join and free
		res = ft_free(res, buffer);
		// quit if \n find
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	// error handling
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	show_results(t_stacks *stacks)
{
	int	i;

	i = 0;
	printf("Stack A: ");
	while (i < stacks->a->size)
	{
		printf("%d ", stacks->a->arr[i]);
		i++;
	}
	printf("\nStack B: ");
	i = 0;
	while (i < stacks->b->size)
	{
		printf("%d ", stacks->b->arr[i]);
		i++;
	}
	printf("\n");
}

// TODO: norminette | read args
int main(int nb, char **args){
	char *line;
	int fd = STDIN_FILENO;

	t_stacks	*stacks;
	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		ft_error("Error: malloc failed", NULL);

	// Init stack
	init_stacks(&stacks);

	read_args(nb, args, &stacks);


	while ((line = get_next_line(fd)) != NULL)
	{
		if(ft_strcmp(line, "sa\n") == 0)
			sb(stacks->a);
		else if(ft_strcmp(line, "sb\n") == 0)
			sb(stacks->b);
		else if(ft_strcmp(line, "ss\n") == 0)
			ss(stacks);
		else if(ft_strcmp(line, "pa\n") == 0)
			pa(stacks);
		else if(ft_strcmp(line, "pb\n") == 0)
			pb(stacks);
		else if(ft_strcmp(line, "ra\n") == 0)
			ra(stacks->a);
		else if(ft_strcmp(line, "rb\n") == 0)
			rb(stacks->b);
		else if(ft_strcmp(line, "rr\n") == 0)
			rr(stacks);
		else if(ft_strcmp(line, "rra\n") == 0)
			rra(stacks->a);
		else if(ft_strcmp(line, "rrb\n") == 0)
			rrb(stacks->b);
		else if(ft_strcmp(line, "rrr\n") == 0)
			rrr(stacks);
		else
			printf("Error: |%s|\n", line);
		free(line);
	}

	if (is_sorted(stacks->a) && stacks->b->size == 0)
		printf("OK\n");
	else
		printf("KO\n");
	
	// show_results(stacks);
	return (0);
}