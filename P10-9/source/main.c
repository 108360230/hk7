#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct card
{
	const char* face;
	const char* suit;
};

typedef struct card Card;

void filldeck(Card* const wdeck, const char* wface[], const char* wsuit[]);
void shuffie(Card* const wdeck);
void deal(const Card* const wdeck);

int main(void)
{	
	Card deck[52];
	const char* face[] = { "Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
	const char* suit[] = { "Hearts","Diamonda","Clubs","Spades" };

	srand(time(NULL));

	filldeck(deck, face, suit);
	shuffie(deck);
	deal(deck);
	system("pause");
	return 0;
}

void filldeck(Card* const wdeck, const char* wface[], const char* wsuit[])
{
	int i;
	for (i = 0; i <= 51; i++)
	{
		wdeck[i].face = wface[i % 13];
		wdeck[i].suit = wsuit[i / 13];
	}
}

void shuffie(Card* const wdeck)
{
	int i, j;
	Card tamp;
	for (i = 0; i <= 51; i++)
	{
		j = rand() % 52;
		tamp = wdeck[i];
		wdeck[i] = wdeck[j];
		wdeck[j] = tamp;
	}
}

void deal(const Card* const wdeck)
{
	int i;
	for (i = 0; i <= 51; i++)
	{
		printf("%5s of %-8s%s", wdeck[i].face, wdeck[i].suit, (i + 1) % 4 ?" " :"\n");
	}
}