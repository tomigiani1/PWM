/* Project includes. */
#include "main.h"


/* App includes. */
#include <stdlib.h>
#include "app.h"
#include "logger.h"

/* Application includes. */


/********************** macros and definitions *******************************/

#define TEST_1 (1)
#define TEST_2 (2)

#define TEST_NUMBER TEST_1 //TEST_1, TEST_2

#define DELAY_TICKS (4)
#define STEP (100)
#define PERIOD (65535)

/********************** external data declaration *****************************/
extern TIM_HandleTypeDef htim3;

/********************** external functions definition ************************/

/********************** internal data declaration ****************************/
uint32_t tickstart;


/********************** internal data definition *****************************/

/********************** internal functions definitions ***********************/
void test1_tick();
void test2_tick();

void setPWM(TIM_HandleTypeDef timer,
            uint32_t channel,
            uint16_t period,
            uint16_t pulse);


/********************** internal functions declaration ***********************/



void app_init(void)
{


}

void app_update(void)
{
#if TEST_1==TEST_NUMBER
	test1_tick();
#endif
#if TEST_2==TEST_NUMBER
	test2_tick();
#endif

}



#if TEST_1==TEST_NUMBER
void test1_tick() {

	static uint16_t active = 0;
	static uint16_t period=PERIOD;
	static bool first = true;
	static uint32_t tick;
	static int16_t step = STEP;

	if (first) {
		first = false;
		tick = HAL_GetTick() + DELAY_TICKS;
	}

	if (HAL_GetTick()>=tick) {
		setPWM(htim3, TIM_CHANNEL_1, period, active);
		if (step>0) {
			if (period-step<=active) {
				step = step * -1;
			}
		}
		else {
			if (abs(step)>=active) {
				step = step * -1;
			}
		}
		active = active + step;
		tick = HAL_GetTick() + DELAY_TICKS;
	}
}
#endif

#if TEST_2==TEST_NUMBER
void test2_tick() {

	static uint16_t period=PERIOD/4;
	static bool first = true;
	static uint32_t tick;
	static int16_t step = STEP;

	if (first) {
		first = false;
		tick = HAL_GetTick() + DELAY_TICKS;
	}

	if (HAL_GetTick()>=tick) {
		setPWM(htim3, TIM_CHANNEL_1, period, period/2);
		if (step>0) {
			if (period-step>=PERIOD/2) {
				step = step * -1;
			}
		}
		else {
			if (period-step<=PERIOD/4) {
				step = step * -1;
			}
		}
		period = period + step;
		tick = HAL_GetTick() + DELAY_TICKS;
	}
}
#endif

void setPWM(TIM_HandleTypeDef timer,
            uint32_t channel,
            uint16_t period,
            uint16_t pulse) {
  HAL_TIM_PWM_Stop(&timer, channel);
  TIM_OC_InitTypeDef sConfigOC;
  timer.Init.Period = period;
  HAL_TIM_PWM_Init(&timer);

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = pulse;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(&timer, &sConfigOC, channel);

  HAL_TIM_PWM_Start(&timer,channel);
}


/********************** end of file ******************************************/
