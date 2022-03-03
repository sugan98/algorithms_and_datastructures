/* CH3PR6.C: Few more string functions. */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <alloc.h>

int search ( char *, char ) ;
int isequals ( char *, char * ) ;
int issmaller ( char *, char * ) ;
int isgreater ( char *, char * ) ;
char * getsub ( char *, int, int ) ;
char * leftsub ( char *, int n ) ;
char * rightsub ( char *, int n ) ;
void upper ( char * ) ;
void lower ( char * ) ;
void reverse ( char * ) ;
int replace ( char *, char, char ) ;
int setat ( char *, char, int ) ;

void main( )
{
	char s1[ ] = "Hello" ;
	char s2[ ] = "Hello World" ;
	char s3[ ] = "Four hundred thirty two" ;
	char ch, *s ;
	int i ;

	clrscr( ) ;

	printf ( "\nString s1: %s", s1 ) ;

	/* check for the first occurrence of a character */
	printf ( "\nEnter character to search: " ) ;
	scanf ( "%c", &ch ) ;
	i = search ( s1, ch ) ;
	if ( i != -1 )
		printf ( "The first occurrence of character %c is found at index no.
                            %d\n", ch, i ) ;
	else
		printf ( "Character %c is not present in the list.\n", ch ) ;

	printf ( "\nString s2: %s", s2 ) ;

	/* compares two strings s1 and s2 */
	i = isequals ( s1, s2 ) ;
	if ( i == 1 )
		printf ( "\nStrings s1 and s2 are identical" ) ;
	else
		printf ( "\nStrings s1 and s2 are not identical") ;
	i = issmaller ( s1, s2 ) ;
	if ( i == 1 )
		printf ( "\nString s1 is smaller than string s2" ) ;
	else
		printf ( "\nString s1 is not smaller than string s2" ) ;

	i = isgreater ( s1, s2 ) ;
	if ( i == 1 )
		printf ( "\nString s1 is greater than string s2\n" ) ;
	else
		printf ( "\nString s1 is not greater than string s2\n" ) ;

	/* extract characters at given position */
	printf ( "\nString s3: %s", s3 ) ;
	s = getsub ( s3, 5, 7 ) ;
	printf ( "\nSub string: %s", s ) ;
	free ( s ) ;

	/* extract leftmost n characters */
	s = leftsub ( s3, 4 ) ;
	printf ( "\nLeft sub string: %s", s ) ;
	free ( s ) ;

	/* extract rightmost n characters */
	s = rightsub ( s3, 3 ) ;
	printf ( "\nRight sub string: %s", s ) ;
	free ( s ) ;

	/*  convert string to uppercase */
	upper ( s3 ) ;
	printf ( "\nString in upper case: %s", s3 ) ;

	/* convert string to lowercase */
	lower ( s3 ) ;
	printf ( "\nString in lower case: %s", s3 ) ;

	/* reverse the given string */
	reverse ( s3 ) ;
	printf ( "\nReversed string: %s", s3 ) ;

	/* replace first occurrence of one char with new one */
	replace ( s1, 'H' , 'M' ) ;
	printf ( "\nString s1: %s", s1 ) ;

	/* sets a char at a given position */
	i = setat ( s1, 'M', 3 ) ;
	if ( i )
		printf ( "\nString s1: %s", s1 ) ;
	else
		printf ( "\nInvalid position." ) ;

	getch( ) ;
}

/* check for the first occurrence of a character */
int search ( char *str, char ch )
{
	int i = 0 ;

	while ( *str )
	{
		if ( *str == ch )
			return i ;
		str++ ;
		i++ ;
	}
	return -1 ;
}

/* checks whether two strings are equal */
int isequals ( char *s, char *t )
{
	while ( *s || *t )
	{
		if ( *s != *t )
			return 0 ;
		s++ ;
		t++ ;
	}
	return 1 ;
}

/* checks whether first string is less than second */
int issmaller ( char *s, char *t )
{
	while ( *t )
	{
		if ( *s != *t )
		{
			if ( *s < *t )
				return 1 ;
			else
				return 0 ;
		}
		t++ ;
		s++ ;
	}
	return 0 ;
}

/* checks whether first string is greater than second */
int isgreater ( char *s, char *t )
{
	while ( *s )
	{
		if ( *s != *t )
		{
			if ( *s > *t )
				return 1 ;
			else
				return 0 ;
		}
		s++ ;
		t++ ;
	}
	return 0 ;
}

/* extracts the character at given position */
char * getsub ( char *str, int spos, int n )
{
	char *s = str + spos ;
	char *t = ( char * ) malloc ( n + 1 ) ;
	int i = 0 ;

	while ( i < n )
	{
		t[i] = *s ;
		s++ ;
		i++ ;
	}
	t[i] = '\0' ;

	return t ;
}

/* extracts leftmost n characters from the string */
char * leftsub ( char *s, int n )
{
	char *t = ( char * ) malloc ( n + 1 ) ;
	int i = 0 ;

	while ( i < n )
	{
		t[i] = *s ;
		s++ ;
		i++ ;
	}
	t[i] = '\0' ;

	return t ;
}
/* extracts rightmost n characters from the string */
char * rightsub ( char *str, int n )
{
	char *t = ( char * ) malloc ( n + 1 ) ;
	int l = strlen ( str ) ;
	char *s = str + ( l - n ) ;
	int i = 0 ;

	while ( i < n )
	{
		t[i] = *s ;
		s++ ;
		i++ ;
	}
	t[i] = '\0' ;

	return t ;
}

/* converts string to uppercase */
void upper ( char *s )
{
	while ( *s )
	{
		if ( *s >= 97 && *s <= 123 )
			*s -= 32 ;
		s++ ;
	}
}

/* converts string to lowercase */
void lower ( char *s )
{
	while ( *s )
	{
		if ( *s >= 65 && *s <= 91 )
			*s += 32 ;
		s++ ;
	}
}

/* reverses a string */
void reverse ( char *str )
{
	int l = strlen ( str ) ;
	char ch, *t = ( str + l - 1 ) ;
	int i = 0 ;

	while ( i < l / 2 )
	{
		ch = *str ;
		*str = *t ;
		*t = ch ;

		str++ ;
		t-- ;
		i++ ;
	}
}

/* replaces the first occurrence of char with new char */
int replace ( char *str, char oldch, char newch )
{
	while ( *str )
	{
		if ( *str == oldch )
		{
			*str = newch ;
			return 1 ;
		}
		str++ ;
	}
	return 0 ;
}

/* sets a char at a given position */
int setat ( char *str, char ch, int i )
{
	if ( i < 0 || strlen ( str ) < i )
		return 0 ;
	* ( str + i ) = ch ;
	return 1 ;
}