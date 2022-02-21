#include "RunAction.hh"

MyRunAction ::MyRunAction()  
{
  fEdep=0;
}

MyRunAction::~MyRunAction()
{
}

void MyRunAction::BeginOfRunAction(const G4Run *)
{
}

void MyRunAction::EndOfRunAction(const G4Run *run)
{
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0)
    return;

  // G4double edep = fEdep;

  const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction *>(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
  G4double mass = detectorConstruction->GetScoringVolume()->GetMass();
  G4double dose = fEdep / mass;

  // Print
  //

  G4cout << "End of  Run" << G4endl;
  G4cout << " The run consists of " << nofEvents << " events" << G4endl;
  G4cout << " Total dose in the scoring volume:  " << G4BestUnit(dose, "Dose") << G4endl;
  G4cout << "Total Edep in the scoring volume: " << G4BestUnit(fEdep, "Energy") << G4endl;

}


