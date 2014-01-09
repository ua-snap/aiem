#ifndef MODELDATA_H
#define MODELDATA_H
#include <ogr_geometry.h>

template<class T> class ModelData {
	/*
 	* Primary data storage for this variable
 	*/
        T **dataArray;

public:
	double XULCorner;
	double YULCorner;
	int domainXOffset;
	int domainYOffset;
        ModelData() : dataArray( T() ){

        }
	/*
 	* Set up domain size and allocate space for each variable
  	*/
	void setDomain(int width, int length){
		XULCorner = -1725223.205807;
		YULCorner = 2544412.932644;
		domainXOffset = 0;
		domainYOffset = 0;
		dataArray = new T*[width];
		for (int i = 0; i < width; i++){
			dataArray[i] = new T[length];
			for (int j = 0; j < length; j++){
				dataArray[i][j] = 0;
			}
		}	
	}
	/*
 	* Reset the dataArray for this variable
 	*/ 
	void clearData(){
		for (int i = 0; i < sizeof(dataArray); i++){
			for (int j = 0; j < sizeof(dataArray[i]); j++){
				dataArray[i][j] = 0;
			}
		}	
	}
	/*
 	* Set the value in the default x,y array, currently NAD83 Alaska Albers
 	*/ 
	void setValue( int x, int y, T val ){
		dataArray[x][y] = val;
	}
	/* 
 	* Set the value using the WGS84 position, referenced to the x,y array	
 	*/
	void setValue( double lat, double lon, T val ){
		int *coords = getAlbers(lat, lon);
		dataArray[coords[0]][coords[1]] = val;
	}
	/* Data fetch methods
	* Fetching can be done with either DD lat/lon or direct x,y coords 
	* The call method determines the input.  Output is the same.
	*/
	T getValue( int x, int y ){
		return dataArray[x][y];
	}
	T getValue( double lat, double lon ){
		int *coords = getAlbers(lat, lon);
	       	return dataArray[coords[0]][coords[1]];
	}
	int* getAlbers(double lat, double lon){
		/* 
		 ** Taking in Decimal Degrees (DD), and returning the X,Y location of the pixel in
		 ** Alaska Albers (NAD83) projection, offset by ALFRESCO Origin and Offset of
		 ** Bounding Box
		 * */
		OGRSpatialReference poSRS;
		poSRS.importFromEPSG( 4326 ); //Reference the incoming WGS84 Decimal Degree Format

		OGRSpatialReference poTRS;
		poTRS.importFromEPSG( 3338 ); //Reference the outgoing NAD83 Alaskan Albers projection

		OGRCoordinateTransformation *poCT;
		poCT = OGRCreateCoordinateTransformation( &poSRS, &poTRS );

		/* Simple array to hold lat/long for transformation */
		double* albers = new double[2];
		albers[0] = lon;
		albers[1] = lat;
		poCT->Transform(1, &albers[0], &albers[1]);

		/* Array to hold int converted output, in XY coordinates */
		int* alfcoords = new int[2];
		alfcoords[0] = round((albers[0] - XULCorner) / 1000) + domainXOffset;
		alfcoords[1] = round((YULCorner - albers[1]) / 1000) + domainYOffset;

		return alfcoords;
	}
};

#endif
