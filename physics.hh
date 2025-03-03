#ifndef PHYSICS_HH
#define PHYSICS_HH


#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4VModularPhysicsList.hh"
#include "G4DecayPhysics.hh"
#include "G4HadronPhysicsFTFP_BERT.hh"
#include "G4IonPhysics.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"
//#include "FTFP_BERT_EMN.hh"
//#include "FTFP_BERT_EMV.hh"
//#include "QGSP_BIC_EMY.hh"

class MyPhysicsList : public G4VModularPhysicsList
{
public:
MyPhysicsList();
~MyPhysicsList();
};

#endif
