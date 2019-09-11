// Beeper ------------------------------------------------------ /

void beepMillis(int milliseconds);

// IR Remote --------------------------------------------------- /

int remoteControlTick();

// Ultrasonic sensor ------------------------------------------- /

bool sonicWatch();

// Turnable head servo motor ----------------------------------- /

void turnHeadDegrees(int degrees);

// Ground sensor ----------------------------------------------- /

int groundWatch();

// Traction engines -------------------------------------------- /

void forwardLeft();

void rewindLeft();

void stopLeft();

void forwardRight();

void rewindRight();

void stopRight();

void setMotorSpeed(int speedLeft, int speedRight);

void delayMillis(int milliseconds);
