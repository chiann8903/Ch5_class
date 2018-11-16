#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void shuffle(int);
void deal(int, const char , const char);
main() {
	char *suit[4] = { "Hearts","Daimonds","Clubs","Spades" };
	char *face[13] = { "Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
	int deck[4][13] = { 0 };
	srand(time(NULL));
	shuffle(deck);
	deal(deck, suit, face);
	system("pause");
}
void shuffle(int wdeck[][13]) {
	int x;
	int y;
	int card;
	for (card = 1; card <= 52; card++) {
		do {
			x = rand() % 4;
			y = rand() % 13;
		} while (wdeck[x][y] != 0);
		wdeck[x][y] = card;
	}
}
void deal(int wdeck[][13], const char *wsuit[], const char *wface[]) {
	int x, y, card;
	for (card = 1; card <= 52; card++) {
		for (x = 0; x < 4; x++) {
			for (y = 0; y < 13; y++) {
				if(wdeck[x][y]==card)
				printf("%5s of %-8s%c",wface[y], wsuit[x],  card % 2 == 0 ? '\n' : '\t');
			}
		}
	}
}