#include "xiaobeiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<xiaobeiApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

xiaobeiApp::xiaobeiApp(InputParameters parameters) : MooseApp(parameters)
{
  xiaobeiApp::registerAll(_factory, _action_factory, _syntax);
}

xiaobeiApp::~xiaobeiApp() {}

void
xiaobeiApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"xiaobeiApp"});
  Registry::registerActionsTo(af, {"xiaobeiApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
xiaobeiApp::registerApps()
{
  registerApp(xiaobeiApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
xiaobeiApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  xiaobeiApp::registerAll(f, af, s);
}
extern "C" void
xiaobeiApp__registerApps()
{
  xiaobeiApp::registerApps();
}
