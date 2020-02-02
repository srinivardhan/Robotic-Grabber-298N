/*============================================================================
// Author : Srinivas
// Project : Object Grabber
// Description : All Power Control
//============================================================================
*/

void SET_motor_A_off (void) {
  digitalWrite(MOTOR_A_DIR_PIN1, LOW);
  digitalWrite(MOTOR_A_DIR_PIN2, LOW);
}

void SET_motor_B_off (void) {
  digitalWrite(MOTOR_B_DIR_PIN1, LOW);
  digitalWrite(MOTOR_B_DIR_PIN2, LOW);
}

void SET_motor_C_off (void) {
  digitalWrite(MOTOR_C_DIR_PIN1, LOW);
  digitalWrite(MOTOR_C_DIR_PIN2, LOW);
}

void SET_motor_D_off (void) {
  digitalWrite(MOTOR_D_DIR_PIN1, LOW);
  digitalWrite(MOTOR_D_DIR_PIN2, LOW);
}

void SET_motor_E_off (void) {
  digitalWrite(MOTOR_E_DIR_PIN1, LOW);
  digitalWrite(MOTOR_E_DIR_PIN2, LOW);
}

void SET_motor_F_off (void) {
  digitalWrite(MOTOR_F_DIR_PIN1, LOW);
  digitalWrite(MOTOR_F_DIR_PIN2, LOW);
}

void SET_motor_A_PWM (void) {
  analogWrite(MOTOR_A_PWM_PIN, PWM_VALUE);
}

void SET_motor_B_PWM (void) {
  analogWrite(MOTOR_B_PWM_PIN, PWM_VALUE);
}

void SET_motor_C_PWM (void) {
  analogWrite(MOTOR_C_PWM_PIN, PWM_VALUE);
}

void SET_motor_D_PWM (void) {
  analogWrite(MOTOR_D_PWM_PIN, PWM_VALUE);
}

void SET_motor_E_PWM (void) {
  analogWrite(MOTOR_E_PWM_PIN, PWM_VALUE);
}

void SET_motor_F_PWM (void) {
  analogWrite(MOTOR_F_PWM_PIN, PWM_VALUE);
}

void SET_motor_PWM (void) {
  SET_motor_A_PWM();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
  SET_motor_D_PWM();
  SET_motor_E_PWM();
  SET_motor_F_PWM();
}
void TURNOFF_all_Motor (void) {
  SET_motor_A_off();
  SET_motor_B_off();
  SET_motor_C_off();
  SET_motor_D_off();
  SET_motor_E_off();
  SET_motor_F_off();
}
