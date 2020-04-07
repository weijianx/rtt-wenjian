#include <rtthread.h>

#ifdef RT_USING_DFS
#include <dfs_fs.h>
#include "dfs_romfs.h"


int romfs_init(void)
{
	static const rt_uint8_t _romfs_root_readme_txt[] = {
	0x52,0x54,0x2d,0x54,0x68,0x72,0x65,0x61,0x64,0x0d,0x0a,0x00
	};

	static const rt_uint8_t _romfs_root_sdcard_aaa_txt[] = {
		0x52,0x54,0x2d,0x54,0x68,0x72,0x65,0x61,0x64,0x0d,0x0a,0x00
	};

	static const struct romfs_dirent _romfs_root_sdcard[] = {
		{ROMFS_DIRENT_FILE, "aaa.txt", (rt_uint8_t *)_romfs_root_sdcard_aaa_txt, sizeof(_romfs_root_sdcard_aaa_txt)/sizeof(_romfs_root_sdcard_aaa_txt[0])}
	};

	static const rt_uint8_t _romfs_root_spi_bbb_txt[] = {
		0x52,0x54,0x2d,0x54,0x68,0x72,0x65,0x61,0x64,0x0d,0x0a,0x00
	};

	static const struct romfs_dirent _romfs_root_spi[] = {
		{ROMFS_DIRENT_FILE, "bbb.txt", (rt_uint8_t *)_romfs_root_spi_bbb_txt, sizeof(_romfs_root_spi_bbb_txt)/sizeof(_romfs_root_spi_bbb_txt[0])}
	};

	static const struct romfs_dirent _romfs_root[] = {
		{ROMFS_DIRENT_FILE, "readme.txt", (rt_uint8_t *)_romfs_root_readme_txt, sizeof(_romfs_root_readme_txt)/sizeof(_romfs_root_readme_txt[0])},
        {ROMFS_DIRENT_DIR, "sdcard", (rt_uint8_t *)_romfs_root_sdcard, sizeof(_romfs_root_sdcard)/sizeof(_romfs_root_sdcard[0])},
		{ROMFS_DIRENT_DIR, "qspi", (rt_uint8_t *)_romfs_root_spi, sizeof(_romfs_root_spi)/sizeof(_romfs_root_spi[0])}
	};

	static const struct romfs_dirent romfs_root = {
		ROMFS_DIRENT_DIR, "/", (rt_uint8_t *)_romfs_root, sizeof(_romfs_root)/sizeof(_romfs_root[0])
	};
		
    if (dfs_mount(RT_NULL, "/", "rom", 0, &(romfs_root)) == 0)
    {
        rt_kprintf("ROM file system initializated!\n");
    }
    else
    {
        rt_kprintf("ROM file system initializate failed!\n");
    }

    return 0;
}
INIT_ENV_EXPORT(romfs_init);

#endif



