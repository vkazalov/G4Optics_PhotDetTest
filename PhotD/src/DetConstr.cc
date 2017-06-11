#include "DetConstr.hh"
#include "DetEventAction.hh"


#include "SensitiveDetector.hh"
#include "DetEventAction.hh"
#include "G4SDManager.hh"
#include "G4Step.hh"    
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
 
#include "G4Material.hh"
#include "G4NistManager.hh"

#include "G4Isotope.hh"
#include "G4Element.hh"

#include "G4UnitsTable.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Tubs.hh"
#include "G4Torus.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4UnitsTable.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"

#include <stdlib.h>
#include <time.h>
#include <fstream>

G4int SpcRaw[SpcL];




DetConstr::DetConstr():G4VUserDetectorConstruction(),
world_log(0),world_phys(0),LSctn_log(0),LSctn_phys(0),
QurCell_log(0),QurCell_phys(0),LGd1_log(0),LGd1_phys(0),
LGd2_log(0),LGd2_phys(0),Box1_log(0),Box1_phys(0),
Box2_log(0),Box2_phys(0),Box3_log(0),Box3_phys(0),
Box4_log(0),Box4_phys(0),Box5_log(0),Box5_phys(0),
Box6_log(0),Box6_phys(0),CuBox1_log(0),CuBox1_phys(0),
CuBox2_log(0),CuBox2_phys(0),CuBox3_log(0),CuBox3_phys(0),
CuBox4_log(0),CuBox4_phys(0),CuBox5_log(0),CuBox5_phys(0),
CuBox6_log(0),CuBox6_phys(0),PbBox1_log(0),PbBox1_phys(0),
PbBox2_log(0),PbBox2_phys(0),PbBox3_log(0),PbBox3_phys(0),
PbBox4_log(0),PbBox4_phys(0),PbBox5_log(0),PbBox5_phys(0),
PbBox6_log(0),PbBox6_phys(0),RadS_log(0),RadS_phys(0)

{;}
DetConstr::~DetConstr()
{
  FILE *outputFile1 = fopen("TScinPhotDet.dat", "wt");
  		
	for (G4int ii=0; ii<SpcL; ii++)
	{ 
		
		//G4int ChanValKeV = ii;
		//fprintf(outputFile1, " %6i\t", ChanValKeV );
		fprintf(outputFile1, "%i\n", SpcRaw[ii] );
		
				
	}
   fclose(outputFile1);
   
}




G4VPhysicalVolume* DetConstr::Construct()

{
		////-----defineMaterials-----------
		G4String name, symbol;             // a=mass of a mole;
		G4double A, z, density;            // z=mean number of protons;  
		G4int nel;
		
		//G4int iz, n;                       // iz=nb of protons  in an isotope; 
                                   // n=nb of nucleons in an isotope; G4int ncomponents, natoms;
		G4double abundance, fractionmass;
		G4double temperature, pressure;

        ///oooooooooooooooooooowork materials-----oooooooooo
		G4NistManager* nist = G4NistManager::Instance();
		G4Element* elH = nist->FindOrBuildElement(1);
		G4Element* elLi = nist->FindOrBuildElement(3);
	    G4Element* elB = nist->FindOrBuildElement(5);
		G4Element* elC = nist->FindOrBuildElement(6);
		G4Element* elN = nist->FindOrBuildElement(7);
		G4Element* elO = nist->FindOrBuildElement(8);
		G4Element* elSi = nist->FindOrBuildElement(14);
		G4Element* elK = nist->FindOrBuildElement(19);
		G4Element* elCa = nist->FindOrBuildElement(20);
		G4Element* elCr = nist->FindOrBuildElement(24);
		G4Element* elMn = nist->FindOrBuildElement(25);
		G4Element* elFe = nist->FindOrBuildElement(26);
		G4Element* elNi = nist->FindOrBuildElement(28);
		G4Element* elCu = nist->FindOrBuildElement(29);
		G4Element* elGe = nist->FindOrBuildElement(32);
		G4Element* elNd = nist->FindOrBuildElement(41);
		G4Element* elMo = nist->FindOrBuildElement(42);
		G4Element* elPb = nist->FindOrBuildElement(82);
		
		G4Material* Vacuum = nist->FindOrBuildMaterial("G4_Galactic");
		G4Material* OrgSteclo = nist->FindOrBuildMaterial("G4_PLEXIGLASS"); 
		G4Material* Copper = nist->FindOrBuildMaterial("G4_Cu"); 
		G4Material* Germanium = nist->FindOrBuildMaterial("G4_Ge");
		G4Material* Lead = nist->FindOrBuildMaterial("G4_Pb");
		G4Material* Air = nist->FindOrBuildMaterial("G4_AIR");
		G4Material* NaI = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
		G4Material* PolyBankaMat = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
		G4Material* Lavsan = nist->FindOrBuildMaterial("G4_MYLAR");
		
		//quartz
		G4Material* Qtz = new G4Material(name="quartz", density = 2.200*g/cm3, nel=2);
		Qtz->AddElement(elSi, 1);
		Qtz->AddElement(elO , 2);
		G4Material* SiO2   = nist->FindOrBuildMaterial("quartz");
		
		
		
		// Stainless steel (Medical Physics, Vol 25, No 10, Oct 1998)	
		G4Material* Ssteel = new G4Material(name="Stainless steel", density = 8.02*g/cm3, nel=5);
		Ssteel->AddElement(elMn, 0.02);
		Ssteel->AddElement(elSi, 0.01);
		Ssteel->AddElement(elCr, 0.19);
		Ssteel->AddElement(elNi, 0.10);
		Ssteel->AddElement(elFe, 0.68);
		// Scintillator LAB.
		G4Material* LAB = new G4Material(name="LAB", density = 0.856*g/cm3, nel=2);
		LAB->AddElement(elC, 18);
		LAB->AddElement(elH, 30);
		 
        /////VM2000         
        G4Material* VM2000 = new G4Material(name="VM2000",density=0.9*g/cm3, nel=2); 
        VM2000->AddElement(elC, 2); 
        VM2000->AddElement(elH,4);
		
		
		
		///\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
		
		///volume of world
		   
		G4double world_x = 200.0*cm;
		G4double world_y = 200.0*cm;
		G4double world_z = 200.0*cm;
		G4Box* world= new G4Box("World",world_x,world_y,world_z);
		world_log = new G4LogicalVolume(world,Air,"World",0,0,0);
		world_phys = new G4PVPlacement(0,G4ThreeVector(),world_log,"World",0,false,0);   
						
		//\/\/\/\/\/\/Quartz cell///////
		G4double innerRadiusQurCell = 0.0*mm;
		G4double outerRadiusQurCell = 50.0*mm;
		G4double hightQurCell = 100.0*mm;
		G4double startAngleQurCell = 0.*deg;
		G4double spanningAngleQurCell = 360.*deg;
		G4Tubs* QurCell = new G4Tubs("QurCell",innerRadiusQurCell,outerRadiusQurCell,hightQurCell,startAngleQurCell,spanningAngleQurCell);
				
		QurCell_log = new G4LogicalVolume(QurCell,SiO2,"QurCell",0,0,0); 
		G4double QurCell_Pos_x = 0.*mm;
		G4double QurCell_Pos_y = 0.*mm;
		G4double QurCell_Pos_z = 0.*mm;
		QurCell_phys = new G4PVPlacement(0,G4ThreeVector(QurCell_Pos_x,QurCell_Pos_y,QurCell_Pos_z),QurCell_log,"QurCell",world_log,false,0);

		///Scintillator
		G4double innerRadiusLSctn = 0.0*mm;
		G4double outerRadiusLSctn = 46.0*mm;
		G4double hightLSctn = 96.0*mm;
		G4double startAngleLSctn = 0.*deg;
		G4double spanningAngleLSctn = 360.*deg;
		G4Tubs* LSctn = new G4Tubs("LSctn",innerRadiusLSctn,outerRadiusLSctn,hightLSctn,startAngleLSctn,spanningAngleLSctn);
		
		LSctn_log = new G4LogicalVolume(LSctn,LAB,"LSctn",0,0,0);		
		G4double LSctn_Pos_x = 0.*mm;
		G4double LSctn_Pos_y = 0.*mm;
		G4double LSctn_Pos_z = 0.*mm;
		LSctn_phys = new G4PVPlacement(0,G4ThreeVector(LSctn_Pos_x,LSctn_Pos_y,LSctn_Pos_z),LSctn_log,"LSctn",QurCell_log,false,0);
		
		
		//\/\/\/************LightGuides*********\/\/\/\/
		
		G4double innerRadiusLGd1 = 0.0*mm;
		G4double outerRadiusLGd1 = 43.0*mm;
		G4double hightLGd1 = 25.0*mm;
		G4double startAngleLGd1 = 0.*deg;
		G4double spanningAngleLGd1 = 360.*deg;
		G4Tubs* LGd1 = new G4Tubs("LGd1",innerRadiusLGd1,outerRadiusLGd1,hightLGd1,startAngleLGd1,spanningAngleLGd1);
		
		LGd1_log = new G4LogicalVolume(LGd1,OrgSteclo,"LGd1",0,0,0);		
		G4double LGd1_Pos_x = 0.*mm;
		G4double LGd1_Pos_y = 0.*mm;
		G4double LGd1_Pos_z = 125.1*mm;
		LGd1_phys = new G4PVPlacement(0,G4ThreeVector(LGd1_Pos_x,LGd1_Pos_y,LGd1_Pos_z),LGd1_log,"LGd1",world_log,false,0);
		//////
		G4double innerRadiusLGd2 = 0.0*mm;
		G4double outerRadiusLGd2 = 43.0*mm;
		G4double hightLGd2 = 25.0*mm;
		G4double startAngleLGd2 = 0.*deg;
		G4double spanningAngleLGd2 = 360.*deg;
		G4Tubs* LGd2 = new G4Tubs("LGd2",innerRadiusLGd2,outerRadiusLGd2,hightLGd2,startAngleLGd2,spanningAngleLGd2);
		
		LGd2_log = new G4LogicalVolume(LGd2,OrgSteclo,"LGd2",0,0,0);		
		G4double LGd2_Pos_x = 0.*mm;
		G4double LGd2_Pos_y = 0.*mm;
		G4double LGd2_Pos_z = -125.1*mm;
		LGd2_phys = new G4PVPlacement(0,G4ThreeVector(LGd2_Pos_x,LGd2_Pos_y,LGd2_Pos_z),LGd2_log,"LGd2",world_log,false,0);
		
		
		////////RadSourceBody/////////////////
		G4double innerRadiusRadS = 0.0*mm;
		G4double outerRadiusRadS = 15.0*mm;
		G4double hightRadS = 0.1*mm;
		G4double startAngleRadS = 0.*deg;
		G4double spanningAngleRadS = 360.*deg;
		G4Tubs* RadS = new G4Tubs("RadS",innerRadiusRadS,outerRadiusRadS,hightRadS,startAngleRadS,spanningAngleRadS);
		
		RadS_log = new G4LogicalVolume(RadS,Lavsan,"RadS",0,0,0);		
		G4double RadS_Pos_x = 86.*mm;
		G4double RadS_Pos_y = 30.5*mm;
		G4double RadS_Pos_z = 0.*mm;
		RadS_phys = new G4PVPlacement(0,G4ThreeVector(RadS_Pos_x,RadS_Pos_y,RadS_Pos_z),RadS_log,"RadS",world_log,false,0);
		
		///************///////////////
		//\/\/\/\/\/ Sensitive detectors\/\/\/\/\/\/\/\/\/\/
		  		  
		G4SDManager* sdman=G4SDManager::GetSDMpointer();
		G4String Det_SDname = "Liquid scintillator";		  
		SensitiveDetector* Det_SD = new SensitiveDetector(Det_SDname);
		sdman->AddNewDetector (Det_SD);
		LSctn_log->SetSensitiveDetector(Det_SD);
		  
		  
		  
	  
    return world_phys; 
}