
#ifndef DetEventAction_h
#define DetEventAction_h 1

#define SpcL 8192


#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
extern G4int SpcRaw[SpcL];
// G4int SpcBlur[SpcL];


class G4Event;


class DetEventAction : public G4UserEventAction
{
  public:
    DetEventAction();
    virtual ~DetEventAction();

  public:
    virtual void   BeginOfEventAction(const G4Event*);
    virtual void   EndOfEventAction(const G4Event*);

	private:
	G4int fCollID;                
    G4int Det_hits;
    G4double totEnergy;
	G4double hitEnergy;
       	
    	
	
};
 
#endif