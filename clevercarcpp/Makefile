CXXFLAGS =	-O0 -g -Wall -fmessage-length=0

OBJS =		 InoNav.o InoBackLeftReviser.o InoSonicFaceSensor.o InoDriver.o InoTraction.o InoGroundFaceSensor.o InoControlSensor.o inoCapabilities.o InoBeeper.o test/mock/MockReviser.o Reviser.o CleverCar.o test/mock/MockFaceSensor.o FaceSensor.o test/mock/MockControlSensor.o ControlSensor.o test/mock/MockBeeper.o Beeper.o test/mock/MockTraction.o Traction.o TractionCommand.o Command.o CommandBus.o test/mainTest.o test/util/String.o test/mock/Witness.o

LIBS =

TARGET =	test/mainTest

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
