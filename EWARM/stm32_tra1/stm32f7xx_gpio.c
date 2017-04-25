#include "stm32f7xx_gpio.h"

/** 
*函數功能：設置引腳為高電平 
*參數說明：GPIOx:該參數為GPIO_TypeDef類型的指標，指向GPIO埠的位址 
* GPIO_Pin:選擇要設置的GPIO埠引腳，可輸入宏GPIO_Pin_0-15， 
* 表示GPIOx埠的0-15號引腳。 
*/ 
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) 
{ 
  /*設置GPIOx埠BSRRL寄存器的第GPIO_Pin位，使其輸出高電平*/ 
  /*因為BSRR寄存器寫0不影響， 
  宏GPIO_Pin只是對應位元為1，其它位均為0，所以可以直接賦值*/ 
  
  GPIOx->BSRRL = GPIO_Pin; 
} 

/** 
*函數功能：設置引腳為低電平 
*參數說明：GPIOx:該參數為GPIO_TypeDef類型的指標，指向GPIO埠的位址 
* GPIO_Pin:選擇要設置的GPIO埠引腳，可輸入宏GPIO_Pin_0-15， 
* 表示GPIOx埠的0-15號引腳。 
*/ 
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) 
{ 
  /*設置GPIOx埠BSRRH寄存器的第GPIO_Pin位,使其輸出低電平*/ 
  /*因為BSRR寄存器寫0不影響， 
  宏GPIO_Pin只是對應位元為1，其它位均為0，所以可以直接賦值*/ 
  
  GPIOx->BSRRH = GPIO_Pin; 
}

/** 
*函數功能：初始化引腳模式 
*參數說明：GPIOx，該參數為GPIO_TypeDef類型的指標，指向GPIO埠的位址 
* GPIO_InitTypeDef:GPIO_InitTypeDef結構體指標，指向初始化變數 
*/ 
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct) 
{ 
  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00; 
  
  /*-- GPIO Mode Configuration --*/ 
  for (pinpos = 0x00; pinpos < 16; pinpos++) { 
    /*以下運算是為了通過 GPIO_InitStruct->GPIO_Pin 算出引腳號0-15*/ 
    
    /*經過運算後pos的pinpos位為1，其餘為0，與GPIO_Pin_x宏對應。 
    pinpos變數每次迴圈加1，*/ 
    pos = ((uint32_t)0x01) << pinpos; 
    
    /* pos與GPIO_InitStruct->GPIO_Pin做 & 運算， 
    若運算結果currentpin == pos， 
    則表示GPIO_InitStruct->GPIO_Pin的pinpos位也為1， 
    從而可知pinpos就是GPIO_InitStruct->GPIO_Pin對應的引腳號：0-15*/ 
    currentpin = (GPIO_InitStruct->GPIO_Pin) & pos; 
    
    /*currentpin == pos時執行初始化*/ 
    if (currentpin == pos) { 
      /*GPIOx埠，MODER寄存器的GPIO_InitStruct->GPIO_Pin對應的引腳，
      
      MODER位清空*/ 
      GPIOx->MODER &= ~(3 << (2 *pinpos)); 
      
      /*GPIOx埠，MODER寄存器的GPIO_Pin引腳， 
      MODER位設置"輸入/輸出/複用輸出/類比"模式*/ 
      GPIOx->MODER |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << (2 *pinpos)); 
      
      /*GPIOx埠，PUPDR寄存器的GPIO_Pin引腳， 
      PUPDR位清空*/ 
      GPIOx->PUPDR &= ~(3 << ((2 *pinpos))); 
      
      /*GPIOx埠，PUPDR寄存器的GPIO_Pin引腳， 
      PUPDR位元設置"上/下拉"模式*/ 
      GPIOx->PUPDR |= (((uint32_t)GPIO_InitStruct->GPIO_PuPd) << (2 *pinpos)); 
      
      /*若模式為"輸出/複用輸出"模式，則設置速度與輸出類型*/ 
      if ((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT) || 
          (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF)) { 
            /*GPIOx埠，OSPEEDR寄存器的GPIO_Pin引腳， 
            OSPEEDR位清空*/ 
            GPIOx->OSPEEDR &= ~(3 << (2 *pinpos)); 
            /*GPIOx埠，OSPEEDR寄存器的GPIO_Pin引腳， 
            OSPEEDR位元設置輸出速度*/ 
            GPIOx->OSPEEDR |= ((uint32_t)(GPIO_InitStruct->GPIO_Speed)<<(2 *pinpos)); 
            
            /*GPIOx埠，OTYPER寄存器的GPIO_Pin引腳， 
            OTYPER位清空*/ 
            GPIOx->OTYPER &= ~(1 << (pinpos)) ; 
            /*GPIOx埠，OTYPER位寄存器的GPIO_Pin引腳， 
            OTYPER位設置"推挽/開漏"輸出類型*/ 
            GPIOx->OTYPER |= (uint16_t)(( GPIO_InitStruct->GPIO_OType)<< (pinpos)); 
          } 
    } 
  } 
}
