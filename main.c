#include <gb/gb.h>
#include "main.h"
#include "alpha.c"
#include "blank.c"
#include "hello.c"

void main()
{
    init();
    while (1)
    {
        checkInput();
        updateSwitches();
        wait_vbl_done();
    }
}

void init()
{
    DISPLAY_ON;                 // Turn on the display
    set_bkg_data(0, 47, alpha); // Load 47 tiles into background memory
    // Use the 'helloWorld' array to write background tiles starting at 0,6 (tile positions)
	//  and write for 10 tiles in width and 2 tiles in height
	set_bkg_tiles(0,6,10,2,helloWorld);
}

void checkInput()
{
    if (joypad() & J_B)
    {
        // Use the 'blankScreen' array to write background tiles starting at 0,0 (tile positions)
		//  and for 20 tiles in width and 18 tiles in height
		set_bkg_tiles(0,0,20,18,blankScreen);
    }
}

void updateSwitches()
{
    HIDE_WIN;
    SHOW_SPRITES;
    SHOW_BKG;
}