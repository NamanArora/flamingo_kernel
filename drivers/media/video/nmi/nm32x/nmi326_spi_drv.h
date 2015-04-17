/*****************************************************************************
 Copyright(c) 2012 NMI Inc. All Rights Reserved

 File name : nmi326_spi_drv.h

 Description : NM326 SPI interface

 History :
 ----------------------------------------------------------------------
 2012/11/27 	ssw		initial
*******************************************************************************/

#ifndef __SPI_DRV_H
#define __SPI_DRV_H

#define CONFIG_VIDEO_SPI_DEBUG
#define NMI326_HW_CHIP_ID_CHECK


/* Debug macro */
#define SPI_DEBUG(fmt, ...)                                     \
	do {                                                    \
	        printk(                               \
	                "%s: " fmt, __func__, ##__VA_ARGS__);   \
	} while(0)


#define SPI_WARN(fmt, ...)                                      \
	do {                                                    \
	        printk(KERN_WARNING                             \
	                fmt, ##__VA_ARGS__);                    \
	} while (0)

#define SPI_ERROR(fmt, ...)                                     \
	do {                                                    \
	        printk(KERN_ERR                                 \
	                "%s: " fmt, __func__, ##__VA_ARGS__);   \
        } while (0)



#ifdef CONFIG_VIDEO_SPI_DEBUG
#define spi_dbg(fmt, ...)               SPI_DEBUG(fmt, ##__VA_ARGS__)
#else
#define spi_dbg(fmt, ...)
#endif

#define spi_warn(fmt, ...)              SPI_WARN(fmt, ##__VA_ARGS__)
#define spi_err(fmt, ...)               SPI_ERROR(fmt, ##__VA_ARGS__)

unsigned long check_dtv_chip_id(void);
unsigned long nmi326_spi_read_chip_id(void);
//int nmi326_spi_init(void);
//void  nmi326_spi_exit( void );
int nmi326_spi_read(u8 *buf, size_t len);
int nmi326_spi_write(u8 *buf, size_t len);

struct nmi_spi_dtv_data {
	int irq_gpio;
	u32 irq_flags;
	int reset_gpio;
	u32 reset_flags;
	int rf_switch_gpio;
	u32 rf_switch_flags;
	int dtv_select_gpio;
	u32 dtv_select_flags;
	struct regulator *vdd;
	struct regulator *vdd_io;
	struct regulator *rf_switch;
};

#endif	//__SPI_DRV_H
