# Macros ======================================================================

DRIVER= Drivers/driversample_Test0.cpp
DRIVEROBJECT= Object_Files/driversample_Test0.o
EXECUTABLE= Executables/driversample_Test0.exe
OBJECTS= Object_Files/Ocean.o Object_Files/PRNG.o $(DRIVEROBJECT)
OCEANSOURCE= Source\Ocean.cpp Source\Ocean.h Source\WarBoats.h
PRNGSOURCE= Source\PRNG.cpp Source\PRNG.h
FLAGS=-Wall -Wextra -Werror -O -ansi -pedantic

# Targets =====================================================================

$(EXECUTABLE) : $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS)
  
Object_Files/Ocean.o : $(OCEANSOURCE)
	g++ -c $(FLAGS) -o Object_Files/Ocean.o Source/Ocean.cpp
  
Object_Files/PRNG.o : $(PRNGSOURCE)
	g++ -c $(FLAGS) -o Object_Files/PRNG.o Source/PRNG.cpp
	
$(DRIVEROBJECT) : $(DRIVER)
	g++ -c $(FLAGS) -o $(DRIVEROBJECT) $(DRIVER)
	
clean :
	rm $(EXECUTABLE) $(DRIVEROBJECT)