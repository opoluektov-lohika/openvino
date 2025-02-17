// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <ngraph/pass/graph_rewrite.hpp>

namespace MKLDNNPlugin {

class MoveEltwiseUpThroughDataMov : public ngraph::pass::MatcherPass {
public:
    NGRAPH_RTTI_DECLARATION;
    MoveEltwiseUpThroughDataMov();
};

}  // namespace MKLDNNPlugin
