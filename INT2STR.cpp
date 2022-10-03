#include <iostream>

int len_int (int num, int c = 0)
{
	if (num == 0 && c == 0)
		return 1;
	else if (num == 0)
		return c;
	else
		len_int(num/10, c+1);
}

template <class T>
int print_array (T array[], int size)
{
	for (int i=0; i<size; i++)
	{
		std::cout << array[i];
	}
}

template <class T>
void reverse_array (T array[], int size)
{
	for (int i=0; i<size/2; i++)
	{
		T t = array[size-1-i];
		array[size-1-i] = array[i];
		array[i] = t;
	}
}

std::string int2str (int x)
{	
	x = abs(x); // abs(x) == |x|
	int size = len_int(x);
	char buffer_chr[size+1];
	
	for (int i=0; i<size+1; i++)
	{
		buffer_chr[i] = (i == size) ? '\0' : (char) (x % 10 + 48);
		x /= 10;
	}
	
	reverse_array(buffer_chr, size);
	
	std::string y = (std::string)(buffer_chr);
	
	return y;
}

int main (void)
{
	std::string s = int2str(-56789);
	std::cout << "Val: " + s;	
	
	return 0;
}
