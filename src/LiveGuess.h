////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2011, Abram Hindle, Prem Devanbu and UC Davis            //
// Copyright (c) 2008, Massachusetts Institute of Technology              //
// All rights reserved.                                                   //
//                                                                        //
// Redistribution and use in source and binary forms, with or without     //
// modification, are permitted provided that the following conditions are //
// met:                                                                   //
//                                                                        //
//     * Redistributions of source code must retain the above copyright   //
//       notice, this list of conditions and the following disclaimer.    //
//                                                                        //
//     * Redistributions in binary form must reproduce the above          //
//       copyright notice, this list of conditions and the following      //
//       disclaimer in the documentation and/or other materials provided  //
//       with the distribution.                                           //
//                                                                        //
//     * Neither the name of the Massachusetts Institute of Technology    //
//       nor the names of its contributors may be used to endorse or      //
//       promote products derived from this software without specific     //
//       prior written permission.                                        //
//                                                                        //
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    //
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      //
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  //
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT   //
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  //
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       //
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  //
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  //
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    //
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  //
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   //
////////////////////////////////////////////////////////////////////////////

#ifndef NGRAMMODEL_H
#define NGRAMMODEL_H

#include <vector>
#include "util/ZFile.h"
#include "Types.h"
#include "Vocab.h"
#include "NgramVector.h"

using std::vector;

/* Automatically in the heap */
class LiveGuessResult {
 protected:
  int _size;



 public:
  char * str;
  double probability;
  LiveGuessResult(double prob, char * cstr)
    : probability(prob), str(null), _size (0) {
    /* ugh hack is there a better way */
    _size = strlen(cstr);
    str = new char[ cstr ];
  }
  ~LiveGuessResult() {
    delete[] str;
  }
}

class LiveGuess {
 protected:
  NgramLMBase &       _lm;
  size_t              _order;
  vector<CountVector> _probCountVectors;
  vector<CountVector> _bowCountVectors;
  size_t              _numOOV;
  size_t              _numWords;
  size_t              _numZeroProbs;
  size_t              _numCalls;
  double              _totLogProb;
  SharedPtr<Mask>     _mask;
  
 public:
 LiveGuess(NgramLMBase &lm, size_t order=3)
   : _lm(lm), _order(order) { };
  
  std::auto_ptr< std::vector<LiveGuessResult> > predict
  
};