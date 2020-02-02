/*============================================================================
// Author : Srinivas
// Project : Object Grabber
// Description : L298N Motor Driver, Arduino Mega
// Program: Control 6 DC motors using L298N H Bridge Driver based on BT input
//============================================================================
*/

/* Defines */

#define MOTOR_A_DIR_PIN1            22
#define MOTOR_A_DIR_PIN2            23
#define MOTOR_B_DIR_PIN1            24
#define MOTOR_B_DIR_PIN2            25
#define MOTOR_C_DIR_PIN1            26
#define MOTOR_C_DIR_PIN2            27
#define MOTOR_D_DIR_PIN1            28
#define MOTOR_D_DIR_PIN2            29
#define MOTOR_E_DIR_PIN1            30
#define MOTOR_E_DIR_PIN2            31
#define MOTOR_F_DIR_PIN1            32
#define MOTOR_F_DIR_PIN2            33

#define MOTOR_A_PWM_PIN             A1 
#define MOTOR_B_PWM_PIN             A2
#define MOTOR_C_PWM_PIN             A3
#define MOTOR_D_PWM_PIN             A4
#define MOTOR_E_PWM_PIN             A5
#define MOTOR_F_PWM_PIN             A6

#define PWM_VALUE                   255

#define BT_SERIAL                   Serial3
#define BT_BAUD                     9600

#define USB_SERIAL                  Serial
#define USB_BAUD                    9600

/*Communication Protocol */
#define START_BIT                   123     // '{' character      
#define END_BIT                     125     // '}' character
#define MOVE_FORWARD_COMMAND        97      // 'a' character
#define MOVE_BACKWARD_COMMAND       98      // 'b' character
#define MOVE_RIGHT_COMMAND          99      // 'c' character
#define MOVE_LEFT_COMMAND           100     // 'd' character
#define MOVE_FORWARD_RIGHT_COMMAND  101     // 'e' character
#define MOVE_FORWARD_LEFT_COMMAND   102     // 'f' character
#define MOVE_BACKWARD_RIGHT_COMMAND 103     // 'g' character
#define MOVE_BACKWARD_LEFT_COMMAND  104     // 'h' character
#define MOVE_UTURN_RIGHT_COMMAND    105     // 'i' character
#define MOVE_UTURN_LEFT_COMMAND     106     // 'j' character
#define HOLD_GRIPPER                107     // 'k' character
#define RELEASE_GRIPPER             108     // 'l' character
#define MOVE_GRIPPER_UP             109     // 'm' character
#define MOVE_GRIPPER_DOWN           110     // 'n' character
#define STOP_MOTOR                  111     // 'o' character
#define LINE_FEED                   10        
#define CARRIAGE_RETURN             13

/* Global Variables */

/* Global Structures & Typedefs */

/* Main Program */

void setup() {
  init_DI();
  BT_SERIAL.begin(BT_BAUD);
  USB_SERIAL.begin(USB_BAUD);
  TURNOFF_all_Motor();
  SET_motor_PWM();
}

void loop() {
  if(BT_SERIAL.available() > 0) {
    SERIAL_READ();
  }
}

void init_DI (void) {
  
  pinMode(MOTOR_A_DIR_PIN1, OUTPUT);
  pinMode(MOTOR_A_DIR_PIN2, OUTPUT);
  pinMode(MOTOR_B_DIR_PIN1, OUTPUT);
  pinMode(MOTOR_B_DIR_PIN2, OUTPUT);
  pinMode(MOTOR_C_DIR_PIN1, OUTPUT);
  pinMode(MOTOR_C_DIR_PIN2, OUTPUT);
  pinMode(MOTOR_D_DIR_PIN1, OUTPUT);
  pinMode(MOTOR_D_DIR_PIN2, OUTPUT);
  pinMode(MOTOR_E_DIR_PIN1, OUTPUT);
  pinMode(MOTOR_E_DIR_PIN2, OUTPUT);
  pinMode(MOTOR_F_DIR_PIN1, OUTPUT);
  pinMode(MOTOR_F_DIR_PIN2, OUTPUT);
  
  pinMode(MOTOR_A_PWM_PIN, OUTPUT);
  pinMode(MOTOR_B_PWM_PIN, OUTPUT);
  pinMode(MOTOR_C_PWM_PIN, OUTPUT);
  pinMode(MOTOR_D_PWM_PIN, OUTPUT);
  pinMode(MOTOR_E_PWM_PIN, OUTPUT);
  pinMode(MOTOR_F_PWM_PIN, OUTPUT);

}
