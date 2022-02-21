#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"
#include "Generator.hh"
#include "Event.hh"
#include "RunAction.hh"
#include "Stepping.hh"
#include "Construction.hh"

class MyActionInitialization : public G4VUserActionInitialization
{
public:
    MyActionInitialization();
    ~MyActionInitialization();

    virtual void Build() const;

private:
    MyDetectorConstruction *fDetConstruction;
};

#endif