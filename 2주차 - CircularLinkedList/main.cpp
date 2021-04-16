#include <iostream>
#include "MusicPlay.h"

int main()
{
	MusicPlay* musicList = new MusicPlay();
	
	while (musicList->GetIsRunning())
	{
		musicList->ShowMenu();

		switch (musicList->GetCmd())
		{
		case 1 : 
			musicList->AddMusic();
			break;

		case 2 : 
			musicList->ShowPlayList(musicList->GetHead());
			break;

		case 3 : 
			musicList->Play();
			break;

		case 4 : 
			musicList->Exit();
			break;

		default:
			return 0;
			break;
		}

	}

	delete musicList;

	return 0;
}