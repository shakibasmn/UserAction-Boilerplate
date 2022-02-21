#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "G4Accumulable.hh"
#include "Construction.hh"
#include "G4RunManager.hh"
#include "G4AccumulableManager.hh"
#include "G4ParticleGun.hh"
#include "Generator.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

class MyRunAction : public G4UserRunAction
{

public:
  MyRunAction();
  ~MyRunAction();

private:
  G4double fEdep;

public:
  void AddEdep(G4double edep) { fEdep += edep; }

  virtual void BeginOfRunAction(const G4Run *);
  virtual void EndOfRunAction(const G4Run *);
};

#endif