#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "RunAction.hh"
class MyRunAction;


class MyEventAction : public G4UserEventAction
{
public:
  MyEventAction(MyRunAction *runAction);
  ~MyEventAction();

  virtual void BeginOfEventAction(const G4Event *);
  virtual void EndOfEventAction(const G4Event *);

  // we transfer energy from steppinsg class to this function so this is public
  // adds edep to the fedep
  void AddEdep(G4double edep) { fEdep += edep; }

private:
  MyRunAction *fRunAction;
  G4double fEdep; // value to accumulate deposited energy
};

#endif