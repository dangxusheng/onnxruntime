// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "OnnxruntimeSessionBuilder.h"

namespace Windows::AI::MachineLearning {

class OnnxruntimeEngineFactory;

class OnnxruntimeDmlSessionBuilder : public Microsoft::WRL::RuntimeClass<
                                         Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::ClassicCom>,
                                         IOrtSessionBuilder> {
 public:
  HRESULT RuntimeClassInitialize(OnnxruntimeEngineFactory* engine_factory, ID3D12Device* device, ID3D12CommandQueue* queue);

  HRESULT STDMETHODCALLTYPE CreateSessionOptions(
      OrtSessionOptions** options) override;

  HRESULT STDMETHODCALLTYPE CreateSession(
      OrtSessionOptions* options,
      OrtSession** session) override;

  HRESULT STDMETHODCALLTYPE Initialize(
      OrtSession* session) override;

 private:
  Microsoft::WRL::ComPtr<OnnxruntimeEngineFactory> engine_factory_;
  winrt::com_ptr<ID3D12Device> device_;
  winrt::com_ptr<ID3D12CommandQueue> queue_;
};

}  // namespace Windows::AI::MachineLearning