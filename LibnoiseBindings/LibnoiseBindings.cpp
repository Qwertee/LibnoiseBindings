// LibnoiseBindings.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include <noise/noise.h>

// Example fuction definition which is able to be called from CFFI.
// Note how it is declared on the top level and is not within a class or namespace.
// You can call functions and use types that are within other classes and namespaces from within
// this function, but this function itself must be kept simple.
extern "C" double __declspec(dllexport) example() {
	// namespaced C++ class
	noise::module::Perlin module;
	double value = module.GetValue(1.25, 0.75, 0.5);
	return value;
}

// Ideally you can write simple bindings (like above) for the other features you want from the library you are trying to interface with