/*============================================================================
// Author : Srinivas
// Project : Object Grabber
// Description : Bluetooth/Serial data communication and verification
//============================================================================
*/

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
  }else if(ch == MOVE_UTURN_RIGHT_COMMAND) {
    /*
    BT_SERIAL.print("Moving Backward Left ... ");
    BT_SERIAL.println(ch);
    */
    move_uTurnRight();
  }else if(ch == MOVE_UTURN_LEFT_COMMAND) {
    /*
    BT_SERIAL.print("Moving Backward Left ... ");
    BT_SERIAL.println(ch);
    */
    move_uTurnLeft();
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
  }else if(ch == MOVE_GRIPPER_UP) {
    /*
    BT_SERIAL.print("Move Gripper Up ... ");
    BT_SERIAL.println(ch);
    */
    move_grip_up();
  }else if(ch == MOVE_GRIPPER_DOWN) {
    /*
    BT_SERIAL.print("Move Gripper Down ... ");
    BT_SERIAL.println(ch);
    */
    move_grip_down();
  }else if(ch == STOP_MOTOR) {
    /*
    BT_SERIAL.print("Stop All Motor ... ");
    BT_SERIAL.println(ch);
    */
    TURNOFF_all_Motor();
  }else if(ch == LINE_FEED || ch == CARRIAGE_RETURN) {
    /* Do nothing */
  }
  else {
    BT_SERIAL.print("Error ... ");
    BT_SERIAL.println(ch);
  }
}
