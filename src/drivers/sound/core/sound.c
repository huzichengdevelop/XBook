/*
 * file:		drivers/sound/core/sound.c
 * auther:		Jason Hu
 * time:		2020/1/17
 * copyright:	(C) 2018-2019 by Book OS developers. All rights reserved.
 */

#include <book/config.h>
#include <book/debug.h>
#include <book/arch.h>

#include <share/string.h>

#include <book/sound.h>

#include <drivers/pcspeaker.h>
#include <drivers/sb16.h>

PUBLIC int InitSoundSystem()
{
    PART_START("Sound");

#ifdef CONFIG_SB16
    if (InitSoundBlaster16Driver()) {
        return -1;
    }    
#endif /* CONFIG_SB16 */

    if (InitPcspeakerDriver()) {
        printk("init pc speaker failed!\n");
    }

    PART_END();
    //while(1);
    return 0;
}