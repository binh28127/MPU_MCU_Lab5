#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define NO_OF_TIMER		2

int isTimerUp(int timer);
void setTimer(int timer, int duration);
void timerRun();

#endif /* INC_TIMER_H_ */
