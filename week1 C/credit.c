#include <cs50.h>
#include <stdio.h>

// program which checks validity of credit card and if valid returns the card type

int numlength(long num);
int Luhnalgorithm(long creditcard);
char *cardtype(long creditcard);

int main(void)
{

  long creditcard;
  do
  {
    creditcard = get_long("Number: ");
  } while (numlength(creditcard) < 1);

  int output = Luhnalgorithm(creditcard);

  int length = numlength(creditcard);

  if (output == 0)
  {
    printf("INVALID\n");
  }
  else
  {
    char *card = cardtype(creditcard);
    printf("%s\n", card);
  }
}

// gives value of how many digits a number is

int numlength(long num)
{
  int length = 0;
  while (true)
  {
    num = (num / 10);
    length++;

    if (num == 0)
    {
      return length;
    }
  }
}

// use Luhna's algorithm to determine if creditcard is valid or not

int Luhnalgorithm(long creditcard)
{
  int sum = 0;
  int i = 1;
  int output = 0;

  do
  {

    int digit = creditcard % 10;
    int mult = digit * 2;

    if (i % 2 == 0 && mult < 10)
    {
      sum += mult;
    }

    if (i % 2 == 0 && mult > 9)
    {
      do
      {
        digit = mult % 10;
        sum += digit;

      } while (mult /= 10);
    }
    if (i % 2 != 0)
    {
      sum += digit;
    }

    i++;

  } while (creditcard /= 10);

  if (sum % 10 == 0)
  {
    // 1 in this case represents true or valid credit card
    output = 1;
  }

  else
  {
    // 0 in this case represents true or valid credit card
    output = 0;
  }

  return output;
}

// function to determine which cardtype the given card is
char *cardtype(long creditcard)
{
  int length = numlength(creditcard);
  int seconddigit;
  int firstdigit;
  int firsttwodigits;
  char *card = "";

  for (int i = 0; i < length; i++)
  {
    int digit = creditcard % 10;
    if (i == (length - 2))
    {
      seconddigit = digit;
    }
    if (i == (length - 1))
    {
      firstdigit = digit;
      firsttwodigits = (firstdigit * 10) + seconddigit;
    }
    creditcard /= 10;
  }

  if ((length == 15) && (firsttwodigits == 34 || firsttwodigits == 37))
  {
    card = "AMEX";
  }
  else if ((length == 16) && (firsttwodigits == 51 || firsttwodigits == 52 ||
                              firsttwodigits == 53 || firsttwodigits == 54 ||
                              firsttwodigits == 55))
  {
    card = "MASTERCARD";
  }
  else if ((length == 13 || length == 16) && (firstdigit == 4))
  {
    card = "VISA";
  }
  else
  {
    card = "INVALID";
  }

  return card;
}