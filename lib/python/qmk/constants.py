"""A place to store all constant values that are of use to multiple modules.
"""

# Supported processor types
ARM_PROCESSORS = 'cortex-m0', 'cortex-m0plus', 'cortex-m3', 'cortex-m4', 'STM32F042', 'STM32F072', 'STM32F103', 'STM32F303'
AVR_PROCESSORS = 'at90usb1286', 'at90usb646', 'atmega16u2', 'atmega328p', 'atmega32a', 'atmega32u2', 'atmega32u4', None
ALL_PROCESSORS = ARM_PROCESSORS + AVR_PROCESSORS
