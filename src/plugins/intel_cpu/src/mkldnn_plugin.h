// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <cpp_interfaces/interface/ie_iplugin_internal.hpp>
#include "mkldnn_exec_network.h"

#include <string>
#include <map>
#include <unordered_map>
#include <memory>
#include <functional>
#include <vector>
#include <cfloat>

namespace MKLDNNPlugin {

class Engine : public InferenceEngine::IInferencePlugin {
public:
    Engine();
    ~Engine();

    std::shared_ptr<InferenceEngine::IExecutableNetworkInternal>
    LoadExeNetworkImpl(const InferenceEngine::CNNNetwork &network,
                       const std::map<std::string, std::string> &config) override;

    void AddExtension(const InferenceEngine::IExtensionPtr& extension) override;

    void SetConfig(const std::map<std::string, std::string> &config) override;

    InferenceEngine::Parameter GetConfig(const std::string& name, const std::map<std::string, InferenceEngine::Parameter>& options) const override;

    InferenceEngine::Parameter GetMetric(const std::string& name, const std::map<std::string, InferenceEngine::Parameter>& options) const override;

    InferenceEngine::QueryNetworkResult QueryNetwork(const InferenceEngine::CNNNetwork& network,
                                                     const std::map<std::string, std::string>& config) const override;

    InferenceEngine::IExecutableNetworkInternal::Ptr ImportNetwork(std::istream& networkModel,
                                                     const std::map<std::string, std::string>& config) override;

private:
    bool isLegacyAPI() const;

    InferenceEngine::Parameter GetMetricLegacy(const std::string& name, const std::map<std::string, InferenceEngine::Parameter>& options) const;

    InferenceEngine::Parameter GetConfigLegacy(const std::string& name, const std::map<std::string, InferenceEngine::Parameter>& options) const;

    Config engConfig;
    NumaNodesWeights weightsSharing;
    MKLDNNExtensionManager::Ptr extensionManager = std::make_shared<MKLDNNExtensionManager>();
    bool streamsSet = false;
    const std::string deviceFullName;
};

}  // namespace MKLDNNPlugin
