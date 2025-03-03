#include "run.hh"
#include <sstream>

MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
G4AnalysisManager *man = G4AnalysisManager::Instance();

man->OpenFile("100kev_E.root");
man->CreateNtuple("E_Dep","E_Dep");
man->CreateNtupleDColumn("Dep_E_100keV_5cm_lyso");
man->FinishNtuple(0);

}

void MyRunAction::EndOfRunAction(const G4Run*)
{
G4AnalysisManager *man = G4AnalysisManager::Instance();

man->Write();

man->CloseFile();

}

