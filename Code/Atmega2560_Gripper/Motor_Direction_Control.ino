/*============================================================================
// Author : Srinivas
// Project : Object Grabber
// Description : Each Motor Direction Control
//============================================================================
*/

void SET_motorA_clockwise (void) {
   /*Motor A - Left
   * Standard Direction - AntiClockwise (0 1 , IN1 IN2)
   */
  digitalWrite(MOTOR_A_DIR_PIN1, LOW);
  digitalWrite(MOTOR_A_DIR_PIN2, HIGH);
}

void SET_motorA_anticlockwise (void) {
   /*Motor A - Left
   * Standard Direction - AntiClockwise (1 0 , IN1 IN2)
   */
  digitalWrite(MOTOR_A_DIR_PIN1, HIGH);
  digitalWrite(MOTOR_A_DIR_PIN2, LOW);
}

void SET_motorB_clockwise (void) {
   /*Motor B - Right
   * Standard Direction - Clockwise (1 0 , IN3 IN4)
   */
  digitalWrite(MOTOR_B_DIR_PIN1, HIGH);
  digitalWrite(MOTOR_B_DIR_PIN2, LOW);
}

void SET_motorB_anticlockwise (void) {
   /*Motor B - Right
   * Standard Direction - Clockwise (0 1 , IN3 IN4)
   */
  digitalWrite(MOTOR_B_DIR_PIN1, LOW);
  digitalWrite(MOTOR_B_DIR_PIN2, HIGH);
}

void SET_motorC_clockwise (void) {
   /*Motor C - Left
   * Standard Direction - AntiClockwise (0 1 , IN5 IN6)
   */
  digitalWrite(MOTOR_C_DIR_PIN1, LOW);
  digitalWrite(MOTOR_C_DIR_PIN2, HIGH);
}

void SET_motorC_anticlockwise (void) {
   /*Motor C - Left
   * Standard Direction - AntiClockwise (1 0 , IN5 IN6)
   */
  digitalWrite(MOTOR_C_DIR_PIN1, HIGH);
  digitalWrite(MOTOR_C_DIR_PIN2, LOW);
}

void SET_motorD_clockwise (void) {
   /*Motor D - Right
   * Standard Direction - Clockwise (1 0 , IN7 IN8)
   */
  digitalWrite(MOTOR_D_DIR_PIN1, HIGH);
  digitalWrite(MOTOR_D_DIR_PIN2, LOW);
}

void SET_motorD_anticlockwise (void) {
   /*Motor D - Right
   * Standard Direction - Clockwise (0 1 , IN7 IN8)
   */
  digitalWrite(MOTOR_D_DIR_PIN1, LOW);
  digitalWrite(MOTOR_D_DIR_PIN2, HIGH);
}

void SET_motorE_clockwise (void) {
   /*Motor E - Right Side
   * Standard Direction - Clockwise (1 0 , IN9 IN10)
   */
  digitalWrite(MOTOR_E_DIR_PIN1, HIGH);
  digitalWrite(MOTOR_E_DIR_PIN2, LOW);
}

void SET_motorE_anticlockwise (void) {
   /*Motor E - Right Side
   * Standard Direction - Clockwise (0 1 , IN9 IN10)
   */
  digitalWrite(MOTOR_E_DIR_PIN1, LOW);
  digitalWrite(MOTOR_E_DIR_PIN2, HIGH);
}

void SET_motorF_clockwise (void) {
   /*Motor F - Left Side
   * Standard Direction - AntiClockwise (0 1 , IN11 IN12)
   */
  digitalWrite(MOTOR_F_DIR_PIN1, LOW);
  digitalWrite(MOTOR_F_DIR_PIN2, HIGH);
}

void SET_motorF_anticlockwise (void) {
   /*Motor E - Left Side
   * Standard Direction - AntiClockwise (1 0 , IN11 IN12)
   */
  digitalWrite(MOTOR_F_DIR_PIN1, HIGH);
  digitalWrite(MOTOR_F_DIR_PIN2, LOW);
}
