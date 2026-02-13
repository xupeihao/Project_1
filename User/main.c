#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
//头文件，可不加
#include "gd32f4xx_rcu.h"
#include "gd32f4xx_gpio.h"

void GPIO_Config()
{
	rcu_periph_clock_enable(RCU_GPIOB);
    gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_2);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2);
}

int main(void)
{
	systick_config();
	GPIO_Config();
		
    while(1) 
	{
		gpio_bit_write(GPIOB, GPIO_PIN_2, RESET);
		delay_1ms(500);
		gpio_bit_write(GPIOB, GPIO_PIN_2, SET);
		delay_1ms(500);
    }
}

