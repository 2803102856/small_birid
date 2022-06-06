#ifndef _SPI1_H
#define _SPI1_H


#include "gd32e23x.h"



#define PORT_SPI_CS               GPIOA
#define PORT_SPI_SCK              GPIOA
#define PORT_SPI_MISO             GPIOA
#define PORT_SPI_MOSI             GPIOA

#define PIN_SPI_CS                GPIO_Pin_4
#define PIN_SPI_SCK               GPIO_Pin_5
#define PIN_SPI_MISO              GPIO_Pin_6
#define PIN_SPI_MOSI              GPIO_Pin_7


#define SPI_CS_ENABLE             (gpio_bit_reset(GPIOA,GPIO_PIN_4))
#define SPI_CS_DISABLE            (gpio_bit_set(GPIOA,GPIO_PIN_4))

#define SPI_SCK_LOW               (gpio_bit_reset(GPIOA,GPIO_PIN_5))
#define SPI_SCK_HIGH              (gpio_bit_set(GPIOA,GPIO_PIN_5))

#define SPI_MISO_READ             (gpio_input_bit_get(GPIOA,GPIO_PIN_6))

#define SPI_MOSI_LOW              (gpio_bit_reset(GPIOA,GPIO_PIN_7))
#define SPI_MOSI_HIGH             (gpio_bit_set(GPIOA,GPIO_PIN_7))

void SPI_GPIO_Configuration(void);
void SPI_Initializes(void);
void SPI_WriteByte(uint8_t TxData);
uint8_t SPI_ReadByte(void);
void SPI_Delay(void);
void Delay(uint32_t cnt);


#endif 
