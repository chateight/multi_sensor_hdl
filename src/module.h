#include <M5Stack.h>
#include <Wire.h>
#include "env_sensor/env.h"
#include "thermo_sensor/thermo.h"
#include "dist.h"
#include "MAX30100_PulseOximeter.h"

int setup_dist();
void loop_dist();
int setup_thermo();
void loop_thermo();
int setup_oxi();
void loop_oxi();

void sensor_error();
void read_batt();

