#include "inc/libft.h"

static int	num_len(int n)
{
	int 	len;
	
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

t_matrix	*add_matrix(t_matrix *left, t_matrix *right)
{
	t_matrix	*matrix = NULL;
	int 		i;
	int 		j;
	int 		arr_i;
	int 		*arr;

	if (!left || !right || left->colc != right->colc || left->rowc != right->rowc)
		return (NULL);
	i = 0;
	j = 0;
	arr_i = 0;
	arr = (int *)malloc(sizeof(int) * left->rowc * left->colc);
	while (i < left->rowc)
	{
		while (j < left->colc)
		{
			arr[arr_i] = left->table[i][j] + right->table[i][j];
			arr_i++;
			j++;
		}
		j = 0;
		i++;
	}
	matrix = make_matrix(left->rowc, left->colc, arr, left->rowc * left->colc);
	free(arr);
	return (matrix);
}

t_matrix	*mul_matrix(t_matrix *left, t_matrix *right)
{
	t_matrix	*matrix;
	int 		*arr;
	int 		i;
	int 		j;

	if (!left || !right || left->colc != right->rowc)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (left->rowc * right->colc));
	matrix = (t_matrix *)malloc(sizeof(matrix));
	i = 0;
	j = 0;
	/*
	** UNDER DEVELOPMENT
	*/
	return (matrix);
}

void		print_matrix(t_matrix *matrix)
{
	int 	max_num_len;
	int 	i;
	int 	j;

	if (!matrix)
		return ;
	ft_putstr("Rows: ");
	ft_putnbr(matrix->rowc);
	ft_putstr("    Columns: ");
	ft_putnbr(matrix->colc);
	ft_putchar('\n');
	max_num_len = num_len(matrix->max_value);
	i = 0;
	j = 0;
	ft_nputchar((max_num_len + 3) * matrix->colc, '_');
	ft_putchar('\n');
	while (i < matrix->rowc)
	{
		while (j < matrix->colc)
		{
			write(1, "|", 1);
			ft_putnbr(matrix->table[i][j]);
			ft_nputchar(max_num_len - num_len(matrix->table[i][j]) + 2, ' ');
			j++;
		}
		write(1, "|\n", 2);
		ft_nputchar((max_num_len + 3) * matrix->colc, '_');
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

t_matrix		*make_matrix(int rowc, int colc, int *arr, int n)
{
	t_matrix	*matrix;
	int 		i;
	int 		j;
	int 		arr_i;

	i = 0;
	j = 0;
	arr_i = 0;
	if (rowc <= 0 || colc <= 0 || !arr || n != rowc * colc)
		return (NULL);
	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	matrix->rowc = rowc;
	matrix->colc = colc;
	matrix->is_square = -1;
	matrix->is_diagonal = -1;
	matrix->max_value = arr[0];
	matrix->table = (int **)malloc(sizeof(int *) * rowc);
	while (i < rowc)
	{
		matrix->table[i] = (int *)malloc(sizeof(int) * colc);
		while (j < colc)
		{
			matrix->table[i][j] = (int)arr[arr_i];
			matrix->max_value = arr[arr_i] > matrix->max_value ? arr[arr_i] : matrix->max_value;
			arr_i++;
			j++;
		}
		j = 0;
		i++;
	}
	return (matrix);
}