#include "Action.hh"

MyActionInitialization::MyActionInitialization()
{
}

MyActionInitialization::~MyActionInitialization()
{
}

void MyActionInitialization::Build() const
{
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);

    MyRunAction *runaction = new MyRunAction;
    SetUserAction(runaction);

    MyEventAction *event = new MyEventAction(runaction);
    SetUserAction(event);

    MySteppingAction *stepping = new MySteppingAction(fDetConstruction, event);
    SetUserAction(stepping);
}