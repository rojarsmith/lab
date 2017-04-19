/*片上外設基地址 */ 
#define PERIPH_BASE ((unsigned int)0x40000000) 
/*總線基地址 */ 
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000) 
/*GPIO外設基地址*/ 
#define GPIOH_BASE (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASE (AHB1PERIPH_BASE + 0x2000)

/* GPIOH寄存器地址,強制轉換成指針 */ 
#define GPIOH_MODER *(unsigned int*)(GPIOH_BASE+0x00) 
#define GPIOH_OTYPER *(unsigned int*)(GPIOH_BASE+0x04) 
#define GPIOH_OSPEEDR *(unsigned int*)(GPIOH_BASE+0x08) 
#define GPIOH_PUPDR *(unsigned int*)(GPIOH_BASE+0x0C) 
#define GPIOH_IDR *(unsigned int*)(GPIOH_BASE+0x10) 
#define GPIOH_ODR *(unsigned int*)(GPIOH_BASE+0x14) 
#define GPIOH_BSRR *(unsigned int*)(GPIOH_BASE+0x18) 
#define GPIOH_LCKR *(unsigned int*)(GPIOH_BASE+0x1C) 
#define GPIOH_AFRL *(unsigned int*)(GPIOH_BASE+0x20) 
#define GPIOH_AFRH *(unsigned int*)(GPIOH_BASE+0x24) 

#define GPIOI_MODER *(unsigned int*)(GPIOI_BASE+0x00) 
#define GPIOI_OTYPER *(unsigned int*)(GPIOI_BASE+0x04) 
#define GPIOI_OSPEEDR *(unsigned int*)(GPIOI_BASE+0x08) 
#define GPIOI_PUPDR *(unsigned int*)(GPIOI_BASE+0x0C) 
#define GPIOI_IDR *(unsigned int*)(GPIOI_BASE+0x10) 
#define GPIOI_ODR *(unsigned int*)(GPIOI_BASE+0x14) 
#define GPIOI_BSRR *(unsigned int*)(GPIOI_BASE+0x18) 
#define GPIOI_LCKR *(unsigned int*)(GPIOI_BASE+0x1C) 
#define GPIOI_AFRL *(unsigned int*)(GPIOI_BASE+0x20) 
#define GPIOI_AFRH *(unsigned int*)(GPIOI_BASE+0x24)  

/*RCC外設基地址*/ 
#define RCC_BASE (AHB1PERIPH_BASE + 0x3800) 
/*RCC的AHB1時鐘使能寄存器地址,強制轉換成指針*/
#define RCC_AHB1ENR *(unsigned int*)(RCC_BASE+0x30)