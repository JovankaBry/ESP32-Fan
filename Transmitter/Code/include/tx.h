#pragma once

void txinit();
void commandLogics();
void sendCode (uint16_t* raw, const char* label);

extern uint16_t powerRaw[99];
extern uint16_t swingRaw[99];
extern uint16_t modeRaw[99];
extern uint16_t speedUpRaw[99];
extern uint16_t speedDownRaw[99];
extern uint16_t timerRaw[99];
extern uint16_t lockRaw[99];