#ifndef EXPORT_TO_DLL_H
#define EXPORT_TO_DLL_H

#ifdef BUILDING_ROUNDER_DLL
// Used when building the DLL itself. It is what is used for our purposes specifically.
    #define EXPORT_TO_DLL __declspec(dllexport)
#elif defined(USING_ROUNDER_DLL)
// This is used when the DLL needs to be in a different module.
    #define EXPORT_TO_DLL __declspec(dllimport)
#else
    #define EXPORT_TO_DLL
#endif

#endif
