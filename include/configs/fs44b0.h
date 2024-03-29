/*
 * (C) Copyright 2004
 * DAVE Srl
 *
 * http://www.dave-tech.it
 * http://www.wawnet.biz
 * mailto:info@wawnet.biz
 *
 * Configuation settings for the B2 board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARM7			1	/* This is a ARM7 CPU	*/
#define CONFIG_FS44B0			1	/* on an B2 Board      */
#define CONFIG_ARM_THUMB	1	/* this is an ARM7TDMI */
#undef  CONFIG_ARM7_REVD		/* disable ARM720 REV.D Workarounds */
#define CONFIG_SYS_NO_CP15_CACHE
#define CONFIG_ARCH_CPU_INIT

#define CONFIG_S3C44B0_CLOCK_SPEED	66 /* we have a 75Mhz S3C44B0*/
//#define DEBUG 10

#undef CONFIG_USE_IRQ			/* don't need them anymore */


/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MONITOR_LEN		(256 * 1024)	/* Reserve 256 kB for Monitor	*/
#define CONFIG_ENV_SIZE		1024		/* 1024 bytes may be used for env vars*/
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 512*1024 )

/*
 * Hardware drivers
 */
#define CONFIG_DRIVER_RTL8019 
#define RTL8019_BASE 0x06000000 
#undef  CONFIG_SHOW_ACTIVITY
#define CONFIG_NET_RETRY_COUNT		10
/*
 * select serial console configuration
 */
#define CONFIG_S3C44B0_SERIAL
#define CONFIG_SERIAL1		1	/* we use Serial line 1 */

#define CONFIG_S3C44B0_I2C
#define CONFIG_RTC_S3C44B0

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BAUDRATE		115200

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_SUBNETMASK
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_BOOTFILESIZE


/*
 * Command line configuration.
 */
#include <config_cmd_default.h>

//#define CONFIG_CMD_DATE
//#define CONFIG_CMD_ELF
#define CONFIG_CMD_EEPROM
#define CONFIG_CMD_I2C
#undef CONFIG_CMD_FPGA
#undef CONFIG_CMD_ITEST
#undef CONFIG_CMD_LOADS
//#undef CONFIG_CMD_MEMORY
#undef CONFIG_CMD_MISC
#undef CONFIG_CMD_NFS
#undef CONFIG_CMD_SETGETDCR
#undef CONFIG_CMD_SOURCE
#undef CONFIG_CMD_XIMG
//#define CONFIG_CMD_PING
//#define CONFIG_CMD_DHCP


#define CONFIG_NET_MULTI
#define CONFIG_BOOTDELAY	5
#define CONFIG_ETHADDR	00:50:c2:1e:af:fb
//#define CONFIG_BOOTARGS  "setenv bootargs console=ttySAC0,115200"
#define CONFIG_NETMASK  255.255.255.0
#define CONFIG_IPADDR   192.168.0.4
#define CONFIG_SERVERIP	192.168.0.100
//#define CONFIG_BOOTFILE	"zImage"
//#define CONFIG_BOOTCOMMAND	"bootm 20000 f0000"

/*
 * Miscellaneous configurable options
 */
#define	CONFIG_SYS_LONGHELP				/* undef to save memory		*/
#define	CONFIG_SYS_PROMPT		"=>  "	/* Monitor Command Prompt	*/
#define	CONFIG_SYS_CBSIZE		256		/* Console I/O Buffer Size	*/
#define	CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16) /* Print Buffer Size */
#define	CONFIG_SYS_MAXARGS		16		/* max number of command args	*/
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size	*/

#define CONFIG_SYS_MEMTEST_START	0x0C400000	/* memtest works on	*/
#define CONFIG_SYS_MEMTEST_END		0x0C800000	/* 4 ... 8 MB in DRAM	*/

#define	CONFIG_SYS_LOAD_ADDR		0x0c700000	/* default load address	*/

#define	CONFIG_SYS_HZ				1000		/* 1 kHz */

						/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128*1024)	/* regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ	(4*1024)	/* FIQ stack */
#endif

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1	   /* we have 1 banks of DRAM */
#define PHYS_SDRAM_1		0x0c000000 /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE	0x00800000 /* 8 MB */

#define PHYS_FLASH_1		0x00000000 /* Flash Bank #1 */
#define PHYS_FLASH_SIZE		0x00200000 /* 2 MB */

#define CONFIG_SYS_FLASH_BASE		PHYS_FLASH_1
#define CONFIG_SYS_SDRAM_BASE	PHYS_SDRAM_1
#define CONFIG_SYS_INIT_SP_ADDR (PHYS_SDRAM_1 + 0x1000 - \
                                GENERATED_GBL_DATA_SIZE)

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
/*-----------------------------------------------------------------------
 * FLASH organization
 */
#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* max number of memory banks		*/
#define CONFIG_SYS_MAX_FLASH_SECT	35	/* max number of sectors on one chip	*/

#define CONFIG_SYS_FLASH_ERASE_TOUT	120000	/* Timeout for Flash Erase (in ms)	*/
#define CONFIG_SYS_FLASH_WRITE_TOUT	1000	/* Timeout for Flash Write (in ms)	*/

#define CONFIG_SYS_FLASH_WORD_SIZE	unsigned short	/* flash word size (width)	*/
#define CONFIG_SYS_FLASH_ADDR0		0x5555	/* 1st address for flash config cycles	*/
#define CONFIG_SYS_FLASH_ADDR1		0x2AAA	/* 2nd address for flash config cycles	*/
/*
 * The following defines are added for buggy IOP480 byte interface.
 * All other boards should use the standard values (CPCI405 etc.)
 */
#define CONFIG_SYS_FLASH_READ0		0x0000	/* 0 is standard			*/
#define CONFIG_SYS_FLASH_READ1		0x0001	/* 1 is standard			*/
#define CONFIG_SYS_FLASH_READ2		0x0002	/* 2 is standard			*/

#define CONFIG_SYS_FLASH_EMPTY_INFO		/* print 'E' for empty sector on flinfo */

/*-----------------------------------------------------------------------
 * Environment Variable setup
 */
//#define CONFIG_ENV_IS_IN_EEPROM	1	/* use EEPROM for environment vars */
//#define CONFIG_ENV_OFFSET		0x0	/* environment starts at the beginning of the EEPROM */

#if 1 
#define CONFIG_ENV_IS_IN_FLASH	1	/* use EEPROM for environment vars */
#define CONFIG_ENV_OFFSET		0x00000000	/* environment starts at the beginning of the EEPROM */
#define CONFIG_ENV_ADDR (CONFIG_SYS_FLASH_BASE + 0x50000) /* environment start address */ 
#define CONFIG_ENV_SECT_SIZE 0x10000 /* Total Size of Environment Sector */ 
#define CONFIG_SYS_MONITOR_BASE PHYS_SDRAM_1
#define CONFIG_ENV_OVERWRITE
#endif

/*-----------------------------------------------------------------------
 * I2C EEPROM (STM24C02W6) for environment
 */
#define CONFIG_HARD_I2C			/* I2c with hardware support */
#define CONFIG_SYS_I2C_SPEED		400000	/* I2C speed and slave address */
#define CONFIG_SYS_I2C_SLAVE		0xFE

#define CONFIG_SYS_I2C_EEPROM_ADDR	0xA0	/* EEPROM STM24C02W6		*/
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN 1	/* Bytes of address		*/
/* mask of address bits that overflow into the "EEPROM chip address"	*/
/*#define CONFIG_SYS_I2C_EEPROM_ADDR_OVERFLOW	0x07*/
#define CONFIG_SYS_EEPROM_PAGE_WRITE_BITS 4	/* The Catalyst CAT24WC08 has	*/
					/* 16 byte page write mode using*/
					/* last 4 bits of the address	*/
#define CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS	10   /* and takes up to 10 msec */

/* Flash banks JFFS2 should use */
/*
#define CONFIG_SYS_JFFS2_FIRST_BANK    0
#define CONFIG_SYS_JFFS2_FIRST_SECTOR	2
#define CONFIG_SYS_JFFS2_NUM_BANKS     1
*/
#define CONFIG_CMD_NAND
#ifdef CONFIG_CMD_NAND
#define CONFIG_NAND_S3C44B0
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define NAND_MAX_CHIPS			1
#define CONFIG_SYS_NAND_BASE		0x02000000
#define CONFIG_CMD_FAT		/* FAT support			*/
#define CONFIG_CMD_UBI		/* UBI Support			*/
#define CONFIG_CMD_UBIFS	/* UBIFS Support		*/
#define CONFIG_CMD_MTDPARTS	/* Enable MTD parts commands    */
#define CONFIG_MTD_DEVICE	/* needed for mtdparts commands */
#define CONFIG_MTD_PARTITIONS
#define MTDIDS_DEFAULT		"nand0=s3c44b0-nand.0"
#define MTDPARTS_DEFAULT	"mtdparts=s3c44b0-nand.0:16m(ubi)"
				
#define CONFIG_RBTREE
#define CONFIG_LZO
#endif

#define CONFIG_USB_STORAGE 1
#define CONFIG_USB_SL811HS 1
#define CONFIG_CMD_USB
#define CONGIG_CMD_STORAGE
#define CONFIG_DOS_PARTITION 
#define CONFIG_CMD_EXT2		
/*
	Linux TAGs (see arch/arm/lib/armlinux.c)
*/
#define CONFIG_CMDLINE_TAG
#undef CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG

#endif	/* __CONFIG_H */
