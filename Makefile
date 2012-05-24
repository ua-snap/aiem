CC=g++
INCLUDE=-I/home/apbennett/alfresco/include -I/home/apbennett/gipl -I/usr/include/gdal \
	-I/home/apbennett/DOSTEM/src \
	-I/home/apbennett/DOSTEM/src/atmosphere \
	-I/home/apbennett/DOSTEM/src/disturb \
	-I/home/apbennett/DOSTEM/src/ground \
	-I/home/apbennett/DOSTEM/src/inc \
	-I/home/apbennett/DOSTEM/src/input \
	-I/home/apbennett/DOSTEM/src/lookup \
	-I/home/apbennett/DOSTEM/src/run \
	-I/home/apbennett/DOSTEM/src/runmodes \
	-I/home/apbennett/DOSTEM/src/util \
	-I/home/apbennett/DOSTEM/src/vegetation	
LDFLAGS=-L/home/apbennett/alfinstalldir/lib -L/home/apbennett/DOSTEM -L/home/apbennett/gipl
LIBS=-lFrescoCustom -lFrescoFoundation -lGIPL -lPocoFoundation -lPocoXML -lPocoNet -lgdal -lTEM
EXEC="aiem"
SRC=~/alfresco/src/StatArray.cpp ~/alfresco/src/StatFile.cpp aiem.cpp
all:
	$(CC) $(INCLUDE) $(SRC) -o $(EXEC) $(LDFLAGS) $(LIBS)
clean:
	rm aiem
