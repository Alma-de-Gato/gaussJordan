#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	float matriz[20][20],p,y,aux;    
	int i,j,t,k,a,f,x,m,b;
    char *enter;
    enter = (char*)malloc(sizeof(char));
	
	printf("\n    	  ::************************::");
	printf("\n	  ::*METODO DE GAUSS-JORDAM*::");
	printf("\n          ::************************::\n");
	printf("	  ----------------------------\n");
	printf(" \n Digite a ordem da matriz: ");
	scanf("%i",&t);
	printf("\n Digite os elementos da matriz:\n");
	
	for(i=1; i<=t; i++)
	{
		for(j=1; j<=t+1; j++)
		{
			if(j==t+1)
            {
				printf(" Resultado: ");
				scanf("%f",&matriz[i][j]);
			}
            else
            {
                printf(" linha [%i] coluna [%i]: ", i, j);
			    scanf("%f", &matriz[i][j]);
		    }
		}
    }
    if(matriz[1][1]==0)
    {
        for(m=2;m<=t;m++)
        {
            if(matriz[1][1]==0)
            {
                if(matriz[m][1]!=0)
                {
                    for(b=1;b<=t+1;b++)
                    {
                        aux=matriz[m][b];
 				        matriz[m][b]=matriz[1][b];
 				        matriz[1][b]=aux;
                    }
		        }		 
		    } 		
	    }
    }
    system("cls");
    printf("\n    	  ::************************::");
    printf("\n	  ::*METODO DE GAUSS-JORDAM*::");
    printf("\n          ::************************::\n");
    printf("	  ----------------------------\n\n");
    printf("Matriz inserida:\n");
    
    for (a=1; a<=t; a++)
    {
        printf("{");
        for (f=1; f<=t+1; f++)
        {
            if(f==t+1)
            {
                printf("| %.2f",matriz[a][f]);
            }
            else
            {
                printf("  %.2f  ", matriz[a][f]);	
            } 
        }
        printf("}");
        printf("\n");
    }
    printf("Pressione Enter para zerar os elementos fora da diagonal principal: ");
    fflush(stdin);
    scanf("%[^\n]s", enter);
    free(enter);

	for (i=1; i<=t; i++)
	{
        printf("\n");
		p = matriz[i][i];
		for (j=1; j<=t+1; j++)
		{
			matriz[i][j] = matriz[i][j] / p + 0;
		}
		for (k=1; k<=t+1; k++)
		{
			if (k != i)
			{
				y = matriz[k][i];
				for (x=1; x<=t+1; x++)
				{
					matriz[k][x] = (-y) * matriz[i][x] + matriz[k][x];
				}
	        }
        }        

        for (a=1; a<=t; a++)
		{
			printf("{");
			for (f=1; f<=t+1; f++)
			{
				if(f==t+1)
                {
					printf("| %.2f",matriz[a][f]);                    
				}
                else
                {
					printf("  %.2f  ", matriz[a][f]);
                }
			}
			printf("}");
			printf("\n");
        }
    }
    system("pause");
}