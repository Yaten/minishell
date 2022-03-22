# include <stdio.h>

// 'ou' exclusivo '^'
// 101 1000 0000
// 111 1000 0000
// 010 0000 0000

int main()
{
	// a = 5(00000101), b = 9(00001001)
	unsigned char a = 5, b = 9;

	//  0000 0101
	//  0000 1001

	//  0000 0001

	// The result is
	printf("a = %d, b = %d\n", a, b);
	printf("a&b = %d\n", a & b);

	//  0000 0101
	//  0000 1001

	//  0000 1101

	// The result is
	printf("a|b = %d\n", a | b);

	//  0000 0101
	//  0000 1001

	//  0000 1100

	//  0000 0000
	//

	// The result is
	printf("a^b = %d\n", a ^ b);

	// The result is
	printf("~a = %d\n", a = ~a);

	// The result is
	printf("b<<1 = %d\n", b << 1);

	// The result is 00000100
	printf("b>>1 = %d\n", b >> 1);

	return 0;

}
