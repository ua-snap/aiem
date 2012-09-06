CC=g++
INCLUDES= -I/home/apbennett/aiem \
	-I/home/apbennett/alfresco/include \
	-I/home/apbennett/gipl \
	-I/usr/include/gdal \
	-I/home/apbennett/dvm-dos-tem/src \
	-I/home/apbennett/dvm-dos-tem/src/assembler \
	-I/home/apbennett/dvm-dos-tem/src/atmosphere \
	-I/home/apbennett/dvm-dos-tem/src/data \
	-I/home/apbennett/dvm-dos-tem/src/disturb \
	-I/home/apbennett/dvm-dos-tem/src/ecodomain \
	-I/home/apbennett/dvm-dos-tem/src/inc \
	-I/home/apbennett/dvm-dos-tem/src/input \
	-I/home/apbennett/dvm-dos-tem/src/lookup \
	-I/home/apbennett/dvm-dos-tem/src/output \
	-I/home/apbennett/dvm-dos-tem/src/runmodule \
	-I/home/apbennett/dvm-dos-tem/src/snowsoil \
	-I/home/apbennett/dvm-dos-tem/src/util \
	-I/home/apbennett/dvm-dos-tem/src/vegetation
LDFLAGS=-L/home/apbennett/lib -L/home/apbennett/dvm-dos-tem -L/home/apbennett/gipl
LIBS=-lFrescoAIEM -lPocoFoundation -lPocoXML -lPocoNet -lgdal -lTEM -lGIPL -lboost_system -lboost_filesystem -lboost_program_options
EXEC=aiem
SRC=/home/apbennett/alfresco/src/StatArray.cpp /home/apbennett/alfresco/src/StatFile.cpp aiem.cpp ArgHandler.cpp main.cpp
all:
	$(CC) $(INCLUDES) $(SRC) -o $(EXEC) $(LDFLAGS) $(LIBS)
clean:
	rm aiem
