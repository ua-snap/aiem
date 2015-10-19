CC=g++
#CC=mpicxx
ALFDIR=/home/UA/apbennett/alfresco
GIPLDIR=/home/UA/apbennett/gipl
TEMDIR=/home/UA/apbennett/dvm-dos-tem
INCLUDES= \
	-I./include \
	-I./src \
	-I/home/UA/apbennett/include \
	-I$(ALFDIR)/include \
	-I$(GIPLDIR) \
	-I/usr/include/gdal \
	-I$(TEMDIR)/src \
	-I$(TEMDIR)/src/assembler \
	-I$(TEMDIR)/src/atmosphere \
	-I$(TEMDIR)/src/data \
	-I$(TEMDIR)/src/disturb \
	-I$(TEMDIR)/src/ecodomain \
	-I$(TEMDIR)/src/inc \
	-I$(TEMDIR)/src/input \
	-I$(TEMDIR)/src/lookup \
	-I$(TEMDIR)/src/output \
	-I$(TEMDIR)/src/runmodule \
	-I$(TEMDIR)/src/snowsoil \
	-I$(TEMDIR)/src/util \
	-I$(TEMDIR)/src/vegetation
LDFLAGS=-L/home/UA/apbennett/lib -L$(TEMDIR) -L$(GIPLDIR)
LIBS=-lFrescoAIEM -lPocoFoundation -lPocoXML -lPocoNet -lgdal -lTEM -lgipl -lboost_system -lboost_filesystem -lboost_program_options -ljsoncpp
EXEC=aiem
SRC=$(ALFDIR)/src/StatArray.cpp $(ALFDIR)/src/StatFile.cpp src/aiem.cpp src/CoupledData.cpp src/ArgHandler.cpp src/main.cpp
all:
	$(CC) $(INCLUDES) $(SRC) -o $(EXEC) $(LDFLAGS) $(LIBS)
clean:
	rm aiem
