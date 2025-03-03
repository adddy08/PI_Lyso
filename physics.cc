#include "physics.hh"

MyPhysicsList::MyPhysicsList()
{

    //decay physics
    //RegisterPhysics(new G4DecayPhysics());

    //hadronic physics
    //RegisterPhysics(new G4HadronPhysicsFTFP_BERT());

    //ion physics
    //RegisterPhysics(new G4IonPhysics());

    // Use G4EmStandardPhysics_option4
     RegisterPhysics(new G4EmStandardPhysics_option4());
    G4cout << "Using Physics List: G4EmStandardPhysics_option4" << G4endl;
    //RegisterPhysics(new FTFP_BERT_EMV());
    //RegisterPhysics(new QGSP_BIC_EMY());
    //RegisterPhysics(new G4OpticalPhysics());
}

MyPhysicsList::~MyPhysicsList()
{}
