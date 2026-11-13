#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

int main(void)
{
  char my_char;
  my_char = 'A';
  int i = 1;
  while(i < 11)
  {
    i = i + 1;
    ft_putchar(my_char);
    my_char = my_char + 1;
  }
  while(i < 22)
  {
    i = i + 1;
    ft_putchar(my_char);
    my_char = my_char - 1;
  }
  return (0);
}
