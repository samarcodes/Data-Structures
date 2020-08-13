#include<stdio.h>

void count_words_vowels(char s[])
{
    int i=0;
    int vowel_count=0,consonant_count=0;
    char ch;
    while(s[i]!='\0')
    {
        ch=s[i];
        switch(ch)
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                vowel_count++;
                break;

            case ' ':
                //if encounter space do nothing
                break;

            default:
                consonant_count++;
        }
        i++;
    }
    printf("Words = %d",vowel_count+consonant_count);
    printf("\nVowels = %d",vowel_count);

}

int main()
{
    char str[20];
    printf("Enter string : ");
    gets(str);
    count_words_vowels(str);
    return 0;
}
