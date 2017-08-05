#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp = Kp;
  Ki = Ki;
  Kd = Kd;
  p_error = 0;
  i_error = 0;
  d_error = 0;
  //window      = (int*) calloc( WINDOW_SIZE , sizeof(window[0]) ) ;
  //i           = WINDOW_SIZE - 1 ;
  //sum         = 0 ;
}

void PID::UpdateError(double cte) {
 // d_error is difference from old cte (p_error) to the new cte
  d_error = (cte - p_error);
  // p_error gets set to the new cte
  p_error = cte;
  // i_error is the sum of ctes to this point
  i_error += cte;
}

double PID::TotalError(double speed) {
  return -Kp * p_error - Kd * d_error - Ki * i_error;
  //return (Kp - 0.0032 * speed) * p_error + Ki * i_error + (Kd + 0.0002 * speed) * d_error;
}

