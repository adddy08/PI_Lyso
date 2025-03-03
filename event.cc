#include "event.hh"
#include "G4SystemOfUnits.hh"
#include <chrono>
#include "Randomize.hh"

MyEventAction::MyEventAction(MyRunAction*)
{
	fEdep = 0.;	
}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
	// Set a new random seed based on the current system time
  	long seeds[2];
  	auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
  	seeds[0] = std::chrono::duration_cast<std::chrono::seconds>(now).count();
  	seeds[1] = std::chrono::duration_cast<std::chrono::nanoseconds>(now).count();
  	CLHEP::HepRandom::setTheSeeds(seeds);

	fEdep = 0.;	
}

void MyEventAction::EndOfEventAction(const G4Event*)
{
G4AnalysisManager *man = G4AnalysisManager::Instance();
man->FillNtupleDColumn(0, 0, fEdep);
man->AddNtupleRow(0);
}


void MyEventAction::AddEdep(G4double edep) 
{ fEdep += edep;// Store energy deposition in corresponding array element
}

