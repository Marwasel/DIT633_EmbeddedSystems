// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 2023
// Work package 2
// Exercise 1
// Submission code:


#include <stdio.h> 
#include <string.h>

#define MAX_POS_INPUT 99
#define MIN_POS_INPUT 0



// stores the robot direction
char *directionOfRobot;

// robot directions possible
enum DIRECTION { N,O,S,W };

// defines the robot
typedef struct { 
        int xpos; 
        int ypos; 
        enum DIRECTION dir; 
} ROBOT; 
 
void setDirectionOfRobot(ROBOT *robot);
void move(ROBOT *robot);
void turn(ROBOT *robot);


//  takes a pointer to a ROBOT as input and sets the directionOfRobot variable 
// to the appropriate string representation of the robot's direction (N, O, S, W).
void setDirectionOfRobot(ROBOT *robot) {
switch (robot -> dir){
case N:
directionOfRobot = "N";
    break;

case O:
directionOfRobot = "O";
    break;

case S:
directionOfRobot = "S";
    break;

 case W:
directionOfRobot = "W";
    break;  
 
default:
    break;
}
}

/* takes a pointer to a ROBOT as input and updates the x and y position of the robot based
 on its direction (N, O, S, W). If the direction is N, the y position is incremented. 
 If the direction is O, the x position is incremented. If the direction is S, the y position is decremented. 
 If the direction is W, the x position is decremented. */
void move(ROBOT *robot) {
 // increase or decrease x, y based on the robot direction,and if value is between 0-99.
   if (robot->dir == N) {       
      robot->ypos++; // increment position
   } else if (robot-> dir == O) { 
      robot->xpos++; // increment position
   } else if (robot-> dir == S) { 
      robot->ypos--; // decrement position
   } else if (robot-> dir == W) {
      robot->xpos--; // decrement position
   }
}


/* takes a pointer to a ROBOT as input and updates the direction of the robot.
If the direction is N, it is set to O. If the direction is O, it is set to S. 
If the direction is S, it is set to W. If the direction is W, it is set to N. */
void turn(ROBOT *robot) {

switch (robot-> dir) {

case N:
robot -> dir = O;
    break;

case O:
robot -> dir = S;
    break;

case S:
robot -> dir = W;
    break;

case W:
robot -> dir = N;
    break;

default:
printf("wrong direction!");
    break;
}
}

/* 
  The direction of the robot is then set using the setDirectionOfRobot function and the position and direction of the robot are printed to the screen.
   The loop continues until the user enters "q" to quit. */
int main(int argc, char *argv[]) {

ROBOT robot;
 char instructions[100];
 // set initial direction of robot to N
  robot.dir = N;

 // asks the user for the starting x and y position of the robot 
  printf("Enter starting x position (0-99): ");
  scanf("%d", &robot.xpos);
  printf("Enter starting y position (0-99): ");
  scanf("%d", &robot.ypos);

// in the while loop,the user is asked to enter a string of instructions(m for move, t for turn, q to quit). 
    while (1) {
    printf("Enter instructions (m for move, t for turn, q to quit: ");
    scanf("%s", instructions);
 // Execute instructions one by one
  for (int i = 0; i < strlen(instructions); i++) {
// if m, the instructions are executed and method move is called
      if (instructions[i] == 'm') {
        move(&robot);
// if t, the instructions are executed and method turn is called
      } else if (instructions[i] == 't') {
        turn(&robot);

      }
      // if q, the user quits the robot
    } if (strcmp(instructions, "q") == 0) {
      break;
}
//  updates the directionOfRobot string based on the direction stored in the robot structure.
     setDirectionOfRobot(&robot);

     // outputs the current position of the robot
    printf("%sX = %d; Y = %d; Heading towards: %s \n", " Robot position:\t", robot.xpos, robot.ypos, directionOfRobot);

}
}