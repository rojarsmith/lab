#include "stm32f7xx.h"

#define __IO  volatile

/*GPIO寄存器列表*/
typedef struct {
  __IO uint32_t MODER; /*GPIO模式寄存器 位址偏移: 0x00 */
  __IO uint32_t OTYPER; /*GPIO輸出類型寄存器 位址偏移: 0x04 */
  __IO uint32_t OSPEEDR; /*GPIO輸出速度寄存器 位址偏移: 0x08 */
  __IO uint32_t PUPDR; /*GPIO上拉/下拉寄存器 位址偏移: 0x0C */
  __IO uint32_t IDR; /*GPIO輸入資料寄存器 位址偏移: 0x10 */
  __IO uint32_t ODR; /*GPIO輸出資料寄存器 位址偏移: 0x14 */
  __IO uint16_t BSRRL; /*GPIO置位元/重定寄存器低16位元部分 位址偏移: 0x18 */
  __IO uint16_t BSRRH; /*GPIO置位元/重定寄存器 高16位元部分位址偏移: 0x1A */
  __IO uint32_t LCKR; /*GPIO配置鎖定寄存器 位址偏移: 0x1C */
  __IO uint32_t AFR[2]; /*GPIO複用功能配置寄存器 位址偏移: 0x20-0x24 */
} GPIO_TypeDef;

/*RCC寄存器列表*/
typedef struct {
  __IO uint32_t CR; /*!< RCC 時鐘控制寄存器,位址偏移: 0x00 */
  __IO uint32_t PLLCFGR; /*!< RCC PLL配置寄存器,位址偏移: 0x04 */
  __IO uint32_t CFGR; /*!< RCC 時鐘配置寄存器,位址偏移: 0x08 */
  __IO uint32_t CIR; /*!< RCC 時鐘中斷寄存器,位址偏移: 0x0C */
  __IO uint32_t AHB1RSTR; /*!< RCC AHB1 外設復位寄存器,位址偏移: 0x10 */
  __IO uint32_t AHB2RSTR; /*!< RCC AHB2 外設復位寄存器,位址偏移: 0x14 */
  __IO uint32_t AHB3RSTR; /*!< RCC AHB3 外設復位寄存器,位址偏移: 0x18 */
  __IO uint32_t RESERVED0; /*!< 保留, 位址偏移：0x1C */
  __IO uint32_t APB1RSTR; /*!< RCC APB1 外設復位寄存器,位址偏移: 0x20 */
  __IO uint32_t APB2RSTR; /*!< RCC APB2 外設復位寄存器,位址偏移: 0x24*/
  __IO uint32_t RESERVED1[2]; /*!< 保留,位址偏移：0x28-0x2C*/
  __IO uint32_t AHB1ENR; /*!< RCC AHB1 外設時鐘寄存器,位址偏移: 0x30 */
  __IO uint32_t AHB2ENR; /*!< RCC AHB2 外設時鐘寄存器,位址偏移: 0x34 */
  __IO uint32_t AHB3ENR; /*!< RCC AHB3 外設時鐘寄存器,位址偏移: 0x38 */
  /*RCC後面還有很多寄存器，此處省略*/
} RCC_TypeDef;

/*定義GPIOA-H 寄存器結構體指標*/
#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI ((GPIO_TypeDef *) GPIOI_BASE)

/*定義RCC外設 寄存器結構體指標*/
#define RCC ((RCC_TypeDef *) RCC_BASE)

/*GPIO引腳號定義*/
#define GPIO_Pin_0 (uint16_t)0x0001) /*!< 選擇Pin0 (1<<0) */
#define GPIO_Pin_1 ((uint16_t)0x0002) /*!< 選擇Pin1 (1<<1)*/
#define GPIO_Pin_2 ((uint16_t)0x0004) /*!< 選擇Pin2 (1<<2)*/
#define GPIO_Pin_3 ((uint16_t)0x0008) /*!< 選擇Pin3 (1<<3)*/
#define GPIO_Pin_4 ((uint16_t)0x0010) /*!< 選擇Pin4 */
#define GPIO_Pin_5 ((uint16_t)0x0020) /*!< 選擇Pin5 */
#define GPIO_Pin_6 ((uint16_t)0x0040) /*!< 選擇Pin6 */
#define GPIO_Pin_7 ((uint16_t)0x0080) /*!< 選擇Pin7 */
#define GPIO_Pin_8 ((uint16_t)0x0100) /*!< 選擇Pin8 */
#define GPIO_Pin_9 ((uint16_t)0x0200) /*!< 選擇Pin9 */
#define GPIO_Pin_10 ((uint16_t)0x0400) /*!< 選擇Pin10 */
#define GPIO_Pin_11 ((uint16_t)0x0800) /*!< 選擇Pin11 */
#define GPIO_Pin_12 ((uint16_t)0x1000) /*!< 選擇Pin12 */
#define GPIO_Pin_13 ((uint16_t)0x2000) /*!< 選擇Pin13 */
#define GPIO_Pin_14 ((uint16_t)0x4000) /*!< 選擇Pin14 */
#define GPIO_Pin_15 ((uint16_t)0x8000) /*!< 選擇Pin15 */
#define GPIO_Pin_All ((uint16_t)0xFFFF) /*!< 選擇全部引腳 */

/** 
* GPIO埠配置模式的枚舉定義 
*/ 
typedef enum { 
  GPIO_Mode_IN = 0x00, /*!< 輸入模式 */ 
  GPIO_Mode_OUT = 0x01, /*!< 輸出模式 */ 
  GPIO_Mode_AF = 0x02, /*!< 複用模式 */ 
  GPIO_Mode_AN = 0x03 /*!< 類比模式 */ 
} GPIOMode_TypeDef; 

/** 
* GPIO輸出類型枚舉定義 
*/ 
typedef enum { 
  GPIO_OType_PP = 0x00, /*!< 推挽模式 */ 
  GPIO_OType_OD = 0x01 /*!< 開漏模式 */ 
} GPIOOType_TypeDef; 

/** 
* GPIO輸出速率枚舉定義 
*/ 
typedef enum { 
  GPIO_Speed_2MHz = 0x00, /*!< 2MHz */ 
  GPIO_Speed_25MHz = 0x01, /*!< 25MHz */ 
  GPIO_Speed_50MHz = 0x02, /*!< 50MHz */ 
  GPIO_Speed_100MHz = 0x03 /*!<100MHz */ 
} GPIOSpeed_TypeDef; 

/** 
*GPIO上/下拉配置枚舉定義 
*/ 
typedef enum { 
  GPIO_PuPd_NOPULL = 0x00,/*浮空*/ 
  GPIO_PuPd_UP = 0x01, /*上拉*/ 
  GPIO_PuPd_DOWN = 0x02 /*下拉*/ 
} GPIOPuPd_TypeDef;

/** 
* GPIO初始化結構體類型定義 
*/ 
typedef struct { 
  uint32_t GPIO_Pin; /*!< 選擇要配置的GPIO引腳 
  可輸入 GPIO_Pin_ 定義的宏 */ 
  
  GPIOMode_TypeDef GPIO_Mode; /*!< 選擇GPIO引腳的工作模式 
  可輸入 GPIOMode_TypeDef 定義的枚舉值*/ 
  
  GPIOSpeed_TypeDef GPIO_Speed; /*!< 選擇GPIO引腳的速率 
  可輸入 GPIOSpeed_TypeDef 定義的枚舉值 */ 
  
  GPIOOType_TypeDef GPIO_OType; /*!< 選擇GPIO引腳輸出類型 
  可輸入 GPIOOType_TypeDef 定義的枚舉值*/
  
  GPIOPuPd_TypeDef GPIO_PuPd; /*!<選擇GPIO引腳的上/下拉模式 
  可輸入 GPIOPuPd_TypeDef 定義的枚舉值*/ 
} GPIO_InitTypeDef;

void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);