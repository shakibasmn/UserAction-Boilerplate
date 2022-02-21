#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "Event.hh"
#include "Construction.hh"
#include "G4Track.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

class MySteppingAction : public G4UserSteppingAction
{
    public:

    MySteppingAction(const MyDetectorConstruction* , MyEventAction *);

    ~MySteppingAction();

    virtual void UserSteppingAction(const G4Step *);

private:
    const MyDetectorConstruction* fDetConstruction;

    MyEventAction *fEventAction; // we have to add energy deposition to this variable (we want the enegy deposition in an event)
};

#endif
