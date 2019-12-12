#include <stdio.h>

struct card
{
	char* face;
	char* suit;
};

int main(void)
{
	struct card acard;
	struct card* cardprt;

	acard.face = "Ace";
	acard.suit = "Spades";

	cardprt = &acard;

	printf("%s%s%s\n%s%s%s\n%s%s%s\n", acard.face, "of", acard.suit, cardprt->face, "of", cardprt->suit, (*cardprt).face, "of", (*cardprt).suit);
	system("pause");
	return 0;




}