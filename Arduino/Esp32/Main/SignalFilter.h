#pragma once

#include <Kalman.h>

static const int Nobs = 1;      // 1 filter input:   observed value
static const int Nstate = 2;    // 2 filter outputs: change & velocity

class KalmanFilter {
private:
  KALMAN<Nstate,Nobs> _K;
  unsigned long _timeLastObservation;

public:
  KalmanFilter(float varianceEstimate);

  float filteredValue(float observation);
  float changeVelocity();
};
