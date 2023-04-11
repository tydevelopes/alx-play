//
//  bit_manipulation.c
//  alx-play
//
//  Created by Emmanuel Adjei-Frimpong on 4/7/23.
//

#include "bit_manipulation.h"


int _putchar(char c)
{
	return (int)(write(1, &c, 1));
}

/**
 * binary_to_uint- converts a binary number to an unsigned int
 * @b: pointer to binary string
 * Return: converted string or zero
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int converted_bin = 0, i = 0, exp = 0, length = 0;
	
	if (!b)
		return (0);
	length = (unsigned int)strlen(b);
	
	if (length == 0)
		return (0);
	exp = length - 1;
	
	for (i = 0; i < length; i++, exp--)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		converted_bin += (b[i] - '0') * _pow(2, exp);
	}
	return (converted_bin);
}

/**
 * _pow - calculate power of base, exponent
 * @base: base of power
 * @exp: exponent of power
 * Return: power of base and exp
 */
int _pow(int base, int exp)
{
	int res = 1;
	int i;
	
	for (i = 0; i < exp; i++)
	res *= base;
	
	return (res);
}

/**
 * print_binary - prints the binary representation of a number
 * @n: number tp print
 */
void _print_binary(unsigned long int n)
{
	int first_bit_1_printed = 0;
	int num_shifts;
	int bit;
	
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	for (num_shifts = NUM_OF_BITS; num_shifts >= 0; num_shifts--)
	{
		bit = (n & (1 << num_shifts)) >> num_shifts;
		
		/* Do not print leading zeros*/
		if (bit && !first_bit_1_printed)
			first_bit_1_printed = 1;
		
		if (first_bit_1_printed)
			_putchar(bit + '0');
	}
}

void print_binary(unsigned long int n) {
	if (n > 1)
	{
		print_binary(n >> 1);
	}
	putchar((n & 1) ? '1' : '0');
}
void __print_binary(unsigned long int n) {
	int i;
	for (i = sizeof(unsigned long int) * 8 - 1; i >= 0; i--) {
		putchar((n & (1ul << i)) ? '1' : '0');
	}
}

/**
 * get_bit -  returns the value of a bit at a given index
 * @n: number to get bit from
 * @index: index to of the bit to get
 * Return: bit at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 31)
		return (-1);
	
	return ((n >> index) & 1);
}

/**
 * set_bit -  sets  the value of a bit to 1 at a given index
 * @n: pointer to number to set bit in
 * @index: index of the bit to set
 * Return: 1 if it worked, -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 31)
		return (-1);
	
	/* set a bit at index*/
	*n = *n | _pow(2, index);
	
	/* checks if a bit is set at index*/
	if (*n & (1 << index))
		return (1);
	else
		return (-1);
}

/**
 * clear_bit -  sets  the value of a bit to 0 at a given index
 * @n: pointer to number to set bit in
 * @index: index of the bit to set
 * Return: 1 if it worked, -1 on error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 31)
		return (-1);
	
	/* clear a bit at index*/
	*n = *n & ~_pow(2, index);
	
	/* checks if a bit is cleared at index*/
	if (!(*n & (1 << index)))
		return (1);
	else
		return (-1);
}

/**
 * flip_bits - returns the number of bits you would need to flip to get from one number to another
 * @n: number to flip
 * @m: number to flip to
 * Return: number of bits flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int flips = 0;
	
	while (n > 0 || m > 0)
	{
		if ((n & 1) != (m & 1))
			flips++;
		n = n >> 1;
		m = m >> 1;
	}
	return (flips);
	//return (__builtin_popcount(n ^ m));
}

/**
 * get_endianess - checks the endianness
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int n = 1;
	char *byte  = (char *) &n;
	
	return ((int) *byte);
}

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: file to read
 * @letters: leetters to read
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	char *buffer;
	ssize_t bytes_read, bytes_written;
	
	if (!filename || letters == 0)
		return (0);
	
	buffer = malloc(sizeof(char) * letters);
	
	if (!buffer)
		return (0);
	
	file_descriptor = open(filename, O_RDONLY);
	
	if (file_descriptor == -1)
		return (0);
	
	bytes_read = read(file_descriptor, buffer, letters);
	
	if (bytes_read == -1)
		return (0);
	
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	
	if (bytes_written == -1)
		return (0);
	
	close(file_descriptor);
	free(buffer);
		
	
	return (bytes_written);
}

/**
 * create_file - create a file
 * @filename: pointer to filename
 * @text_content: pointer to text content
 * Return: 1 0n success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor;
	ssize_t bytes_written = -1;
	
	if (!filename)
		return (-1);
	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	
	if (file_descriptor == -1)
		return (-1);
	
	if (text_content)
		bytes_written = write(file_descriptor, text_content, strlen(text_content));
	else
		return (1);
	
	if (bytes_written == -1)
		return (-1);
	
	close(file_descriptor);
	
	return (1);
}

/**
 * append_text_to_file -appends text at the end of a file
 * @filename: pointer to filename
 * @text_content: pointer to text content
 * Return: 1 0n success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;
	ssize_t bytes_written = -1;
	
	if (!filename)
		return (-1);
	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	
	if (file_descriptor == -1)
		return (-1);
	
	if (text_content)
		bytes_written = write(file_descriptor, text_content, strlen(text_content));
	else
		return (1);
	
	if (bytes_written == -1)
		return (-1);
	
	close(file_descriptor);
	
	return (1);
}

/**
 * main - prints name of program
 * @argc: arguments count
 * @argv: list of arguments
 * Return: 0 if success
 */
int _main(int argc, char *argv[])
{
	int src_fd;
	int dest_fd;
	ssize_t bytes_read = -1;
	ssize_t bytes_written = -1;
	char *src_file = argv[1];
	char *dest_file = argv[2];
	char buffer[1024];
	
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	
	src_fd = open(src_file, O_RDONLY);
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",src_file);
		exit(98);
	}
	dest_fd = open(dest_file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest_file);
		exit(99);
	}
	/* Read source into buffer, then write to dest*/
	while (bytes_read != 0)
	{
		bytes_read = read(src_fd, buffer, 1024);
		if (bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",src_file);
			exit(98);
		}
		bytes_written = write(dest_fd, buffer, 1024);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest_file);
			exit(99);
		}
	}
	if (close(src_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
		exit(100);
	}
	if (close(dest_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		exit(100);
	}
	return (0);
}

void handle_rw_error(char *message, char *filename, int exit_code);
void handle_closing_error(char *message, int fd, int exit_code);

/**
 * main - prints name of program
 * @argc: arguments count
 * @argv: list of arguments
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	int src_fd;
	int dest_fd;
	ssize_t bytes_read = -1;
	ssize_t bytes_written = -1;
	char *src_file = argv[1];
	char *dest_file = argv[2];
	char buffer[1024];
	
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	
	src_fd = open(src_file, O_RDONLY);
	if (src_fd == -1)
		handle_rw_error("Error: Can't read from file", src_file, 98);
		
	dest_fd = open(dest_file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	
	if (dest_fd == -1)
		handle_rw_error("Error: Can't write to", dest_file, 99);
	
	/* Read source into buffer, then write to dest*/
	while (bytes_read != 0)
	{
		bytes_read = read(src_fd, buffer, 1024);
		if (bytes_read == -1)
			handle_rw_error("Error: Can't read from file", src_file, 98);
			
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1)
			handle_rw_error("Error: Can't write to", dest_file, 99);
			
	}
	if (close(src_fd) == -1)
		handle_closing_error("Error: Can't close fd", src_fd, 100);
		
	if (close(dest_fd) == -1)
		handle_closing_error("Error: Can't close fd", dest_fd, 100);
		
	return (0);
}

/**
 * handle_rw_error - r/w error utility function
 * @message: pointer to message
 * @filename: pointer to filename
 * @exit_code: exit code
 */
void handle_rw_error(char *message, char *filename, int exit_code)
{
	dprintf(STDERR_FILENO, "%s %s\n", message, filename);
	exit(exit_code);
}

/**
 * handle_closing_error - closing error utility function
 * @message: pointer to message
 * @fd: file descriptor
 * @exit_code: exit code
 */
void handle_closing_error(char *message, int fd, int exit_code)
{
	dprintf(STDERR_FILENO, "%s %d\n", message, fd);
	exit(exit_code);
}

