#include "detector.hh"
#include "event.hh"
MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}
MySensitiveDetector::~MySensitiveDetector()
{}
G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
	G4Track *track = aStep->GetTrack();
	
	//track->SetTrackStatus(fStopAndKill);
	
	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();
	
	
	
	const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
	G4int copyNo = touchable->GetCopyNumber();
	
	// Get the process type
        const G4VProcess* process = postStepPoint->GetProcessDefinedStep();
        
        G4String particleName = track->GetDefinition()->GetParticleName();
        G4double energyDeposit = aStep->GetTotalEnergyDeposit();
	if(energyDeposit!=0){
	 if (process) {
        G4String processName = process->GetProcessName();
        G4ProcessType processType = process->GetProcessType();
        G4int processSubType = process->GetProcessSubType();
        
    }
    }
    
	G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	G4double edep = aStep->GetTotalEnergyDeposit();
  
    
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	return true;
}
