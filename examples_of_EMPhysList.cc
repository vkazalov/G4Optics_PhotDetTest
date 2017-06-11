
Geant4 Home 	Download | User Forum | Gallery
Contact Us
Home > Examples

    Main Page
    Related Pages
    Classes
    Files

    File List
    File Members

    extended
    medical
    GammaTherapy
    src

PhysicsList.cc
Go to the documentation of this file.
    1 //
    2 // ********************************************************************
    3 // * License and Disclaimer                                           *
    4 // *                                                                  *
    5 // * The  Geant4 software  is  copyright of the Copyright Holders  of *
    6 // * the Geant4 Collaboration.  It is provided  under  the terms  and *
    7 // * conditions of the Geant4 Software License,  included in the file *
    8 // * LICENSE and available at  http://cern.ch/geant4/license .  These *
    9 // * include a list of copyright holders.                             *
   10 // *                                                                  *
   11 // * Neither the authors of this software system, nor their employing *
   12 // * institutes,nor the agencies providing financial support for this *
   13 // * work  make  any representation or  warranty, express or implied, *
   14 // * regarding  this  software system or assume any liability for its *
   15 // * use.  Please see the license in the file  LICENSE  and URL above *
   16 // * for the full disclaimer and the limitation of liability.         *
   17 // *                                                                  *
   18 // * This  code  implementation is the result of  the  scientific and *
   19 // * technical work of the GEANT4 collaboration.                      *
   20 // * By using,  copying,  modifying or  distributing the software (or *
   21 // * any work based  on the software)  you  agree  to acknowledge its *
   22 // * use  in  resulting  scientific  publications,  and indicate your *
   23 // * acceptance of all terms of the Geant4 Software license.          *
   24 // ********************************************************************
   25 //
   26 /// \file medical/GammaTherapy/src/PhysicsList.cc
   27 /// \brief Implementation of the PhysicsList class
   28 //
   29 // $Id: PhysicsList.cc 101245 2016-11-10 08:45:38Z gcosmo $
   30 //
   31 //---------------------------------------------------------------------------
   32 //
   33 // ClassName:   PhysicsList
   34 //
   35 // Author:      V.Ivanchenko 03.05.2004
   36 //
   37 // Modified:
   38 // 16.11.06 Use components from physics_lists subdirectory (V.Ivanchenko)
   39 // 16.05.07 Use renamed EM components from physics_lists (V.Ivanchenko)
   40 //
   41 //----------------------------------------------------------------------------
   42 //
   43 
   44 //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
   45 //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
   46 
   47 #include "PhysicsList.hh"
   48 #include "PhysicsListMessenger.hh"
   49 
   50 #include "G4EmStandardPhysics.hh"
   51 #include "G4EmStandardPhysics_option1.hh"
   52 #include "G4EmStandardPhysics_option2.hh"
   53 #include "G4EmStandardPhysics_option3.hh"
   54 #include "G4EmStandardPhysics_option4.hh"
   55 #include "G4EmLivermorePhysics.hh"
   56 #include "G4EmPenelopePhysics.hh"
   57 #include "G4EmLowEPPhysics.hh"
   58 #include "StepLimiterBuilder.hh"
   59 #include "G4DecayPhysics.hh"
   60 #include "G4HadronElasticPhysics.hh"
   61 #include "G4HadronInelasticQBBC.hh"
   62 #include "G4IonBinaryCascadePhysics.hh"
   63 #include "G4EmExtraPhysics.hh"
   64 #include "G4StoppingPhysics.hh"
   65 
   66 #include "G4UnitsTable.hh"
   67 #include "G4LossTableManager.hh"
   68 #include "G4EmParameters.hh"
   69 
   70 #include "G4PhysicalConstants.hh"
   71 #include "G4SystemOfUnits.hh"
   72 
   73 //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
   74 
   75 PhysicsList::PhysicsList(): G4VModularPhysicsList()
   76 {
   77   fHelIsRegisted = false;
   78   fBicIsRegisted = false;
   79   fIonIsRegisted = false;
   80   fGnucIsRegisted = false;
   81   fStopIsRegisted = false;
   82   fVerbose = 1;
   83 
   84   SetDefaultCutValue(1*mm);
   85 
   86   fMessenger = new PhysicsListMessenger(this);
   87 
   88   // Add Physics builders
   89   RegisterPhysics(new G4EmStandardPhysics());
   90   RegisterPhysics(new G4DecayPhysics());
   91   RegisterPhysics(new StepLimiterBuilder());
   92 }
   93 
   94 //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
   95 
   96 PhysicsList::~PhysicsList()
   97 {
   98   delete fMessenger;
   99 }
  100 
  101 //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  102 
  103 void PhysicsList::ConstructParticle()
  104 {
  105   if(fVerbose > 0) {
  106     G4cout << "### PhysicsList Construte Particles" << G4endl;
  107   }
  108   G4VModularPhysicsList::ConstructParticle();
  109 }
  110 
  111 //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  112 
  113 void PhysicsList::ConstructProcess()
  114 {
  115   if(fVerbose > 0) {
  116     G4cout << "### PhysicsList Construte Processes" << G4endl;
  117   }
  118 
  119   G4VModularPhysicsList::ConstructProcess();
  120 
  121   // Define energy interval for loss processes
  122   // from 10 eV to 10 GeV
  123   G4EmParameters* param = G4EmParameters::Instance();
  124   param->SetMinEnergy(0.01*keV);
  125   param->SetMaxEnergy(10.*GeV);
  126   param->SetNumberOfBinsPerDecade(10);
  127   param->SetVerbose(1);
  128 }
  129 
  130 //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  131 
  132 void PhysicsList::AddPhysicsList(const G4String& name)
  133 {
  134   if(fVerbose > 0) {
  135     G4cout << "### PhysicsList Add Physics <" << name 
  136            << "> " << G4endl;
  137   }
  138   if (name == "emstandard") {
  139     ReplacePhysics(new G4EmStandardPhysics());
  140 
  141   } else if (name == "emstandard_opt1") {
  142     ReplacePhysics(new G4EmStandardPhysics_option1());
  143 
  144   } else if (name == "emstandard_opt2") {
  145     ReplacePhysics(new G4EmStandardPhysics_option2());
  146 
  147   } else if (name == "emstandard_opt3") {
  148     ReplacePhysics(new G4EmStandardPhysics_option3());
  149 
  150   } else if (name == "emstandard_opt4") {
  151     ReplacePhysics(new G4EmStandardPhysics_option4());
  152 
  153   } else if (name == "emlivermore") {
  154     ReplacePhysics(new G4EmLivermorePhysics());
  155 
  156   } else if (name == "empenelope") {
  157     ReplacePhysics(new G4EmPenelopePhysics());
  158 
  159   } else if (name == "emlowenergy") {
  160     ReplacePhysics(new G4EmLowEPPhysics());
  161 
  162   } else if (name == "elastic" && !fHelIsRegisted) {
  163     RegisterPhysics(new G4HadronElasticPhysics());
  164     fHelIsRegisted = true;
  165     
  166   } else if (name == "binary" && !fBicIsRegisted) {
  167     RegisterPhysics(new G4HadronInelasticQBBC());
  168     fBicIsRegisted = true;
  169     
  170   } else if (name == "binary_ion" && !fIonIsRegisted) {
  171     RegisterPhysics(new G4IonBinaryCascadePhysics());
  172     fIonIsRegisted = true;
  173 
  174   } else if (name == "gamma_nuc" && !fGnucIsRegisted) {
  175     RegisterPhysics(new G4EmExtraPhysics());
  176     fGnucIsRegisted = true;
  177 
  178   } else if (name == "stopping" && !fStopIsRegisted) {
  179     RegisterPhysics(new G4StoppingPhysics());
  180     fStopIsRegisted = true;
  181     
  182   } else {
  183     G4cout << "PhysicsList::AddPhysicsList <" << name << ">" 
  184            << " fail - module is already regitered or is unknown " << G4endl;
  185   }
  186 }
  187 
  188 //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
Generated on Wed Dec 14 2016 12:13:15 for Geant4 example GammaTherapy by   doxygen 1.8.11
