// G4Step represents a step in the particle propagation
// G4Step is updated each time a process is invoked
// after a step is completed it is possible to extract information from a step (in ProcessHits() or in UserSteppingAction())
#include "Stepping.hh"
#include <iostream>
using namespace std;

MySteppingAction::MySteppingAction(const MyDetectorConstruction *detectorConstruction, MyEventAction *eventAction) : G4UserSteppingAction(),
                                                                                                                     fDetConstruction(detectorConstruction),
                                                                                                                     fEventAction(eventAction)
{
}

MySteppingAction::~MySteppingAction()
{
}

void MySteppingAction::UserSteppingAction(const G4Step *astep)
{

  G4StepPoint *point1 = astep->GetPreStepPoint(); // Get presteppoint pointer

  G4TouchableHandle touch1 = point1->GetTouchableHandle(); // Geometrical information is available from preStepPoint and G4TouchableHandle keeps these information

  // some geometrical information from step
  // G4VPhysicalVolume *volume = touch1->GetVolume();       // get the current volume
  auto volume = astep->GetPreStepPoint()->GetTouchableHandle()->GetVolume();

  G4String volname = volume->GetName();                  // get its name
  G4int copyNumber = touch1->GetCopyNumber();            // get copy number
  G4LogicalVolume *lVolume = volume->GetLogicalVolume(); // get pointer to logical volume
  G4Material *material = point1->GetMaterial();          // get pointer material

  // some Physics quantities that are available from step
  G4double steplength = astep->GetStepLength(); // get step length
  G4double eDeposit = astep->GetTotalEnergyDeposit();
  G4ThreeVector displace = astep->GetDeltaPosition();
  G4double tof = astep->GetDeltaTime();

  // To get some physics quantities of the track after the completion of the current step
  G4Track *track = astep->GetTrack();
  G4double kinEnergy = track->GetKineticEnergy();
  G4double globalTime = track->GetGlobalTime();
  G4ThreeVector momentum = track->GetMomentum();

  // get the current volume
  const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction *>(G4RunManager::GetRunManager()->GetUserDetectorConstruction());

  G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume(); // the scoring volume

  // cout << "one: " << lVolume << endl;
  // cout << "two: " << fScoringVolume << endl;

  if (lVolume == fScoringVolume) // compare two logical volume to get the dose exactly in the scoring volume
  {
    fEventAction->AddEdep(eDeposit); // handover edep to the event action (energy deposited by all particles ins detectors)
  }

  // G4VPhysicalVolume *physcheck = fDetConstruction->GetBoxVol();
  // // cout << "one: " << physcheck << endl;
  // cout << "two: " << volume << endl;
}
