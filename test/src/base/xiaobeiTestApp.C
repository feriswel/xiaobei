//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "xiaobeiTestApp.h"
#include "xiaobeiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<xiaobeiTestApp>()
{
  InputParameters params = validParams<xiaobeiApp>();
  return params;
}

xiaobeiTestApp::xiaobeiTestApp(InputParameters parameters) : MooseApp(parameters)
{
  xiaobeiTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

xiaobeiTestApp::~xiaobeiTestApp() {}

void
xiaobeiTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  xiaobeiApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"xiaobeiTestApp"});
    Registry::registerActionsTo(af, {"xiaobeiTestApp"});
  }
}

void
xiaobeiTestApp::registerApps()
{
  registerApp(xiaobeiApp);
  registerApp(xiaobeiTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
xiaobeiTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  xiaobeiTestApp::registerAll(f, af, s);
}
extern "C" void
xiaobeiTestApp__registerApps()
{
  xiaobeiTestApp::registerApps();
}
