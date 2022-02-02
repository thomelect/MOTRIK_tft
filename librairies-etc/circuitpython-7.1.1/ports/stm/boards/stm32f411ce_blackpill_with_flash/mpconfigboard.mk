USB_VID = 0x239A
USB_PID = 0x006A
USB_PRODUCT = "stm32f411ce blackpill with flash"
USB_MANUFACTURER = "WeAct"

SPI_FLASH_FILESYSTEM = 1
#See supervisor/shared/external_flash/devices.h for options
EXTERNAL_FLASH_DEVICES = GD25Q16C,W25Q64FV,W25Q32JVxQ,W25Q64JVxQ
LONGINT_IMPL = MPZ

INTERNAL_FLASH_FILESYSTEM = 0

MCU_SERIES = F4
MCU_VARIANT = STM32F411xE
MCU_PACKAGE = UFQFPN48

LD_COMMON = boards/common_default.ld
LD_FILE = boards/STM32F411_nofs.ld

# Too big for the flash
CIRCUITPY_ULAB = 0
