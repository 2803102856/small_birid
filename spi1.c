#include "spi1.h"



//功    能 ： SPI延时
void SPI_Delay(void)
{
  uint16_t cnt = 5;

  while(cnt--);
}
void Delay(uint32_t cnt)
{
  

  while(cnt--);
}


void SPI_GPIO_Configuration(void)  //IO初始化
{
	rcu_periph_clock_enable(RCU_GPIOA);
	gpio_mode_set(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7);
	gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7);  //OUT
 
	gpio_mode_set(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO_PIN_6);    //INT	
  
	gpio_bit_set(GPIOA,GPIO_PIN_4);
	gpio_bit_reset(GPIOA,GPIO_PIN_7|GPIO_PIN_5);

}


void SPI_Initializes(void)//spi初始化
{
  SPI_GPIO_Configuration();

  SPI_CS_DISABLE;
  SPI_SCK_LOW;
  SPI_MOSI_LOW;
}



void SPI_WriteByte(uint8_t TxData)   //输出1字节 TxData
{
uint8_t cnt;

  for(cnt=0; cnt<8; cnt++)
  {
    if(TxData & 0x80)                            //发送数据
      SPI_MOSI_HIGH;
    else
      SPI_MOSI_LOW;
    TxData <<= 1;
    SPI_SCK_HIGH;                                //时钟 - 高
    SPI_Delay();
    SPI_SCK_LOW;                                 //时钟 - 低
    SPI_Delay();
  }
}

uint8_t SPI_ReadByte(void)//读1字节 RxData
{
  uint8_t cnt;
  uint8_t RxData = 0;

  for(cnt=0; cnt<8; cnt++)
  {
    RxData <<= 1;
    if(SPI_MISO_READ)                            //读取数据
    {
      RxData |= 0x01;
    }

    SPI_SCK_HIGH;                                //时钟 - 高
    SPI_Delay();
	 SPI_SCK_LOW;                                 //时钟 - 低
    SPI_Delay();
  }

  return RxData;
}



