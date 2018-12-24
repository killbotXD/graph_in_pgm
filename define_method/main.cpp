#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc,char * argv[])
{
		if(argc != 2)
		{
			printf("Syntax is $./main \"f(x) expression\"\n");
			return 0;
		}
        char exp[100];
        sprintf(exp,"echo \"#define fun(x) (%s) \"|cat > fun.h",argv[1]);
        system(exp);
        if(!(system("g++ graph.cpp -o graph")))
        system("./graph");
        return 0;
}                                                                                                          