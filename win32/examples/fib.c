#Inclua <stdio.h>
#Inclua <stdlib.h>	// atoi()

Inteiro fib(n)
{
	Se (n <= 2)
		Retorne 1;
	Senão
		Retorne fib(n-1) + fib(n-2);
}

Inteiro main(Inteiro argc, Caractere **argv) 
{
	Inteiro n;
	Se (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		Retorne 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	Retorne 0;
}
