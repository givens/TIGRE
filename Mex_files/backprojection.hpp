
#ifndef BACKPROJECTION_HPP
#define BACKPROJECTION_HPP
typedef struct {
    // Geometry assumptions:
    //  -> Origin is at (0,0,0). Image center is there +offOrig
    //  -> at angle 0, source + image centre (without the offset) + detector centre (without offset) 
    //     are aligned in the Y_Z plane.
    //  -> detector is orthonormal to projection plane.
    
    //Parameters part of the image geometry
    int   nVoxelX, nVoxelY, nVoxelZ;
    double sVoxelX, sVoxelY, sVoxelZ;
    double dVoxelX, dVoxelY, dVoxelZ;
    double *offOrigX,*offOrigY,*offOrigZ;
    double DSO;
    // Parameters  of the Detector.
    int   nDetecU, nDetecV;
    double sDetecU, sDetecV;
    double dDetecU, dDetecV;
    double *offDetecU, *offDetecV;
    double DSD;
    
    // The base unit we are working with in mm. 
    double unitX;
    double unitY;
    double unitZ;
    
    //projection angle
    double alpha;
    
    //Maximum length of cube
    double maxLength;
     //User option
    double accuracy;
}Geometry;

typedef struct{
    double x;
    double y;
    double z;
}Point3D;
int backprojection(float const * const projections, Geometry geo, double* result,double const * const alphas,int nalpha);
void computeDeltasCube(Geometry geo, double alpha,int i, Point3D* xyzorigin, Point3D* deltaX, Point3D* deltaY, Point3D* deltaZ);
#endif