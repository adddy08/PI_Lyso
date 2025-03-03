#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
  G4NistManager *nist = G4NistManager::Instance();

  G4Material *worldMat = nist->FindOrBuildMaterial("G4_Galactic");

  // Define LYSO material
  G4Element* elLu = nist->FindOrBuildElement("Lu"); // Lutetium
  G4Element* elY = nist->FindOrBuildElement("Y");   // Yttrium
  G4Element* elSi = nist->FindOrBuildElement("Si"); // Silicon
  G4Element* elO = nist->FindOrBuildElement("O");   // Oxygen

  G4Material* LYSO = new G4Material("LYSO", 7.1 * g/cm3, 4); // Density: ~7.1 g/cm3
  LYSO->AddElement(elLu, 71 * perCent); // 71% Lutetium
  LYSO->AddElement(elY, 4 * perCent);  // 4% Yttrium
  LYSO->AddElement(elSi, 6 * perCent); // 6% Silicon
  LYSO->AddElement(elO, 19 * perCent); // 19% Oxygen

  G4Box *solidWorld = new G4Box("solidWorld",
                                20.0*m,
                                20.0*m,
                                20.0*m);

  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld,
                                                    worldMat, 
                                                    "logicWorld");

  G4VPhysicalVolume *physWorld = new G4PVPlacement(0,
                                                   G4ThreeVector(0.,0.,0.),
                                                   logicWorld, 
                                                   "physWorld",
                                                   0, 
                                                   false, 
                                                   0, 
                                                   true);
  
  // Defining Logic volume for LYSO detector
  G4Box *solidDetector = new G4Box("solidDetector", 
                                    100.0/2*cm, // 5 mm along x (half-length)
                                    100.0/2*cm, // 5 mm along y (half-length)
                                    5.0/2*cm);  // 5 mm along z (half-length)

  logicDetector = new G4LogicalVolume(solidDetector,
                                      LYSO, 
                                      "logicDetector");

  G4VPhysicalVolume *physDetector = new G4PVPlacement(0,
                                                       G4ThreeVector(0,0,0),
                                                       logicDetector,
                                                       "physDetector",
                                                       logicWorld,
                                                       false,
                                                       0,
                                                       true);

  // Set production cuts in energy
  G4ProductionCuts *cuts = new G4ProductionCuts();
  cuts->SetProductionCut(10 * eV, "gamma");    // 10 eV for photons
  cuts->SetProductionCut(10 * eV, "e-");      // 10 eV for electrons
  cuts->SetProductionCut(10 * eV, "e+");      // 10 eV for positrons
  cuts->SetProductionCut(10 * eV, "proton");  // 10 eV for protons (if needed)

  // Apply the cuts to the world volume
  G4Region *region = G4RegionStore::GetInstance()->GetRegion("World");
  if (region)
  {
      region->SetProductionCuts(cuts);
  }

  return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
  MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
  G4SDManager::GetSDMpointer()->AddNewDetector(sensDet);
  logicDetector->SetSensitiveDetector(sensDet);
}

