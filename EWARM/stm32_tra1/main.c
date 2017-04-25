/*
Flashing LED demo.

Run flow : SystemInit -> main
*/

#include "stdint.h"
#include "stm32f7xx.h"
#include "stm32f7xx_gpio.h"

void flashing_reg();
void flashing_struct();
void flashing_lib();
void Delay(uint32_t nCount);

int main(void)
{
  flashing_lib();
}

void SystemInit()
{
  
}

void flashing_reg()
{
  RCC_AHB1ENR |= (1 << 8);
  
  GPIOI_MODER &= ~(0x03 << (2*3));
  GPIOI_MODER |= (1 << 2*3);
  
  GPIOI_OTYPER &= ~(1 << 1*3);
  GPIOI_OTYPER |= (0 << 1*3);
  
  GPIOI_OSPEEDR &= ~(0x03 << 2*3);
  GPIOI_OSPEEDR |= (0x03 << 2*3);
  
  GPIOI_PUPDR &= ~(0x03 << 2*3);
  GPIOI_PUPDR |= (1 << 2*3);
  
  while (1)
  {
    GPIOI_BSRR |= (1 << 16 << 3);
    
    //Delay
    uint32_t count1 = 10000000;
    while(count1 > 0) count1--;
    
    GPIOI_BSRR |= (1 << 3);
    
    //Delay
    uint32_t count2 = 10000000;
    while(count2--);
  }
}

void flashing_struct()
{
  RCC->AHB1ENR |= (1 << 8);
  
  GPIOI->MODER &= ~(0x03 << (2*3));
  GPIOI->MODER |= (1 << 2*3);
  
  GPIOI->OTYPER &= ~(1 << 1*3);
  GPIOI->OTYPER |= (0 << 1*3);
  
  GPIOI->OSPEEDR &= ~(0x03 << 2*3);
  GPIOI->OSPEEDR |= (0x03 << 2*3);
  
  GPIOI->PUPDR &= ~(0x03 << 2*3);
  GPIOI->PUPDR |= (1 << 2*3);
  
  while (1)
  {
    GPIOI->BSRRH |= (1 << 3);
    
    //Delay
    uint32_t count1 = 10000000;
    while(count1 > 0) count1--;
    
    GPIOI->BSRRL |= (1 << 3);
    
    //Delay
    uint32_t count2 = 10000000;
    while(count2--);
  }
}

void flashing_lib()
{
  GPIO_InitTypeDef InitStruct;
  
  /*開啟 GPIOH 時鐘，使用外設時都要先開啟它的時鐘*/
  RCC->AHB1ENR |= (1<<8);
  
  /* LED 埠初始化 */
  
  /*初始化PI3引腳*/
  /*選擇要控制的GPIO引腳*/
  InitStruct.GPIO_Pin = GPIO_Pin_3;
  /*設置引腳模式為輸出模式*/
  InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  /*設置引腳的輸出類型為推挽輸出*/
  InitStruct.GPIO_OType = GPIO_OType_PP;
  /*設置引腳為上拉模式*/
  InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
  /*設置引腳速率為2MHz */
  InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
  /*調用庫函數，使用上面配置的GPIO_InitStructure初始化GPIO*/
  GPIO_Init(GPIOI, &InitStruct);
  
  while (1)
  {
    /*使引腳輸出低電平,點亮LED1*/
    GPIO_ResetBits(GPIOI, GPIO_Pin_3);
    
    Delay(10000000);
    
    /*使引腳輸出高電平，關閉LED1*/
    GPIO_SetBits(GPIOI, GPIO_Pin_3);
    
    Delay(10000000);
  }
}

/*簡單的延時函數，讓cpu執行無意義指令，消耗時間
  具體延時時間難以計算，以後我們可使用計時器精確延時 */
void Delay(uint32_t nCount)
{
  // 函數為空，目的是為了騙過編譯器不報錯
  for (; nCount != 0; nCount--);
}