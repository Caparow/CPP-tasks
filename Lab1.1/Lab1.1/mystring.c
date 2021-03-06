#include "mystring.h"


int substr(const char *string1, const char *string2)
{
	int s, p, i;
	s = 0;

	for (i = 0; i < strlen(string1); i++)
	{

		if (string1[i] == string2[0])
		{

			for (p = 0; p < strlen(string2); p++)
				if (string1[i] == string2[p])
					i++;
				else
					break;

			if (p == strlen(string2))
			{
				s = i - p;
				break;
			}
		}
	}

	return(s);

}

int subseq(const char *string1, const char *string2)
{
	int k, p, i, nk, ni, max;
	max = p = ni = 0;

	for (i = 0; i < strlen(string1); i++)
		for (k = 0; k < strlen(string2); k++)
		    {
		        if (string1[i] == string2[k])
		        {
		        	ni = i;
					for (nk = k; nk < strlen(string2); nk++)
					{
						if (string1[ni] == string2[nk])
						{
							p++;
							ni++;
						}
						else
							break;
					}
		            if (p > max)
			            max = p;
				    p = 0;				
			     }
		    }
	
	return(max);
}

char ispal(const char *string)
{
	int k;

	for (int i = 0; i < (strlen(string)) % 2; i++)
		if (string[i] != string[strlen(string) - i - 1])
		{
		    k = 0;
			break;
		}
		else
			k = 1;

	return k;
}

int pstrlen(const char *p)
{
	int len = 0;
	while (*p++) len++;
	return len;
}

char* makepal(const char *st)
{

	int i, ni, k, b, n, end;
	static char nst[20]="";
	
	n = b = i = ni = k = 0;

	end = pstrlen(st)-1;
	

	for (i = 0; i < end; i++)
	{
		n++;
		if (st[i] == st[end])
		{
			ni = i;
			k = end;
			while ((st[ni] == st[k]) && (ni++ <= k--))
				b++;
		}
		if (ni > k)
		{
			n = ni - b - 1;
			break;
		}
		else
			b = 0;
	}


	for (i = 0; i <= end; i++)
		nst[i] = st[i];

	for (i = n; i >= 0; i--)
		nst[end+n-i] = st[i];

	
	return &nst;
}

double* txt2double(const char *str, int *size)
{
	char ch;
	int i = 0;
	int j = 0;
	int *ptr = NULL;


	double *vector = (double*)malloc(0);

	while (i < strlen(str))
	{
		char str_t[20];
		int b = 0;
		double num_t;

		ch = str[i];
		while ((ch != ";") && (i < strlen(str)))
		{
			if (((ch >= 48) && (ch<=57)) || (ch == '.'))
			{
				str_t[b] = ch;
				++b;
				++i;
				ch = str[i];
			}
			else
			{
				size = 0;
				return size;
			}
		}
		
		num_t = strtod(str_t, NULL);
		vector = (double*)realloc(ptr, (j+1)*sizeof(double));
		vector[j] = num_t;
		++i;
		++j;
	}

	for (int i = 0; i < j; i++)
		printf("%f", vector[i]);

	size = j;
	return &vector;
}