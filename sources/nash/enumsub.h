//
// FILE: enumsub.h -- Solve efg by enumeration in nfg
//
// $Id$
//

#ifndef ENUMSUB_H
#define ENUMSUB_H

#include "subsolve.h"
#include "enum.h"

class EnumBySubgame : public SubgameSolver  {
private:
  int npivots;
  EnumParams params;

  void SolveSubgame(const FullEfg &, const EFSupport &,
		    gList<BehavSolution> &, gStatus &);
  EfgAlgType AlgorithmID(void) const { return algorithmEfg_ENUMMIXED_NFG; }    

public:
  EnumBySubgame(const EnumParams &, int max = 0);
  virtual ~EnumBySubgame();

  int NumPivots(void) const   { return npivots; }
};

int Enum(const EFSupport &, const EnumParams &,
	 gList<BehavSolution> &, gStatus &, long &npivots, double &time);

#endif   // ENUMSUB_H

