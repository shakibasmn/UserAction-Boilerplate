
#include "Event.hh"
class MyRunAction;

MyEventAction::MyEventAction(MyRunAction *runAction)
{
  fEdep = 0.; // at start of  events it should be zero
  fRunAction = runAction;
}

MyEventAction::~MyEventAction()
{
}

void MyEventAction::BeginOfEventAction(const G4Event *)
{
  fEdep = 0.; // every time that an event starts energy value should be set to zero (we want each value seperately)
}

void MyEventAction::EndOfEventAction(const G4Event *)
{
  G4cout << "Energy deposition: " << fEdep << G4endl; // energy deposition at the end of the event

  fRunAction->AddEdep(fEdep);
}
