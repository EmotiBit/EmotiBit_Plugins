#ifndef EXPORT_TO_DLL_H
#define EXPORT_TO_DLL_H

#ifdef BUILDING_ROUNDER_DLL
    #define ROUND_EXPORT __declspec(dllexport)
#elif defined(USING_ROUNDER_DLL)
    #define ROUND_EXPORT __declspec(dllimport)
#else
    #define ROUND_EXPORT
#endif

#endif
