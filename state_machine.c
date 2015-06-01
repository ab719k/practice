/* State machine implementation */



typedef enum {
  STATE1,
  STATE2,
  STATE3
} state;

typedef enum {
  NILEVENT,
  EVENT1,
  EVENT2
} event;	

typedef void (*action)();
 
// General functions
void stateEval(event e);
void exit(int status);
void getIOValues(void);
 
//Actions
 void action_s1_e1(void);
 void action_s1_e2(void);
 void action_s1_e3(void);
 void action_s2_e1(void);
 void action_s2_e2(void);
 void action_s2_e3(void);
 void action_s3_e1(void);
 void action_s3_e2(void);
 void action_s3_e3(void);

stateElement stateMatrix[3][3] = {
   { {STATE1, action_s1_e1}, {STATE2, actions_1_e2}, {STATE3, action_s1_3} },
   { {STATE2, action_s2_e1}, {STATE2, actions_2_e2}, {STATE3, action_s2_3} },
   { {STATE3, action_s3_e1}, {STATE3, actions_3_e2}, {STATE3, action_s3_3} }
};


typedef struct {
    state nextState;       // Enumerator for the next state
    action actionToDo;     // function-pointer to the action that shall be released in current state
}  stateElement;               // structure for the elements in the state-event matrix


state  currentState = STATE1;

int check_input();

int check_input()
{
  return 1;
}

int main(int argc, char *argv[])
{
  if (check_input())
  {
      return -1;
  }

    //Initializations
    event  eventOccured = NILEVENT;
    action actionToDo   = action_s1_e1;
 
    while(1) {
        // event input, NIL-event for non-changing input-alphabet of FSM
        // in real implementation this should be triggered by event registers e.g.
        // evaluation of complex binary expressions could be implemented to release the events
 
                int e = 0;            
 
               printf("----------------\n");
               printf("Event to occure: ");
               scanf("%u",&e);
               stateEval( (event) e); // typecast to event enumeration type
               printf("-----------------\n");
 
    };
    return (0);



/********************************************************************************
 * stateEval (event)
 * in Dependancy of an triggered event, the action wich is required by this
 * transition will be returned. The proper action is determined by the current state the
 * automat holds. The current state will then be transitioned to the requestet next
 * state
 ********************************************************************************/
 
void stateEval(event e)
{
    //determine the State-Matrix-Element in dependany of current state and triggered event
        stateElement stateEvaluation = stateMatrix[currentState][e];
 
    //do the transition to the next state (set requestet next state to current state)...
    currentState = stateEvaluation.nextState;
    //... and fire the proper action
    (*stateEvaluation.actionToDo)();
}
 
/**********************************************************************
 * action functions
 **********************************************************************/
 
void action_s1_e1() {
  printf("action1.1 \n");
}
 
void action_s1_e2() {
  printf("action1.2 \n");
}
 
 void action_s1_e3() {
  printf("action1.3 \n");
 }
 
 void action_s2_e1() {
  printf("action2.1 \n");
 }
 
 void action_s2_e2() {
  printf("action2.2 \n");
 }
 
 void action_s2_e3() {
  printf("action2.3 \n");
 }
 
 void action_s3_e1() {
  printf("action3.1 \n");
 }
 
 void action_s_s3_e2() {
  printf("action3.2 \n");
 }
 
 void action_S3_e3() {
  printf("action3.3 \n");
 }



}
