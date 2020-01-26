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

#define SAMPLE_HOLD_COUNT           5

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
#define HOLD_GRIPPER                105     // 'i' character
#define RELEASE_GRIPPER             106     // 'j' character
#define LINE_FEED                   10        
#define CARRIAGE_RETURN             13

#define HARD_CODED_DELAY            600    // 1 sec - TODO: Still match better timing as delay visible

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
  TURNOFF_all_Motor();
  if(BT_SERIAL.available() > 0) {
    SERIAL_READ();
    delay(HARD_CODED_DELAY); // TODO : Should use interrupt with expiry concept instead of delay
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
void move_forward (void) {
  SET_motorA_anticlockwise();
  SET_motorC_anticlockwise();
  SET_motorB_clockwise();
  SET_motorD_clockwise();
  SET_motor_A_PWM();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
  SET_motor_D_PWM();
}
void move_backward (void) {
  SET_motorA_clockwise();
  SET_motorC_clockwise();
  SET_motorB_anticlockwise();
  SET_motorD_anticlockwise();
  SET_motor_A_PWM();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
  SET_motor_D_PWM();
}
void move_left (void) {
  SET_motorA_anticlockwise();
  SET_motorB_clockwise();
  SET_motorC_clockwise();
  SET_motorD_anticlockwise();
  SET_motor_A_PWM();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
  SET_motor_D_PWM();
}
void move_right (void) {
  SET_motorA_clockwise();
  SET_motorB_anticlockwise();
  SET_motorC_anticlockwise();
  SET_motorD_clockwise();
  SET_motor_A_PWM();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
  SET_motor_D_PWM();
}
void move_rightTopCross (void) {
  SET_motorB_clockwise();
  SET_motorC_anticlockwise();
  SET_motor_A_off();
  SET_motor_D_off();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
}
void move_leftTopCross (void) {
  SET_motorA_anticlockwise();
  SET_motorD_clockwise();
  SET_motor_B_off();
  SET_motor_C_off();
  SET_motor_A_PWM();
  SET_motor_D_PWM();
}
void move_rightBottomCross (void) {
  SET_motorB_anticlockwise();
  SET_motorC_clockwise();
  SET_motor_A_off();
  SET_motor_D_off();
  SET_motor_B_PWM();
  SET_motor_C_PWM();
}
void move_leftBottomCross (void) {
  SET_motorA_clockwise();
  SET_motorD_anticlockwise();
  SET_motor_B_off();
  SET_motor_C_off();
  SET_motor_A_PWM();
  SET_motor_D_PWM();
}

void grip_motor (void) {
  SET_motorE_clockwise();
  SET_motorF_anticlockwise();
  SET_motor_E_PWM();
  SET_motor_F_PWM();
}

void release_motor (void) {
  SET_motorE_anticlockwise();
  SET_motorF_clockwise();
  SET_motor_E_PWM();
  SET_motor_F_PWM();
}

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

void SERIAL_READ (void) {
  uint8_t ch = BT_SERIAL.read();
  if(ch == MOVE_FORWARD_COMMAND) {
    /*
    BT_SERIAL.print("Moving Forward ... ");
    BT_SERIAL.println(ch);
    */
    move_forward();    
  }else if(ch == MOVE_BACKWARD_COMMAND) {
    /*
    BT_SERIAL.print("Moving Backward ... ");
    BT_SERIAL.println(ch);
    */
    move_backward();
  }else if(ch == MOVE_RIGHT_COMMAND) {
    /*
    BT_SERIAL.print("Moving Right ... ");
    BT_SERIAL.println(ch);
    */
    move_right();
  }else if(ch == MOVE_LEFT_COMMAND) {
    /*
    BT_SERIAL.print("Moving Left ... ");
    BT_SERIAL.println(ch);
    */
    move_left();
  }else if(ch == MOVE_FORWARD_RIGHT_COMMAND){
    /*
    BT_SERIAL.print("Moving Forward Right ... ");
    BT_SERIAL.println(ch);
    */
    move_rightTopCross();
  }else if(ch == MOVE_FORWARD_LEFT_COMMAND) {
    /*
    BT_SERIAL.print("Moving Forward Left ... ");
    BT_SERIAL.println(ch);
    */
    move_leftTopCross();
  }else if(ch == MOVE_BACKWARD_RIGHT_COMMAND) {
    /*
    BT_SERIAL.print("Moving Backward Right ... ");
    BT_SERIAL.println(ch);
    */
    move_rightBottomCross();
  }else if(ch == MOVE_BACKWARD_LEFT_COMMAND) {
    /*
    BT_SERIAL.print("Moving Backward Left ... ");
    BT_SERIAL.println(ch);
    */
    move_leftBottomCross();
  }else if(ch == HOLD_GRIPPER) {
    /*
    BT_SERIAL.print("Holding Gripper ... ");
    BT_SERIAL.println(ch);
    */
    grip_motor();
  }else if(ch == RELEASE_GRIPPER) {
    /*
    BT_SERIAL.print("Releasing Gripper ... ");
    BT_SERIAL.println(ch);
    */
    release_motor();
  }else if(ch == LINE_FEED || ch == CARRIAGE_RETURN) {
    /* Do nothing */
  }
  else {
    BT_SERIAL.print("Error ... ");
    BT_SERIAL.println(ch);
  }
}

