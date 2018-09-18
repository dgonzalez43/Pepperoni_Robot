/* 8 Infrared sensors are placed in the front of the robot.
 * /* 5 Infrared sensors are placed in the front of the robot.
 * I/Connection diagram:
 * 1,H-Bridge to Arduino:
 * -Red H Bridge (Left side):
 *    +ENA: PIN 5 (PWM)
 *    +IN1: PIN 32
 *    +IN2: PIN 30
 *    +IN3: PIN 34
 *    +IN4: PIN 36
 *    +ENB: PIN 4 (PWM)
 * - Black H-Bridge to Arduino (Right Side):
 *    +ENA: PIN 3 (PWM)
 *    +IN1: PIN 26
 *    +IN2: PIN 28
 *    +IN3: PIN 24
 *    +IN4: PIN 22
 *    +ENB: PIN 2 (PWM)
 * -Moving Forward DIR1 : LOW ; DIR2: HIGH
 * 
       
 * 2/ IR sensors to Arduino( From Left to Right- IR1 IR2 IR3 IR4 IR5):
 *    +IR1: A0
 *    +IR2: A1
 *    +IR3: A2
 *    +IR4: A3
 *    +IR5: A4
 *    +IR6:A5
 *    +IR7:A6
 *    +IR8:A7
 */
