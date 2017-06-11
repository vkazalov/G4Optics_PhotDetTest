#ifndef DetConstr_h
#define DetConstr_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4Box;
class G4Tubs;
class G4Cons;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
//class DetectorMessenger;

class DetConstr : public G4VUserDetectorConstruction
{
	public:
  
    DetConstr();
    ~DetConstr();
    G4VPhysicalVolume* Construct();
	//G4VPhysicalVolume* DefineVolumes();
	//DefineMaterials();
	
	private:
    //void DefineMaterials();
    G4Box* world;
	G4Tubs* Tub11;
	G4Tubs* Tub12;
	G4Tubs* Tub13;
	G4Tubs* Tub14;
	G4Tubs* Tub15;
	//G4Torus
	//G4Tubs* stenkaSsteel;
	//G4Tubs* stenkaQuartz;
	//G4Tubs* NaIcrystall;
	//G4Cons* banka;
	//G4Cons* chrompik;
	
	
		
    G4LogicalVolume* world_log;
	G4LogicalVolume* LSctn_log;
	G4LogicalVolume* QurCell_log;
	G4LogicalVolume* LGd1_log;
	G4LogicalVolume* LGd2_log;
	G4LogicalVolume* Box1_log;
	G4LogicalVolume* Box2_log;
	G4LogicalVolume* Box3_log;
	G4LogicalVolume* Box4_log;
	G4LogicalVolume* Box5_log;
	G4LogicalVolume* Box6_log;
	G4LogicalVolume* CuBox1_log;
	G4LogicalVolume* CuBox2_log;
	G4LogicalVolume* CuBox3_log;
	G4LogicalVolume* CuBox4_log;
	G4LogicalVolume* CuBox5_log;
	G4LogicalVolume* CuBox6_log;
	G4LogicalVolume* PbBox1_log;
	G4LogicalVolume* PbBox2_log;
	G4LogicalVolume* PbBox3_log;
	G4LogicalVolume* PbBox4_log;
	G4LogicalVolume* PbBox5_log;
	G4LogicalVolume* PbBox6_log;
	G4LogicalVolume* RadS_log;
	
	// Physical volumes
    //
    G4VPhysicalVolume* world_phys;
	G4VPhysicalVolume* LSctn_phys;
	G4VPhysicalVolume* QurCell_phys;
	G4VPhysicalVolume* LGd1_phys;
	G4VPhysicalVolume* LGd2_phys;
	G4VPhysicalVolume* Box1_phys;
	G4VPhysicalVolume* Box2_phys;
	G4VPhysicalVolume* Box3_phys;
	G4VPhysicalVolume* Box4_phys;
	G4VPhysicalVolume* Box5_phys;
	G4VPhysicalVolume* Box6_phys;
	G4VPhysicalVolume* CuBox1_phys;
	G4VPhysicalVolume* CuBox2_phys;
	G4VPhysicalVolume* CuBox3_phys;
	G4VPhysicalVolume* CuBox4_phys;
	G4VPhysicalVolume* CuBox5_phys;
	G4VPhysicalVolume* CuBox6_phys;
	G4VPhysicalVolume* PbBox1_phys;
	G4VPhysicalVolume* PbBox2_phys;
	G4VPhysicalVolume* PbBox3_phys;
	G4VPhysicalVolume* PbBox4_phys;
	G4VPhysicalVolume* PbBox5_phys;
	G4VPhysicalVolume* PbBox6_phys;
	G4VPhysicalVolume* RadS_phys;
	
	//G4VPhysicalVolume* DefineVolumes();
	/*G4Material* SiO2;
	G4Material* Vacuum;
	G4Material* LAB;
	G4Material* Air;
	G4Material* OrgSteclo;
	G4Material* VM2000;
	G4Material* Copper;
	G4Material* Ssteel;
	G4Material* NaI;
	G4Material* PolyBankaMat;
	G4Material* PotDich;
	G4Material* Lead;*/
    ////---------------
	//G4VisAttributes* worldVisAtt;
	//G4VisAttributes* quartzVisAtt;
	//G4VisAttributes* quartzWALLVisAtt;
	//G4VisAttributes* LABVisAtt;
	
	
   
};
#endif