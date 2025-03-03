#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "G4AnalysisManager.hh"
//#include "g4root.hh"

#include "run.hh"

class MyEventAction : public G4UserEventAction
{
public:
MyEventAction(MyRunAction*);
~MyEventAction();

virtual void BeginOfEventAction(const G4Event*);
virtual void EndOfEventAction(const G4Event*);

void AddEdep(G4double edep);
 void AddEdep0(G4int copyNo, G4double edep);
 
 
    //G4int fHistId2D; ;//GetHistId2D() const { return }
private:
G4double fEdep;
};

#endif
