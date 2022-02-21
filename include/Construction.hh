#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Tubs.hh"

class G4VPhysicalVolume;

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  MyDetectorConstruction();
  ~MyDetectorConstruction();

  virtual G4VPhysicalVolume *Construct();
  void ConstructScintillator();

  G4VPhysicalVolume *GetBoxVol() const { return physBox; }

  G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; }

protected:
  G4LogicalVolume *fScoringVolume;

private:
  void DefineMaterials();
  // virtual void ConstructSDandField();

  G4Box *solidWorld, *solidBox;
  G4LogicalVolume *logicWorld, *logicBox;
  G4VPhysicalVolume *physWorld, *physBox;
  G4bool isScintillator;
};

// inline const G4VPhysicalVolume *MyDetectorConstruction::GetBoxVol() const
// {
//   return physBox;
// }

#endif