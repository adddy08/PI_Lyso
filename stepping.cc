#include "stepping.hh"

MySteppingAction::MySteppingAction(MyEventAction *eventAction)
{

fEventAction = eventAction;
}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step *step)
{
G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction*>(G4RunManager::GetRunManager()->GetUserDetectorConstruction());

    G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
    G4double edep = step->GetTotalEnergyDeposit();
 // Get the copy number of the volume
    G4int copyNo = step->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber();
fEventAction->AddEdep(edep);
}
