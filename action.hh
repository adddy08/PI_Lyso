#ifndef ACTION_HH
#define ACTION_HH

#include "generator.hh"

#include "G4VUserActionInitialization.hh"

#include "run.hh"

#include "event.hh"

#include "stepping.hh"

class MyActionInitialization : public G4VUserActionInitialization

{
public:

MyActionInitialization();
~MyActionInitialization();

virtual void Build() const;

};

#endif
