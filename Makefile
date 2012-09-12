CC=g++
TEMDIR=/home/apbennett/fmyuan/dvm-dos-tem
INCLUDES= -I/home/apbennett/aiem \
	-I/home/apbennett/alfresco/include \
	-I/home/apbennett/gipl \
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
LDFLAGS=-L/home/apbennett/lib -L$(TEMDIR) -L/home/apbennett/gipl
LIBS=-lFrescoAIEM -lPocoFoundation -lPocoXML -lPocoNet -lgdal -lTEM -lGIPL -lboost_system -lboost_filesystem -lboost_program_options
EXEC=aiem
SRC=/home/apbennett/alfresco/src/StatArray.cpp /home/apbennett/alfresco/src/StatFile.cpp aiem.cpp ArgHandler.cpp main.cpp
all:
	$(CC) $(INCLUDES) $(SRC) -o $(EXEC) $(LDFLAGS) $(LIBS)
clean:
	rm aiem
