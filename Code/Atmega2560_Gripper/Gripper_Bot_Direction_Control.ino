/*============================================================================
// Author : Srinivas
// Project : Object Grabber
// Description : Gripper Bot Direction Control
//============================================================================
*/

void move_forward (void) {
  SET_motorA_anticlockwise();
  SET_motorB_anticlockwise();
  SET_motorC_clockwise();
  SET_motorD_clockwise();
  SET_motor_A_PWM();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
  SET_motor_D_PWM();
}
void move_backward (void) {
  SET_motorA_clockwise();
  SET_motorB_clockwise();
  SET_motorC_anticlockwise();
  SET_motorD_anticlockwise();
  SET_motor_A_PWM();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
  SET_motor_D_PWM();
}
void move_left (void) {
  SET_motorA_anticlockwise();
  SET_motorB_anticlockwise();
  SET_motorC_clockwise();
  SET_motorD_clockwise();
  SET_motor_A_PWM();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
  SET_motor_D_PWM();
}
void move_right (void) {
  SET_motorA_clockwise();
  SET_motorB_clockwise();
  SET_motorC_anticlockwise();
  SET_motorD_anticlockwise();
  SET_motor_A_PWM();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
  SET_motor_D_PWM();
}
void move_rightTopCross (void) {
  SET_motorB_anticlockwise();
  SET_motorC_anticlockwise();
  SET_motor_A_off();
  SET_motor_D_off();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
}
void move_leftTopCross (void) {
  SET_motorA_anticlockwise();
  SET_motorD_anticlockwise();
  SET_motor_B_off();
  SET_motor_C_off();
  SET_motor_A_PWM();
  SET_motor_D_PWM();
}
void move_rightBottomCross (void) {
  SET_motorB_clockwise();
  SET_motorC_clockwise();
  SET_motor_A_off();
  SET_motor_D_off();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
}
void move_leftBottomCross (void) {
  SET_motorA_clockwise();
  SET_motorD_clockwise();
  SET_motor_B_off();
  SET_motor_C_off();
  SET_motor_A_PWM();
  SET_motor_D_PWM();
}

void move_uTurnLeft (void) {
  SET_motorA_clockwise();
  SET_motorC_clockwise();
  SET_motorB_anticlockwise();
  SET_motorD_anticlockwise();
  SET_motor_A_PWM();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
  SET_motor_D_PWM();
}


void move_uTurnRight (void) {
  SET_motorA_anticlockwise();
  SET_motorC_anticlockwise();
  SET_motorB_clockwise();
  SET_motorD_clockwise();
  SET_motor_A_PWM();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
  SET_motor_D_PWM();
}

void grip_motor (void) {
  SET_motorE_clockwise();
  SET_motor_E_PWM();
}

void release_motor (void) {
  SET_motorE_anticlockwise();
  SET_motor_E_PWM();
}

void move_grip_up (void) {
  SET_motorF_clockwise();
  SET_motor_F_PWM();
}

void move_grip_down (void) {
  SET_motorF_anticlockwise();
  SET_motor_F_PWM();
}
