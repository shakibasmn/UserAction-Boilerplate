#include "Construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{
  DefineMaterials();
}

MyDetectorConstruction::~MyDetectorConstruction()
{
}

void MyDetectorConstruction::DefineMaterials()
{
}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
  G4NistManager *nist = G4NistManager::Instance();

  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
  G4Material *boxMat = nist->FindOrBuildMaterial("G4_WATER");

  solidWorld = new G4Box("solidWorld", 0.5 * m, 0.5 * m, 0.5 * m);

  logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

  physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

  solidBox = new G4Box("abox", 10. * cm, 10. * cm, 10. * cm);
  logicBox = new G4LogicalVolume(solidBox, boxMat, "logicbox");
  physBox = new G4PVPlacement(0, G4ThreeVector(0., 0., 20. * cm), logicBox, "physbox", logicWorld, false, 0);

  fScoringVolume = logicBox;

  return physWorld;
}

