//
//  gate component.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef gate_component_hpp
#define gate_component_hpp

#include <Simpleton/Data/json.hpp>

enum class GateFun {
  AND,
  OR,
  XOR,
  NOT,
  NAND,
  NOR,
  XNOR,
  IDENTITY
};

struct Gate {
  GateFun fun;
  
  static void init(Gate &comp, const json &node) {
    comp.fun = static_cast<GateFun>(node.at("fun").get<int>());
  }
};

#endif
