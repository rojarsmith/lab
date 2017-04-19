/*
Flashing LED demo.

Run flow : SystemInit -> main
*/

#include "stdint.h"
#include "stm32f7xx.h"

int main(void)
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

void SystemInit()
{
  
}