#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"

#include "G4AnalysisManager.hh"
//#include "g4root.hh"



class MyRunAction : public G4UserRunAction
{
public:
MyRunAction();
~MyRunAction();


virtual void BeginOfRunAction(const G4Run*);
virtual void EndOfRunAction(const G4Run*);

private:
    G4int fHistId2D;  // ID for the 2D histogram
};

#endif
