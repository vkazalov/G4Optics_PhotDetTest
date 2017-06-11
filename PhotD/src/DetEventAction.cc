//#include "SensitiveDetector.hh"
#include "DetEventAction.hh"
#include "DetHit.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4VVisManager.hh"
#include "G4SDManager.hh"
#include "G4UImanager.hh"
#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4Step.hh"

DetEventAction::DetEventAction()
{ 
  
}
DetEventAction::~DetEventAction()
{
	
}

void DetEventAction::BeginOfEventAction(const G4Event* anEvent)
{
  
  G4SDManager* SDman = G4SDManager::GetSDMpointer();
  if(fCollID<0) 
  fCollID=SDman->GetCollectionID("DetCol");
  //G4cout << fCollID << G4endl;     
}

void DetEventAction::EndOfEventAction(const G4Event* anEvent)
{
  DetHitsCollection* HC = NULL;
  G4HCofThisEvent* HCE = anEvent->GetHCofThisEvent();
 
  if(HCE)
  {
	if(fCollID>=0) HC = (DetHitsCollection*)(HCE->GetHC(fCollID));
  //G4cout << HC << G4endl;
  }
  totEnergy = 0;
  if(HC)
  {
	Det_hits = HC->entries();
  //G4cout << Det_hits << G4endl;
	for (G4int j=0; j<Det_hits; j++) 
	{
      hitEnergy = (*HC)[j]->GetEdep();
	  //G4cout << hitEnergy << G4endl;
	  totEnergy += hitEnergy/keV;  
	  //G4cout << totEnergy << G4endl;
    } 
   } 
  //G4cout << totEnergy << G4endl;
  if (totEnergy > 0 && totEnergy<SpcL)
	{  
		G4int EnergRaw = int(totEnergy);
		//G4cout << EnergRaw << G4endl;   		
		SpcRaw[EnergRaw]++;			
	}
}	

